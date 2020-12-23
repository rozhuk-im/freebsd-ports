--- src/data.c.orig	2020-02-17 11:52:23 UTC
+++ src/data.c
@@ -45,6 +45,7 @@
 #else
   #include <netdb.h>
   #include <netinet/in.h>
+  #include <sys/socket.h>
 
   #define SOCKET          int
   #define INVALID_SOCKET  -1
