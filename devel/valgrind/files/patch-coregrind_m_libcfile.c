--- coregrind/m_libcfile.c.orig	2016-01-13 22:20:20.000000000 +0300
+++ coregrind/m_libcfile.c	2019-03-17 13:06:51.974161000 +0300
@@ -255,11 +255,7 @@ Int VG_(pipe) ( Int fd[2] )
    SysRes res = VG_(do_syscall1)(__NR_pipe, (UWord)fd);
    return sr_isError(res) ? -1 : 0;
 #  elif defined(VGO_freebsd)
-   SysRes res = VG_(do_syscall0)(__NR_pipe);
-   if (!sr_isError(res)) {
-      fd[0] = sr_Res(res);
-      fd[1] = sr_ResHI(res);
-   }
+   SysRes res = VG_(do_syscall2)(__NR_pipe2, (UWord)fd, 0);
    return sr_isError(res) ? -1 : 0;
 #  elif defined(VGO_darwin)
    /* __NR_pipe is UX64, so produces a double-word result */
@@ -369,7 +365,7 @@ Int VG_(fstat) ( Int fd, struct vg_stat* vgbuf )
 #  if defined(VGO_linux)  ||  defined(VGO_darwin)  ||  defined(VGO_freebsd)
    /* First try with fstat64.  If that doesn't work out, fall back to
       the vanilla version. */
-#  if defined(__NR_fstat64)
+#  if defined(__NR_fstat64) && !defined(VGO_freebsd)
    { struct vki_stat64 buf64;
      res = VG_(do_syscall2)(__NR_fstat64, (UWord)fd, (UWord)&buf64);
      if (!(sr_isError(res) && sr_Err(res) == VKI_ENOSYS)) {
