--- src/sdr.c.orig	2020-02-17 11:52:23 UTC
+++ src/sdr.c
@@ -48,6 +48,7 @@
 #else
   #include <netdb.h>
   #include <netinet/in.h>
+  #include <sys/socket.h>
 
   #define SOCKET          int
   #define INVALID_SOCKET  -1
