--- src/libvncclient/rfbclient.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncclient/rfbclient.c
@@ -317,7 +317,10 @@ ConnectToRFBServer(rfbClient* client,const char *hostn
 
     if (fread(buffer,1,strlen(magic),rec->file) != strlen(magic) || strncmp(buffer,magic,strlen(magic))) {
       rfbClientLog("File %s was not recorded by vncrec.\n",client->serverHost);
+      free(client->vncRec);
+      client->vncRec = NULL;
       fclose(rec->file);
+      rec->file = NULL;
       return FALSE;
     }
     client->sock = RFB_INVALID_SOCKET;
@@ -511,15 +514,7 @@ ReadSupportedSecurityType(rfbClient* client, uint32_t 
                 }
             }
         }
-        if (tAuth[loop]==rfbVncAuth || tAuth[loop]==rfbNoAuth ||
-			extAuthHandler ||
-#if defined(LIBVNCSERVER_HAVE_GNUTLS) || defined(LIBVNCSERVER_HAVE_LIBSSL)
-	    (!subAuth && (tAuth[loop]==rfbTLS || tAuth[loop]==rfbVeNCrypt)) ||
-#endif
-#ifdef LIBVNCSERVER_HAVE_SASL
-            tAuth[loop]==rfbSASL ||
-#endif /* LIBVNCSERVER_HAVE_SASL */
-            ((tAuth[loop]==rfbARD || tAuth[loop]==rfbUltraMSLogonII) && client->GetCredential))
+        if (tAuth[loop]==rfbVncAuth || tAuth[loop]==rfbNoAuth)
         {
             if (!subAuth && client->clientAuthSchemes)
             {
@@ -602,6 +597,50 @@ HandleVncAuth(rfbClient *client)
     return TRUE;
 }
 
+
+/* Auth related */
+
+static rfbBool
+HandleVncAuth1(rfbClient *client)
+{
+    uint8_t challenge[CHALLENGESIZE];
+
+    rfbClientLog("RUN HandleVncAuth1\n");
+
+    if (!ReadFromRFBServer(client, (char *)challenge, CHALLENGESIZE)) return FALSE;
+
+    if (client->serverPort!=-1) { /* if not playing a vncrec file */
+      /* save challenge in client structure */
+      memcpy(client->challenge, challenge, CHALLENGESIZE);
+    }
+
+    return TRUE;
+}
+
+
+static rfbBool
+HandleVncAuth2(rfbClient *client)
+{
+    uint8_t response[CHALLENGESIZE];
+    char *passwd=NULL;
+
+    rfbClientLog("RUN HandleVncAuth2\n");
+
+    if (client->serverPort!=-1) { /* if not playing a vncrec file */
+
+      /* restore response from client structure */
+      memcpy(response, client->response, CHALLENGESIZE);
+
+      if (!WriteToRFBServer(client, (char *)response, CHALLENGESIZE)) return FALSE;
+    }
+
+    /* Handle the SecurityResult message */
+    if (!rfbHandleAuthResult(client)) return FALSE;
+
+    return TRUE;
+}
+
+
 static void
 FreeUserCredential(rfbCredential *cred)
 {
@@ -1228,6 +1267,11 @@ InitialiseRFBConnection(rfbClient* client)
 
   client->desktopName[client->si.nameLength] = 0;
 
+  rfbClientLog("Remote VNC desktop size: %d x %d\n",
+               client->si.framebufferWidth, client->si.framebufferHeight);
+
+  if (client->GotAuthDone) client->GotAuthDone(client);
+
   rfbClientLog("Desktop name \"%s\"\n",client->desktopName);
 
   rfbClientLog("Connected to VNC server, using protocol version %d.%d\n",
@@ -1240,6 +1284,193 @@ InitialiseRFBConnection(rfbClient* client)
 }
 
 
+/* Auth related */
+
+rfbBool
+InitialiseRFBConnection1(rfbClient* client)
+{
+  rfbProtocolVersionMsg pv;
+  int major,minor;
+  uint32_t authScheme;
+  uint32_t subAuthScheme;
+  rfbClientInitMsg ci;
+
+  /* if the connection is immediately closed, don't report anything, so
+       that pmw's monitor can make test connections */
+
+  if (client->listenSpecified)
+    errorMessageOnReadFailure = FALSE;
+
+  if (!ReadFromRFBServer(client, pv, sz_rfbProtocolVersionMsg)) return FALSE;
+
+  errorMessageOnReadFailure = TRUE;
+
+  pv[sz_rfbProtocolVersionMsg] = 0;
+
+  if (sscanf(pv,rfbProtocolVersionFormat,&major,&minor) != 2) {
+    rfbClientLog("Not a valid VNC server (%s)\n",pv);
+    return FALSE;
+  }
+
+
+  DefaultSupportedMessages(client);
+  client->major = major;
+  client->minor = minor;
+
+  /* fall back to viewer supported version */
+  if ((major==rfbProtocolMajorVersion) && (minor>rfbProtocolMinorVersion))
+    client->minor = rfbProtocolMinorVersion;
+
+  /* UltraVNC uses minor codes 4 and 6 for the server */
+  if (major==3 && (minor==4 || minor==6)) {
+      rfbClientLog("UltraVNC server detected, enabling UltraVNC specific messages\n",pv);
+      DefaultSupportedMessagesUltraVNC(client);
+  }
+
+  /* UltraVNC Single Click uses minor codes 14 and 16 for the server */
+  if (major==3 && (minor==14 || minor==16)) {
+     minor = minor - 10;
+     client->minor = minor;
+     rfbClientLog("UltraVNC Single Click server detected, enabling UltraVNC specific messages\n",pv);
+     DefaultSupportedMessagesUltraVNC(client);
+  }
+
+  /* TightVNC uses minor codes 5 for the server */
+  if (major==3 && minor==5) {
+      rfbClientLog("TightVNC server detected, enabling TightVNC specific messages\n",pv);
+      DefaultSupportedMessagesTightVNC(client);
+  }
+
+  /* we do not support > RFB3.8 */
+  if ((major==3 && minor>8) || major>3)
+  {
+    client->major=3;
+    client->minor=8;
+  }
+
+  rfbClientLog("VNC server supports protocol version %d.%d (viewer %d.%d)\n",
+	  major, minor, rfbProtocolMajorVersion, rfbProtocolMinorVersion);
+
+  sprintf(pv,rfbProtocolVersionFormat,client->major,client->minor);
+
+  if (!WriteToRFBServer(client, pv, sz_rfbProtocolVersionMsg)) return FALSE;
+
+  /* 3.7 and onwards sends a # of security types first */
+  if (client->major==3 && client->minor > 6)
+  {
+    if (!ReadSupportedSecurityType(client, &authScheme, FALSE)) return FALSE;
+  }
+  else
+  {
+    if (!ReadFromRFBServer(client, (char *)&authScheme, 4)) return FALSE;
+    authScheme = rfbClientSwap32IfLE(authScheme);
+  }
+
+  rfbClientLog("Selected Security Scheme %d\n", authScheme);
+  client->authScheme = authScheme;
+  
+  switch (authScheme) {
+
+  case rfbConnFailed:
+    ReadReason(client);
+    return FALSE;
+
+  case rfbNoAuth:
+    rfbClientLog("No authentication needed\n");
+    /* 3.8 and upwards sends a Security Result for rfbNoAuth */
+    if ((client->major==3 && client->minor > 7) || client->major>3)
+        if (!rfbHandleAuthResult(client)) return FALSE;        
+    break;
+
+  case rfbVncAuth:
+    if (!HandleVncAuth1(client)) return FALSE;
+    break;
+
+  default:
+    rfbClientLog("Unknown authentication scheme from VNC server: %d\n",
+	    (int)authScheme);
+    return FALSE;
+  }
+
+  return TRUE;
+}
+
+
+rfbBool
+InitialiseRFBConnection2(rfbClient* client)
+{
+  uint32_t authScheme;
+
+  authScheme = client->authScheme;
+
+  rfbClientLog("Selected Security Scheme(2) %d\n", authScheme);
+  
+  switch (authScheme) {
+    case rfbVncAuth:
+      if (!HandleVncAuth2(client)) return FALSE;
+      break;
+
+    default:
+      rfbClientLog("Unknown authentication scheme(2) from VNC server: %d\n",
+                   (int)authScheme);
+      return FALSE;
+  }
+
+  return TRUE;
+}
+
+
+rfbBool
+InitialiseRFBConnection3(rfbClient* client)
+{
+  rfbClientInitMsg ci;
+
+  ci.shared = (client->appData.shareDesktop ? 1 : 0);
+
+  if (!WriteToRFBServer(client,  (char *)&ci, sz_rfbClientInitMsg)) return FALSE;
+
+  if (!ReadFromRFBServer(client, (char *)&client->si, sz_rfbServerInitMsg)) return FALSE;
+
+  client->si.framebufferWidth = rfbClientSwap16IfLE(client->si.framebufferWidth);
+  client->si.framebufferHeight = rfbClientSwap16IfLE(client->si.framebufferHeight);
+  client->si.format.redMax = rfbClientSwap16IfLE(client->si.format.redMax);
+  client->si.format.greenMax = rfbClientSwap16IfLE(client->si.format.greenMax);
+  client->si.format.blueMax = rfbClientSwap16IfLE(client->si.format.blueMax);
+  client->si.nameLength = rfbClientSwap32IfLE(client->si.nameLength);
+
+  rfbClientLog("Remote VNC desktop size: %d x %d\n",
+               client->si.framebufferWidth, client->si.framebufferHeight);
+
+  if (client->si.nameLength > 1<<20) {
+      rfbClientErr("Too big desktop name length sent by server: %u B > 1 MB\n", (unsigned int)client->si.nameLength);
+      return FALSE;
+  }
+
+  client->desktopName = malloc(client->si.nameLength + 1);
+  if (!client->desktopName) {
+    rfbClientLog("Error allocating memory for desktop name, %lu bytes\n",
+            (unsigned long)client->si.nameLength);
+    return FALSE;
+  }
+
+  if (!ReadFromRFBServer(client, client->desktopName, client->si.nameLength)) return FALSE;
+
+  client->desktopName[client->si.nameLength] = 0;
+
+  if (client->GotAuthDone) client->GotAuthDone(client);
+
+  rfbClientLog("Desktop name \"%s\"\n",client->desktopName);
+
+  rfbClientLog("Connected to VNC server, using protocol version %d.%d\n",
+	  client->major, client->minor);
+
+  rfbClientLog("VNC server default format:\n");
+  PrintPixelFormat(&client->si.format);
+
+  return TRUE;
+}
+
+
 /*
  * SetFormatAndEncodings.
  */
@@ -2559,16 +2790,19 @@ HandleRFBServerMessage(rfbClient* client)
       client->SoftCursorUnlockScreen(client);
 
       client->GotFrameBufferUpdate(client, rect.r.x, rect.r.y, rect.r.w, rect.r.h);
-    }
+    } /* For each reactangle (msg.fu.nRects) received. */
 
+
     if (!SendIncrementalFramebufferUpdateRequest(client))
       return FALSE;
+    /* Always send new SendFramebufferUpdateRequest after end of processing rfbFramebufferUpdate msg. */
 
     if (client->FinishedFrameBufferUpdate)
       client->FinishedFrameBufferUpdate(client);
+    /* Done with got and appropriate update all rectangles. Done with rfbFramebufferUpdate msg. */
 
     break;
-  }
+  } /* end of "case rfbFramebufferUpdate:" */
 
   case rfbBell:
   {
