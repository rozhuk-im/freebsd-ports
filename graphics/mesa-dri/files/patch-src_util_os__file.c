--- src/util/os_file.c
+++ src/util/os_file.c
@@ -194,33 +194,84 @@
    return buf;
 }
 
-#if (DETECT_OS_LINUX || DETECT_OS_FREEBSD) && ALLOW_KCMP
 
+#if (DETECT_OS_LINUX || DETECT_OS_FREEBSD)
+
 #include <sys/syscall.h>
 #include <unistd.h>
 
+
+#ifdef SYS_kcmp
+
 #if DETECT_OS_LINUX
 /* copied from <linux/kcmp.h> */
 #define KCMP_FILE 0
 #endif
 
-#endif
-
 int
 os_same_file_description(int fd1, int fd2)
 {
-#ifdef SYS_kcmp
    pid_t pid = getpid();
-#endif
 
    /* Same file descriptor trivially implies same file description */
    if (fd1 == fd2)
       return 0;
 
-#ifdef SYS_kcmp
    return syscall(SYS_kcmp, pid, pid, KCMP_FILE, fd1, fd2);
-#else
-   /* Otherwise we can't tell */
-   return -1;
+}
+
+#else /* SYS_kcmp */
+
+#include <sys/sysctl.h>
+#include <sys/file.h>
+#define kinfo_file xfile
+#define f_pid xf_pid
+#define f_fd xf_fd
+#define f_file xf_file
+#ifndef nitems /* SIZEOF() */
+#	define nitems(__val)	(sizeof(__val) / sizeof(__val[0]))
 #endif
+
+int
+os_same_file_description(int fd1, int fd2) {
+	const int mib[] = { CTL_KERN, KERN_FILE };
+	const pid_t pid = getpid();
+	size_t i, count, len = 0;
+	kvaddr_t fd1_kfile = 0, fd2_kfile = 0;
+	struct kinfo_file *kf;
+	/* Same file descriptor trivially implies same file description. */
+	if (fd1 == fd2)
+		return (0);
+
+	if (0 != sysctl(mib, nitems(mib), NULL, &len, NULL, 0))
+		return (-1);
+	len += (256 * sizeof(*kf)); /* Add extra space. */
+	kf = malloc(len);
+	if (NULL == kf)
+		return (-1);
+	if (0 != sysctl(mib, nitems(mib), kf, &len, NULL, 0))
+		return (-1);
+
+	count = (len / sizeof(*kf));
+	for (i = 0; i < count; i ++) {
+		if (pid != kf[i].f_pid)
+			continue;
+		if (fd1 == kf[i].f_fd) {
+			fd1_kfile = kf[i].f_file;
+			if (0 != fd2_kfile)
+				break;
+		}
+		if (fd2 == kf[i].f_fd) {
+			fd2_kfile = kf[i].f_file;
+			if (0 != fd1_kfile)
+				break;
+		}
+	}
+	free(kf);
+
+	if (0 == fd1_kfile || 0 == fd2_kfile)
+		return (-1);
+	return ((fd1_kfile < fd2_kfile) | ((fd1_kfile > fd2_kfile) << 1));
 }
+#endif /* SYS_kcmp */
+#endif /* (DETECT_OS_LINUX || DETECT_OS_FREEBSD) */
