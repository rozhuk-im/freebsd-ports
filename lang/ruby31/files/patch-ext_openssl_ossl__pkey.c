--- ext/openssl/ossl_pkey.c
+++ ext/openssl/ossl_pkey.c
@@ -710,7 +710,7 @@
 	}
     }
     else {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OSSL_OPENSSL_PREREQ(1, 1, 0) || OSSL_LIBRESSL_PREREQ(3, 5, 0)
 	if (!PEM_write_bio_PrivateKey_traditional(bio, pkey, enc, NULL, 0,
 						  ossl_pem_passwd_cb,
 						  (void *)pass)) {
