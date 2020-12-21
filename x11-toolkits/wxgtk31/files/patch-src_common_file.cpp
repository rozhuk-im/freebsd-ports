--- src/common/file.cpp.orig	2018-12-09 18:40:08.000000000 +0300
+++ src/common/file.cpp	2019-10-02 00:45:23.576996000 +0300
@@ -261,7 +261,7 @@
 {
     wxCHECK_MSG( str, false, wxS("Output string must be non-NULL") );
 
-    static const ssize_t READSIZE = 4096;
+    static const ssize_t READSIZE = 65536;
 
     wxCharBuffer buf;
 
@@ -276,7 +276,7 @@
         char* p = buf.data();
         for ( ;; )
         {
-            ssize_t nread = Read(p, length > READSIZE ? READSIZE : length);
+            ssize_t nread = Read(p, length);
             if ( nread == wxInvalidOffset )
                 return false;
 
