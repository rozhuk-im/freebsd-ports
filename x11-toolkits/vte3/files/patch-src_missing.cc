--- src/missing.cc.orig	2020-09-15 17:46:41.000000000 +0300
+++ src/missing.cc	2020-09-25 19:02:27.887117000 +0300
@@ -40,6 +40,13 @@
 
 #ifndef HAVE_FDWALK
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <sys/file.h>
+#endif
+
 #ifdef __linux__
 
 struct linux_dirent64
@@ -128,6 +135,48 @@
         return RLIM_INFINITY;
 }
 
+#ifdef __FreeBSD__
+static int
+fdwalk2(int (*func)(void *, int), void *udata, int *ret) {
+	size_t i, bufsz = 0;
+	struct xfile *xfbuf, *xf;
+	int uret = 0, pid_found = 0;
+	int mib[2] = { CTL_KERN, KERN_FILE };
+	pid_t pid;
+
+	if (NULL == func)
+		return EINVAL;
+
+	if (sysctl(mib, nitems(mib), NULL, &bufsz, NULL, 0) == -1)
+		return (errno);
+	bufsz += 65536;
+	xfbuf = (struct xfile*)alloca(bufsz);
+	if (xfbuf == NULL)
+		return errno;
+	if (sysctl(mib, nitems(mib), xfbuf, &bufsz, NULL, 0) == -1)
+		return errno;
+	bufsz /= sizeof(struct xfile);
+
+	pid = getpid();
+	for (i = 0; i < bufsz; i++) {
+		xf = &xfbuf[i];
+		if (pid != xf->xf_pid) {
+			if (pid_found)
+				return 0;
+			continue;
+		}
+		pid_found = 1;
+		if (0 > xf->xf_fd)
+			continue;
+		uret = func(udata, xf->xf_fd);
+		if (uret != 0)
+			break;
+	}
+
+	return 0;
+}
+#endif
+
 /* This function is called between fork and execve/_exit and so must be
  * async-signal-safe; see man:signal-safety(7).
  */
@@ -141,6 +190,12 @@
    */
   int fd;
   int res = 0;
+
+#ifdef __FreeBSD__
+  if (fdwalk2(cb, data, &res) == 0)
+      return res;
+  /* If any sysctl/malloc call fails continue with the fall back method */
+#endif
 
 #ifdef __linux__
   /* Avoid use of opendir/closedir since these are not async-signal-safe. */
