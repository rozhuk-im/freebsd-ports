--- src/libvncserver/font.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncserver/font.c
@@ -123,6 +123,30 @@ int rfbWidthOfString(rfbFontDataPtr font,const char* s
   return(i);
 }
 
+int rfbHeightOfString(rfbFontDataPtr font,const char* string)
+{
+  int i=0;
+#if 0 /* For experimental and testing 1 */
+  *y1+=-font->metaData[c*5+4]-font->metaData[c*5+2]+1;
+  *x2=*x1+font->metaData[c*5+1]+1;
+  *y2=*y1+font->metaData[c*5+2]+1;
+#endif
+  i = -font->metaData[*string*5+4]-font->metaData[*string*5+2];
+#if 0  /* For experimental and testing 2 */
+  //i+= font->metaData[*string*5+2];
+  //i+=font->metaData[*string*5+2];
+  /*
+  while(*string) {
+    if ((*string) == '\n') {
+      i+=font->metaData[*string*5+2];
+    }
+    string++;
+  }
+  */
+#endif
+  return(i);
+}
+
 int rfbWidthOfChar(rfbFontDataPtr font,unsigned char c)
 {
   return(font->metaData[c*5+1]+font->metaData[c*5+3]);
