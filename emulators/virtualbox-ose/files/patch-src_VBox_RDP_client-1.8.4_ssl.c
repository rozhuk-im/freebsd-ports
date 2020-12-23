--- src/VBox/RDP/client-1.8.4/ssl.c.orig	2019-01-25 21:31:48.000000000 +0300
+++ src/VBox/RDP/client-1.8.4/ssl.c	2019-02-11 12:38:31.251992000 +0300
@@ -97,7 +97,7 @@
 rdssl_rsa_encrypt(uint8 * out, uint8 * in, int len, uint32 modulus_size, uint8 * modulus,
 		  uint8 * exponent)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
 	BN_CTX *ctx;
 	BIGNUM *mod, *exp, *x, *y;
 	uint8 inr[SEC_MAX_MODULUS_SIZE];
@@ -128,7 +128,7 @@
 	BN_free(exp);
 	BN_free(mod);
 	BN_CTX_free(ctx);
-#else /* OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER) */
+#else
 	BN_CTX *ctx;
 	BIGNUM mod, exp, x, y;
 	uint8 inr[SEC_MAX_MODULUS_SIZE];
@@ -316,12 +316,12 @@
 rdssl_hmac_md5(const void *key, int key_len, const unsigned char *msg, int msg_len,
 	       unsigned char *md)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || !defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX ctx;
 	HMAC_CTX_init(&ctx);
 #endif
 	HMAC(EVP_md5(), key, key_len, msg, msg_len, md, NULL);
-#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || !defined(LIBRESSL_VERSION_NUMBER)
 	HMAC_CTX_cleanup(&ctx);
 #endif
 }
