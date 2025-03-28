--- include/rfb/rfb.h.orig	2024-12-22 09:54:53 UTC
+++ include/rfb/rfb.h
@@ -376,6 +376,12 @@ typedef struct _rfbScreenInfo
 #endif
     /* Timeout value for select() calls, mainly used for multithreaded servers. */
     int select_timeout_usec;
+    /* external sockets addon */
+    rfbBool external_sock;
+    char *external_data;
+    int response_is_set;
+    int initiator_display_finish;
+    char *vnc_actions; /* Hide HoundVncLibActions structure. */
 } rfbScreenInfo, *rfbScreenInfoPtr;
 
 
@@ -981,6 +987,7 @@ int rfbWidthOfString(rfbFontDataPtr font,const char* s
 int rfbDrawCharWithClip(rfbScreenInfoPtr rfbScreen,rfbFontDataPtr font,int x,int y,unsigned char c,int x1,int y1,int x2,int y2,rfbPixel colour,rfbPixel backColour);
 void rfbDrawStringWithClip(rfbScreenInfoPtr rfbScreen,rfbFontDataPtr font,int x,int y,const char* string,int x1,int y1,int x2,int y2,rfbPixel colour,rfbPixel backColour);
 int rfbWidthOfString(rfbFontDataPtr font,const char* string);
+int rfbHeightOfString(rfbFontDataPtr font,const char* string);
 int rfbWidthOfChar(rfbFontDataPtr font,unsigned char c);
 void rfbFontBBox(rfbFontDataPtr font,unsigned char c,int* x1,int* y1,int* x2,int* y2);
 /** this returns the smallest box enclosing any character of font. */
