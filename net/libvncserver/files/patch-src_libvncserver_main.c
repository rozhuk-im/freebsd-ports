--- src/libvncserver/main.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncserver/main.c
@@ -1002,6 +1002,9 @@ rfbScreenInfoPtr rfbGetScreen(int* argc,char** argv,
 
    screen->permitFileTransfer = FALSE;
 
+   screen->external_sock = FALSE;
+   screen->external_data = NULL;
+
    if(!rfbProcessArguments(screen,argc,argv)) {
      free(screen);
      return NULL;
@@ -1335,6 +1338,7 @@ rfbUpdateClient(rfbClientPtr cl)
            +(tv.tv_usec-cl->startPtrDeferring.tv_usec)/1000)
            > cl->screen->deferPtrUpdateTime) {
           cl->startPtrDeferring.tv_usec = 0;
+          /* No checks on client status ??? (RFB_NORMAL)? */
           cl->screen->ptrAddEvent(cl->lastPtrButtons,
                                   cl->lastPtrX,
                                   cl->lastPtrY, cl);
