--- dlls/ntdll/unix/virtual.c	2021-12-22 04:19:04.331401000 +0300
+++ dlls/ntdll/unix/virtual.c	2021-12-22 03:43:41.570061000 +0300
@@ -3918,6 +3918,7 @@
 
     size = max( reserve_size, commit_size );
     if (size < 1024 * 1024) size = 1024 * 1024;  /* Xlib needs a large stack */
+    size += (4 * 1024 * 1024);  /* Xlib needs a extra large stack. */
     size = ROUND_SIZE( 0, size, granularity_mask );
 
     server_enter_uninterrupted_section( &virtual_mutex, &sigset );
