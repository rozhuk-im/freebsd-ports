--- src/libvncserver/auth.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncserver/auth.c
@@ -112,7 +112,13 @@ rfbVncAuthSendChallenge(rfbClientPtr cl)
 	
     /* 4 byte header is alreay sent. Which is rfbSecTypeVncAuth 
        (same as rfbVncAuth). Just send the challenge. */
-    rfbRandomBytes(cl->authChallenge);
+
+    /* Dont need now
+     * The cl->authChallenge
+     * Was already filled at Server Initialization stage.
+     */
+    //rfbRandomBytes(cl->authChallenge);
+
     if (rfbWriteExact(cl, (char *)cl->authChallenge, CHALLENGESIZE) < 0) {
         rfbLogPerror("rfbAuthNewClient: write");
         rfbCloseClient(cl);
