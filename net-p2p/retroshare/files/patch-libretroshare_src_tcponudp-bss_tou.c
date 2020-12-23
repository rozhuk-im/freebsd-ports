--- libretroshare/src/tcponudp/bss_tou.c.orig	2019-09-04 17:37:42 UTC
+++ libretroshare/src/tcponudp/bss_tou.c
@@ -90,13 +90,18 @@ static int clear_tou_socket_error(int s)
 
 #include "tou.h"
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L 
 //static void BIO_set_shutdown(BIO *a,int s) { a->shutdown=s; }
 
 static int  BIO_get_shutdown(BIO *a) { return a->shutdown; }
 static int  BIO_get_init(BIO *a) { return a->init; }
 static void BIO_set_init(BIO *a,int i) { a->init=i; }
 static void BIO_set_data(BIO *a,void *p) { a->ptr = p; }
+#elif  defined(LIBRESSL_VERSION_NUMBER)
+int  BIO_get_shutdown(BIO *a) { return a->shutdown; }
+int  BIO_get_init(BIO *a) { return a->init; }
+void BIO_set_init(BIO *a,int i) { a->init=i; }
+void BIO_set_data(BIO *a,void *p) { a->ptr = p; }
 #else
 typedef struct bio_method_st {
     int type;
