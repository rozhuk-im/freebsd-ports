--- src/VBox/RDP/client-1.8.4/tcp.c.orig	2019-01-25 21:31:48.000000000 +0300
+++ src/VBox/RDP/client-1.8.4/tcp.c	2019-02-11 12:39:02.556043000 +0300
@@ -311,8 +311,10 @@
 
 	if (!g_ssl_initialized)
 	{
+#ifndef LIBRESSL_VERSION_NUMBER
 		SSL_load_error_strings();
 		SSL_library_init();
+#endif
 		g_ssl_initialized = True;
 	}
 
