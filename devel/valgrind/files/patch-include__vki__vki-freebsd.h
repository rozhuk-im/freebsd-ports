--- include/vki/vki-freebsd.h.orig	2016-01-13 22:20:20.000000000 +0300
+++ include/vki/vki-freebsd.h	2019-03-17 13:06:51.978881000 +0300
@@ -367,7 +367,45 @@
 	unsigned int :(8 / 2) * (16 - (int)sizeof(struct vki_timespec));
 };
 
+/* FreeBSD 11.x stat */
+/* struct vki_stat_freebsd11 { TODO } */
 
+/* FreeBSD 12.x stat */
+struct vki_stat64 {
+	vki_dev_t	st_dev;
+	vki_ino_t	st_ino;
+	vki_nlink_t	st_nlink;
+	vki_mode_t	st_mode;
+	vki_int16_t	st_padding0;
+	vki_uid_t	st_uid;
+	vki_gid_t	st_gid;
+	vki_int32_t	st_padding1;
+	vki_dev_t	st_rdev;
+#if defined(VGA_x86)
+	vki_int32_t	st_atim_ext;
+#endif
+	struct vki_timespec st_atim;
+#if defined(VGA_x86)
+	vki_int32_t	st_mtim_ext;
+#endif
+	struct vki_timespec st_mtim;
+#if defined(VGA_x86)
+	vki_int32_t	st_ctim_ext;
+#endif
+	struct vki_timespec st_ctim;
+#if defined(VGA_x86)
+	vki_int32_t	st_btim_ext;
+#endif
+	struct vki_timespec st_birthtim;
+
+	vki_off_t	st_size;
+	vki_blkcnt_t	st_blocks;
+	vki_blksize_t	st_blksize;
+	vki_fflags_t	st_flags;
+	vki_uint64_t	st_gen;
+	vki_uint64_t	st_spare[10];
+};
+
 //----------------------------------------------------------------------
 // From linux-2.6.8.1/include/linux/sched.h
 //----------------------------------------------------------------------
@@ -684,6 +722,7 @@
 
 #define VKI_SOCK_STREAM	1
 
+#include <sys/types.h>
 #include <netinet/tcp.h>
 
 #define VKI_TCP_NODELAY  TCP_NODELAY
@@ -888,7 +927,8 @@
 #define VKI_OMFSNAMELEN	16
 #define VKI_OMNAMELEN	(88 - 2 * sizeof(long))
 #define VKI_MFSNAMELEN	16
-#define VKI_MNAMELEN	88
+#define VKI_MNAMELEN11	88
+#define VKI_MNAMELEN	1024
 
 struct vki_statfs4 {
 	long		f_spare2;
@@ -915,6 +955,31 @@
 	long		f_spare[2];
 };
 
+struct vki_statfs11 {
+	vki_uint32_t	f_version;
+	vki_uint32_t	f_type;
+	vki_uint64_t	f_flags;
+	vki_uint64_t	f_bsize;
+	vki_uint64_t	f_iosize;
+	vki_uint64_t	f_blocks;
+	vki_uint64_t	f_bfree;
+	vki_int64_t	f_bavail;
+	vki_uint64_t	f_files;
+	vki_int64_t	f_ffree;
+	vki_uint64_t	f_syncwrites;
+	vki_uint64_t	f_asyncwrites;
+	vki_uint64_t	f_syncreads;
+	vki_uint64_t	f_asyncreads;
+	vki_uint64_t	f_spare[10];
+	vki_uint32_t	f_namemax;
+	vki_uid_t	f_owner;
+	vki_fsid_t	f_fsid;
+	char		f_charspare[80];
+	char		f_fstypename[VKI_MFSNAMELEN];
+	char		f_mntfromnname[VKI_MNAMELEN11];
+	char		f_mntonname[VKI_MNAMELEN11];
+};
+
 struct vki_statfs {
 	vki_uint32_t	f_version;
 	vki_uint32_t	f_type;
@@ -1157,7 +1222,9 @@
 //----------------------------------------------------------------------
 // From sys/kevent.h
 //----------------------------------------------------------------------
-struct vki_kevent {
+
+/* FreeBSD 11.x kevent */
+struct vki_kevent11 {
 	vki_uintptr_t  ident;
 	vki_int16_t    filter;
 	vki_uint16_t   flags;
@@ -1166,6 +1233,15 @@
 	void           *udata;
 };
 
+struct vki_kevent {
+	vki_uintptr_t  ident;
+	vki_int16_t    filter;
+	vki_uint16_t   flags;
+	vki_uint32_t   fflags;
+	vki_int64_t    data;
+	void           *udata;
+	vki_uint64_t   ext[4];
+};
 
 // QQQ sort
 
@@ -1888,11 +1964,23 @@
 #define VKI_I386_SET_FSBASE     8
 #define VKI_I386_GET_GSBASE     9
 #define VKI_I386_SET_GSBASE     10
+#define VKI_I386_SET_XFPUSTATE  11
 
 #define VKI_AMD64_GET_FSBASE    128
 #define VKI_AMD64_SET_FSBASE    129
 #define VKI_AMD64_GET_GSBASE    130
 #define VKI_AMD64_SET_GSBASE    131
+#define VKI_AMD64_GET_XFPUSTATE 132
+
+struct vki_i386_get_xfpustate {
+	unsigned int addr;
+	int len;
+};
+
+struct vki_amd64_get_xfpustate {
+	void *addr;
+	int len;
+};
 
 //----------------------------------------------------------------------
 // From sys/module.h
