--- src/libvncserver/rfbserver.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncserver/rfbserver.c
@@ -368,7 +368,6 @@ rfbNewTCPOrUDPClient(rfbScreenInfoPtr rfbScreen,
 		     (char *)&one, sizeof(one)) < 0) {
 	rfbLogPerror("setsockopt failed: can't set TCP_NODELAY flag, non TCP socket?");
       }
-
       FD_SET(sock,&(rfbScreen->allFds));
 		rfbScreen->maxFd = rfbMax(sock,rfbScreen->maxFd);
 #endif
@@ -581,7 +580,8 @@ rfbClientConnectionGone(rfbClientPtr cl)
 #endif
 
     if(cl->sock != RFB_INVALID_SOCKET)
-	rfbCloseSocket(cl->sock);
+      if (!cl->screen->external_sock)
+        rfbCloseSocket(cl->sock);
 
     if (cl->scaledScreen!=NULL)
         cl->scaledScreen->scaledScreenRefCount--;
