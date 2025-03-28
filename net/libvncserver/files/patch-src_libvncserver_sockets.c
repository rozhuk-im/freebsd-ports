--- src/libvncserver/sockets.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncserver/sockets.c
@@ -303,7 +303,8 @@ void rfbShutdownSockets(rfbScreenInfoPtr rfbScreen)
 
     if(rfbScreen->inetdSock!=RFB_INVALID_SOCKET) {
 	FD_CLR(rfbScreen->inetdSock,&rfbScreen->allFds);
-	rfbCloseSocket(rfbScreen->inetdSock);
+      if (!rfbScreen->external_sock)
+        rfbCloseSocket(rfbScreen->inetdSock);
 	rfbScreen->inetdSock=RFB_INVALID_SOCKET;
     }
 
@@ -600,7 +601,8 @@ rfbCloseClient(rfbClientPtr cl)
 	/* Either no threading support or threading support with screen->backgroundloop == false */
 	{
 	    /* Close client sock */
-	    rfbCloseSocket(cl->sock);
+	    if (!cl->screen->external_sock)
+		rfbCloseSocket(cl->sock);
 	    cl->sock = RFB_INVALID_SOCKET;
 	}
 }
