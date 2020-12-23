--- include/vki/vki-scnums-freebsd.h.orig	2016-01-13 22:20:20.000000000 +0300
+++ include/vki/vki-scnums-freebsd.h	2019-03-17 13:06:51.980012000 +0300
@@ -138,7 +138,7 @@
 #define	__NR_setsid		147
 #define	__NR_quotactl		148
 #define	__NR_nfssvc		155
-#define	__NR_statfs		157
+#define	__NR_statfs11		157
 #define	__NR_fstatfs		158
 #define	__NR_lgetfh		160
 #define	__NR_getfh		161
@@ -275,7 +275,7 @@
 #define	__NR_getresuid		360
 #define	__NR_getresgid		361
 #define	__NR_kqueue		362
-#define	__NR_kevent		363
+#define	__NR_kevent11		363
 #define	__NR_extattr_set_fd	371
 #define	__NR_extattr_get_fd	372
 #define	__NR_extattr_delete_fd	373
@@ -299,7 +299,7 @@
 #define	__NR_uuidgen		392
 #define	__NR_sendfile		393
 #define	__NR_mac_syscall	394
-#define	__NR_getfsstat		395
+#define	__NR_getfsstat11	395
 #define	__NR_statfs6		396
 #define	__NR_fstatfs6		397
 #define	__NR_fhstatfs6		398
@@ -408,6 +408,14 @@
 #define	__NR___semctl		510
 #define	__NR_shmctl		512
 #define	__NR_pipe2		542
+#define	__NR_fstat64		551
+#define	__NR_fstatat64		552
+#define	__NR_getdirentries64	554
+#define	__NR_statfs		555
+#define	__NR_fstatfs64		556
+#define	__NR_getfsstat		557
+#define	__NR_kevent		560
+#define	__NR_getrandom		563
 
 #define __NR_fake_sigreturn	1000
 
