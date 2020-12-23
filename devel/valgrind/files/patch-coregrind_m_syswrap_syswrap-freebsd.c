--- coregrind/m_syswrap/syswrap-freebsd.c.orig	2016-01-13 22:20:20.000000000 +0300
+++ coregrind/m_syswrap/syswrap-freebsd.c	2019-03-17 13:06:51.977414000 +0300
@@ -868,6 +868,18 @@
    POST_MEM_WRITE( ARG2, sizeof(struct vki_stat) );
 }
 
+PRE(sys_fstat64)
+{
+   PRINT("sys_fstat64 ( %ld, %#lx )", ARG1, ARG2);
+   PRE_REG_READ2(long, "fstat", unsigned long, fd, struct stat *, buf);
+   PRE_MEM_WRITE( "fstat(buf)", ARG2, sizeof(struct vki_stat64) );
+}
+
+POST(sys_fstat64)
+{
+   POST_MEM_WRITE( ARG2, sizeof(struct vki_stat64) );
+}
+
 PRE(sys_pathconf)
 {
    PRINT("sys_pathconf ( %#lx(%s), %ld )",ARG1,(char *)ARG1,ARG2);
@@ -1012,6 +1024,26 @@
    }
 }
 
+PRE(sys_getdirentries64)
+{
+   *flags |= SfMayBlock;
+   PRINT("sys_getdents ( %ld, %#lx, %ld )", ARG1,ARG2,ARG3);
+   PRE_REG_READ3(vki_ssize_t, "getdirentries",
+                 unsigned int, fd, struct dirent *, dirp,
+                 vki_size_t, count);
+   PRE_MEM_WRITE( "getdirentries(dirp)", ARG2, ARG3 );
+}
+
+POST(sys_getdirentries64)
+{
+   vg_assert(SUCCESS);
+   if (RES > 0) {
+      POST_MEM_WRITE( ARG2, RES );
+      if ( ARG4 != 0 )
+	 POST_MEM_WRITE( ARG4, sizeof (vki_off_t));
+   }
+}
+
 PRE(sys_seteuid)
 {
    PRINT("sys_seteuid ( %ld )", ARG1);
@@ -1070,6 +1102,44 @@
    }
 }
 
+PRE(sys_kevent11)
+{
+   /* struct freebsd11_kevent {
+        uintptr_t ident;  -- identifier for this event
+	short     filter; -- filter for event
+	u_short   flags;  -- action flags for kqueue
+	u_int     fflags; -- filter flag value
+	intptr_t  data;   -- filter data value
+	void      *udata; -- opaque user data identifier
+      };
+      int kevent(int kq, const struct kevent *changelist, int nchanges,
+                 struct kevent *eventlist, int nevents,
+                 const struct timespec *timeout);
+   */
+   *flags |= SfMayBlock;
+   PRINT("sys_kevent11 ( %ld, %#lx, %ld, %#lx, %ld, %#lx )\n", ARG1,ARG2,ARG3,ARG4,ARG5,ARG6);
+   PRE_REG_READ6(long, "kevent11",
+                 int, fd, struct vki_kevent11 *, newev, int, num_newev,
+		 struct vki_kevent11 *, ret_ev, int, num_retev,
+		 struct timespec *, timeout);
+   if (ARG2 != 0 && ARG3 != 0)
+      PRE_MEM_READ( "kevent(changeevent)", ARG2, sizeof(struct vki_kevent11)*ARG3 );
+   if (ARG4 != 0 && ARG5 != 0)
+      PRE_MEM_WRITE( "kevent(events)", ARG4, sizeof(struct vki_kevent11)*ARG5);
+   if (ARG6 != 0)
+      PRE_MEM_READ( "kevent(timeout)",
+                    ARG6, sizeof(struct vki_timespec));
+}
+
+POST(sys_kevent11)
+{
+   vg_assert(SUCCESS);
+   if (RES > 0) {
+      if (ARG4 != 0)
+         POST_MEM_WRITE( ARG4, sizeof(struct vki_kevent11)*RES) ;
+   }
+}
+
 PRE(sys_kevent)
 {
    /* struct kevent {
@@ -1077,8 +1147,9 @@
 	short     filter; -- filter for event
 	u_short   flags;  -- action flags for kqueue
 	u_int     fflags; -- filter flag value
-	intptr_t  data;   -- filter data value
+	int64_t   data;   -- filter data value
 	void      *udata; -- opaque user data identifier
+	uint64_t  ext[4]; -- extensions
       };
       int kevent(int kq, const struct kevent *changelist, int nchanges,
                  struct kevent *eventlist, int nevents,
@@ -1108,6 +1179,7 @@
    }
 }
 
+
 PRE(sys___getcwd)
 {
    PRINT("sys___getcwd ( %#lx, %lu )", ARG1,ARG2);
@@ -1143,6 +1215,20 @@
    }
 }
 
+PRE(sys_getfsstat11)
+{
+   PRINT("sys_getfsstat11 ( %#lx, %ld, %ld )",ARG1,ARG2,ARG3);
+   PRE_REG_READ3(long, "getfsstat11", struct vki_statfs11 *, buf, long, len, int, flags);
+   PRE_MEM_WRITE( "getfsstat11(buf)", ARG1, ARG2 );
+}
+POST(sys_getfsstat11)
+{
+   vg_assert(SUCCESS);
+   if (RES > 0) {
+      POST_MEM_WRITE( ARG1, RES * sizeof(struct vki_statfs11) );
+   }
+}
+
 PRE(sys_getfsstat)
 {
    PRINT("sys_getfsstat ( %#lx, %ld, %ld )",ARG1,ARG2,ARG3);
@@ -1234,6 +1320,19 @@
    POST_MEM_WRITE( ARG2, sizeof(struct vki_statfs6) );
 }
 
+PRE(sys_fstatfs64)
+{
+   PRINT("sys_fstatfs64 ( %ld, %#lx )", ARG1, ARG2);
+   PRE_REG_READ2(long, "fstatfs6",
+                 unsigned int, fd, struct statfs *, buf);
+   PRE_MEM_WRITE( "fstatfs6(buf)", ARG2, sizeof(struct vki_statfs6) );
+}
+
+POST(sys_fstatfs64)
+{
+   POST_MEM_WRITE( ARG2, sizeof(struct vki_statfs6) );
+}
+
 PRE(sys_statfs6)
 {
    PRINT("sys_statfs6 ( %#lx(%s), %#lx )",ARG1,(char *)ARG1,ARG2);
@@ -1246,7 +1345,19 @@
    POST_MEM_WRITE( ARG2, sizeof(struct vki_statfs6) );
 }
 
+PRE(sys_statfs11)
+{
+   PRINT("sys_statfs11 ( %#lx(%s), %#lx )",ARG1,(char *)ARG1,ARG2);
+   PRE_REG_READ2(long, "statfs11", const char *, path, struct statfs *, buf);
+   PRE_MEM_RASCIIZ( "statfs11(path)", ARG1 );
+   PRE_MEM_WRITE( "statfs11(buf)", ARG2, sizeof(struct vki_statfs11) );
+}
+POST(sys_statfs11)
+{
+   POST_MEM_WRITE( ARG2, sizeof(struct vki_statfs11) );
+}
 
+
 #if 0
 /* ---------------------------------------------------------------------
    aio_* wrappers
@@ -1774,6 +1885,20 @@
    miscellaneous wrappers
    ------------------------------------------------------------------ */
 
+PRE(sys_minherit)
+{
+   PRINT("minherit ( %#lx, %lu, %ld )" , ARG1, ARG2, ARG3);
+   PRE_REG_READ3(long, "minherit", 
+                 void *, addr, vki_size_t, len, int, inherit);
+   if (ARG2 != 0)
+      PRE_MEM_WRITE( "minherit(addr)", ARG1,ARG2 );
+}
+POST(sys_minherit)
+{
+   if (ARG2 != 0)
+      POST_MEM_WRITE( ARG1, ARG2 );
+}
+
 PRE(sys_munlockall)
 {
    *flags |= SfMayBlock;
@@ -2474,6 +2599,24 @@
       POST_MEM_WRITE( ARG2, sizeof(vki_siginfo_t) );
 }
 
+PRE(sys_sigwait)
+{
+   *flags |= SfMayBlock;
+   PRINT("sys_sigwait ( %#lx, %#lx )",
+         ARG1,ARG2);
+   PRE_REG_READ2(long, "sigwait", 
+                 const vki_sigset_t *, set, int *, sig);
+   if (ARG1 != 0) 
+      PRE_MEM_READ(  "sigwait(set)",  ARG1, sizeof(vki_sigset_t));
+   if (ARG2 != 0)
+      PRE_MEM_WRITE( "sigwait(sig)", ARG2, sizeof(int*));
+}
+POST(sys_sigwait)
+{
+   if (ARG2 != 0)
+      POST_MEM_WRITE( ARG2, sizeof(int*));
+}
+
 #if 0	/* not on freebsd 4.x */
 PRE(sys_rt_sigqueueinfo)
 {
@@ -3069,6 +3212,20 @@
    POST_MEM_WRITE( ARG3, sizeof(struct vki_stat) );
 }
 
+PRE(sys_fstatat64)
+{
+   PRINT("sys_fstatat ( %ld, %#lx(%s), %#lx )", ARG1,ARG2,(char*)ARG2,ARG3);
+   PRE_REG_READ3(long, "fstatat",
+                 int, dfd, char *, file_name, struct stat *, buf);
+   PRE_MEM_RASCIIZ( "fstatat(file_name)", ARG2 );
+   PRE_MEM_WRITE( "fstatat(buf)", ARG3, sizeof(struct vki_stat) );
+}
+
+POST(sys_fstatat64)
+{
+   POST_MEM_WRITE( ARG3, sizeof(struct vki_stat) );
+}
+
 PRE(sys_unlinkat)
 {
    *flags |= SfMayBlock;
@@ -3374,7 +3531,7 @@
                  unsigned int, fd, unsigned int, request, unsigned long, arg);
 
 /* On FreeBSD, ALL ioctl's are IOR/IOW encoded.  Just use the default decoder */
-   if (VG_(strstr)(VG_(clo_sim_hints), "lax-ioctls") != NULL) {
+   if (SimHintiS(SimHint_lax_ioctls, VG_(clo_sim_hints))) {
       /* 
       * Be very lax about ioctl handling; the only
       * assumption is that the size is correct. Doesn't
@@ -3655,7 +3812,7 @@
 PRE(sys_cpuset_getaffinity)
 {
 
-    PRINT("sys_cpuset_getaffinity ( %ld, %ld, %lld, %llu, %#lx )", ARG1, ARG2,
+    PRINT("sys_cpuset_getaffinity ( %ld, %ld, %ld, %lu, %#lx )", ARG1, ARG2,
         ARG3, ARG4, ARG5);
     PRE_REG_READ5(int, "cpuset_getaffinity",
         int, level, int, which, long, id,
@@ -3670,6 +3827,19 @@
         POST_MEM_WRITE( ARG5, ARG4 );
 }
 
+PRE(sys_getrandom)
+{
+   PRINT("sys_getrandom ( %#lx, %ld, %ld )" , ARG1,ARG2,ARG3);
+   PRE_REG_READ3(ssize_t, "getrandom",
+                 void *, buf, size_t, buflen, unsigned int, flags);
+   PRE_MEM_WRITE( "getrandom(cpu)", ARG1, ARG2 );
+}
+
+POST(sys_getrandom)
+{
+   POST_MEM_WRITE( ARG1, ARG2 );
+}
+
 #undef PRE
 #undef POST
 
@@ -3870,7 +4040,7 @@
    // BSDXY(__NR_nfssvc,		sys_nfssvc),			// 155
 
    // 4.3 getdirentries							   156
-   GENXY(__NR_statfs,			sys_statfs),			// 157
+   BSDXY(__NR_statfs11,			sys_statfs11),			// 157
    GENXY(__NR_fstatfs,			sys_fstatfs),			// 158
    // nosys								   159
 
@@ -3986,7 +4156,7 @@
 
 // BSDXY(__NR_ntp_gettime,		sys_ntp_gettime),		// 248
    // nosys								   249
-// BSDXY(__NR_minherit,			sys_minherit),			// 250
+   BSDXY(__NR_minherit,			sys_minherit),			// 250
    BSDX_(__NR_rfork,			sys_rfork),			// 251
 
    GENXY(__NR_openbsd_poll,		sys_poll),			// 252
@@ -4127,7 +4297,7 @@
    BSDXY(__NR_getresuid,		sys_getresuid),			// 360
    BSDXY(__NR_getresgid,		sys_getresgid),			// 361
    BSDX_(__NR_kqueue,			sys_kqueue),			// 362
-   BSDXY(__NR_kevent,			sys_kevent),			// 363
+   BSDXY(__NR_kevent11,			sys_kevent11),			// 363
 
    // nosys								   364
    // nosys								   365
@@ -4167,7 +4337,7 @@
    BSDXY(__NR_uuidgen,			sys_uuidgen),			// 392
    BSDXY(__NR_sendfile,			sys_sendfile),			// 393
    // mac_syscall							   394
-   BSDXY(__NR_getfsstat,		sys_getfsstat),			// 395
+   BSDXY(__NR_getfsstat11,		sys_getfsstat11),		// 395
 
    BSDXY(__NR_statfs6,			sys_statfs6),			// 396
    BSDXY(__NR_fstatfs6,			sys_fstatfs6),			// 397
@@ -4210,7 +4380,7 @@
    BSDX_(__NR___acl_delete_link,	sys___acl_delete_link),		// 427
 
    BSDX_(__NR___acl_aclcheck_link,	sys___acl_aclcheck_link),	// 428
-   //!sigwait								   429
+   BSDXY(__NR_sigwait,			sys_sigwait),			// 429
    // thr_create							   430
    BSDX_(__NR_thr_exit,			sys_thr_exit),			// 431
 
@@ -4309,6 +4479,17 @@
    BSDXY(__NR_shmctl,			sys_shmctl),			// 512
 
    BSDXY(__NR_pipe2,			sys_pipe2),			// 542
+
+   // ino64
+   BSDXY(__NR_fstat64,			sys_fstat64),			// 551
+   BSDXY(__NR_fstatat64,		sys_fstatat64),			// 552
+   BSDXY(__NR_getdirentries64,		sys_getdirentries64),		// 554
+   GENXY(__NR_statfs,			sys_statfs),			// 555
+   GENXY(__NR_fstatfs64,		sys_fstatfs),			// 556
+   BSDXY(__NR_getfsstat,		sys_getfsstat),			// 557
+
+   BSDXY(__NR_kevent,			sys_kevent),			// 560
+   BSDXY(__NR_getrandom,		sys_getrandom),			// 563
 
    BSDX_(__NR_fake_sigreturn,		sys_fake_sigreturn),		// 1000, fake sigreturn
 
