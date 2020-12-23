--- coregrind/m_syswrap/priv_syswrap-freebsd.h.orig	2016-01-13 22:20:20.000000000 +0300
+++ coregrind/m_syswrap/priv_syswrap-freebsd.h	2019-03-17 13:06:51.975479000 +0300
@@ -46,6 +46,7 @@
 DECL_TEMPLATE(freebsd, sys_syscall);
 DECL_TEMPLATE(freebsd, sys_exit);
 DECL_TEMPLATE(freebsd, sys_getfsstat4);
+DECL_TEMPLATE(freebsd, sys_getfsstat11);
 DECL_TEMPLATE(freebsd, sys_getfsstat);
 DECL_TEMPLATE(freebsd, sys_mount);
 DECL_TEMPLATE(freebsd, sys_unmount);
@@ -54,6 +55,7 @@
 DECL_TEMPLATE(freebsd, sys_sendmsg);
 DECL_TEMPLATE(freebsd, sys_recvfrom);
 DECL_TEMPLATE(freebsd, sys_accept);
+DECL_TEMPLATE(freebsd, sys_accept4);
 DECL_TEMPLATE(freebsd, sys_getpeername);
 DECL_TEMPLATE(freebsd, sys_getsockname);
 DECL_TEMPLATE(freebsd, sys_chflags);
@@ -97,10 +99,13 @@
 DECL_TEMPLATE(freebsd, sys_seteuid);
 DECL_TEMPLATE(freebsd, sys_stat);
 DECL_TEMPLATE(freebsd, sys_fstat);
+DECL_TEMPLATE(freebsd, sys_fstat64);
 DECL_TEMPLATE(freebsd, sys_lstat);
 DECL_TEMPLATE(freebsd, sys_pathconf);
 DECL_TEMPLATE(freebsd, sys_fpathconf);
 DECL_TEMPLATE(freebsd, sys_getdirentries);
+DECL_TEMPLATE(freebsd, sys_getdirentries64);
+DECL_TEMPLATE(freebsd, sys_getrandom);
 DECL_TEMPLATE(freebsd, sys_mmap);
 DECL_TEMPLATE(freebsd, sys___syscall);
 DECL_TEMPLATE(freebsd, sys_lseek);
@@ -173,6 +178,10 @@
 DECL_TEMPLATE(freebsd, sys_utrace);
 DECL_TEMPLATE(freebsd, sys_kldsym);
 DECL_TEMPLATE(freebsd, sys_jail);
+DECL_TEMPLATE(freebsd, sys_jail_get);
+DECL_TEMPLATE(freebsd, sys_jail_set);
+DECL_TEMPLATE(freebsd, sys_jail_attach);
+DECL_TEMPLATE(freebsd, sys_jail_remove);
 DECL_TEMPLATE(freebsd, sys_sigprocmask);
 DECL_TEMPLATE(freebsd, sys_sigsuspend);
 DECL_TEMPLATE(freebsd, sys_sigaction);
@@ -181,6 +190,7 @@
 DECL_TEMPLATE(freebsd, sys_fake_sigreturn);
 DECL_TEMPLATE(freebsd, sys_sigtimedwait);
 DECL_TEMPLATE(freebsd, sys_sigwaitinfo);
+DECL_TEMPLATE(freebsd, sys_sigwait);
 DECL_TEMPLATE(freebsd, sys_getcontext);
 DECL_TEMPLATE(freebsd, sys_setcontext);
 DECL_TEMPLATE(freebsd, sys_swapcontext);
@@ -207,7 +217,9 @@
 DECL_TEMPLATE(freebsd, sys_kevent);
 DECL_TEMPLATE(freebsd, sys_sendfile);
 DECL_TEMPLATE(freebsd, sys_statfs6);
+DECL_TEMPLATE(freebsd, sys_statfs11);
 DECL_TEMPLATE(freebsd, sys_fstatfs6);
+DECL_TEMPLATE(freebsd, sys_fstatfs64);
 DECL_TEMPLATE(freebsd, sys_fhstatfs6);
 DECL_TEMPLATE(freebsd, sys_thr_exit);
 DECL_TEMPLATE(freebsd, sys_thr_self);
@@ -251,6 +262,7 @@
 DECL_TEMPLATE(freebsd, sys_fchownat);
 DECL_TEMPLATE(freebsd, sys_fexecve);
 DECL_TEMPLATE(freebsd, sys_fstatat);
+DECL_TEMPLATE(freebsd, sys_fstatat64);
 DECL_TEMPLATE(freebsd, sys_futimesat);
 DECL_TEMPLATE(freebsd, sys_linkat);
 DECL_TEMPLATE(freebsd, sys_mkdirat);
