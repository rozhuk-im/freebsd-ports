--- src/libvncclient/vncviewer.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncclient/vncviewer.c
@@ -356,6 +356,12 @@ rfbClient* rfbGetClient(int bitsPerSample,int samplesP
   client->listen6Address = NULL;
   client->clientAuthSchemes = NULL;
 
+  client->external_sock = FALSE;
+  client->external_ctx = NULL;
+  client->ExternalRead = NULL;
+  client->ExternalWrite = NULL;
+  client->GotAuthDone = NULL;
+
 #ifdef LIBVNCSERVER_HAVE_SASL
   client->GetSASLMechanism = NULL;
   client->GetUser = NULL;
@@ -430,6 +436,86 @@ static rfbBool rfbInitConnection(rfbClient* client)
   return TRUE;
 }
 
+
+/* Auth related */
+
+static rfbBool rfbInitConnection1(rfbClient* client)
+{
+  /* Unless we accepted an incoming connection, make a TCP connection to the
+     given VNC server */
+  if (!client->listenSpecified) {
+    if (!client->serverHost)
+      return FALSE;
+    if (client->destHost) {
+      if (!ConnectToRFBRepeater(client,client->serverHost,client->serverPort,client->destHost,client->destPort))
+        return FALSE;
+    } else {
+      if (!ConnectToRFBServer(client,client->serverHost,client->serverPort))
+        return FALSE;
+    }
+  }
+  /*
+   * Initialise the VNC connection, including reading the password
+   */
+  if (!InitialiseRFBConnection1(client))
+    return FALSE;
+
+  return TRUE;
+}
+
+static rfbBool rfbInitConnection2(rfbClient* client)
+{
+
+  if (!InitialiseRFBConnection2(client))
+    return FALSE;
+
+  return TRUE;
+}
+
+static rfbBool rfbInitConnection3(rfbClient* client)
+{
+  if (!InitialiseRFBConnection3(client))
+    return FALSE;
+
+  client->width=client->si.framebufferWidth;
+  client->height=client->si.framebufferHeight;
+  if (!client->MallocFrameBuffer(client))
+    return FALSE;
+
+  if (!SetFormatAndEncodings(client))
+    return FALSE;
+
+  if (client->updateRect.x < 0) {
+    client->updateRect.x = client->updateRect.y = 0;
+    client->updateRect.w = client->width;
+    client->updateRect.h = client->height;
+  }
+
+  if (client->appData.scaleSetting>1)
+  {
+      if (!SendScaleSetting(client, client->appData.scaleSetting))
+          return FALSE;
+      if (!SendFramebufferUpdateRequest(client,
+			      client->updateRect.x / client->appData.scaleSetting,
+			      client->updateRect.y / client->appData.scaleSetting,
+			      client->updateRect.w / client->appData.scaleSetting,
+			      client->updateRect.h / client->appData.scaleSetting,
+			      FALSE))
+	      return FALSE;
+  }
+  else
+  {
+      if (!SendFramebufferUpdateRequest(client,
+			      client->updateRect.x, client->updateRect.y,
+			      client->updateRect.w, client->updateRect.h,
+			      FALSE))
+      return FALSE;
+  }
+
+  return TRUE;
+}
+
+
 rfbBool rfbInitClient(rfbClient* client,int* argc,char** argv) {
   int i,j;
 
@@ -511,6 +597,113 @@ rfbBool rfbInitClient(rfbClient* client,int* argc,char
   return TRUE;
 }
 
+
+/* Auth related */
+
+rfbBool rfbInitClient1(rfbClient* client,int* argc,char** argv) {
+  int i,j;
+
+  if(argv && argc && *argc) {
+    if(client->programName==0)
+      client->programName=argv[0];
+
+    for (i = 1; i < *argc; i++) {
+      j = i;
+      if (strcmp(argv[i], "-listen") == 0) {
+	listenForIncomingConnections(client);
+	break;
+      } else if (strcmp(argv[i], "-listennofork") == 0) {
+	listenForIncomingConnectionsNoFork(client, -1);
+	break;
+      } else if (strcmp(argv[i], "-play") == 0) {
+	client->serverPort = -1;
+	j++;
+      } else if (i+1<*argc && strcmp(argv[i], "-encodings") == 0) {
+	client->appData.encodingsString = argv[i+1];
+	j+=2;
+      } else if (i+1<*argc && strcmp(argv[i], "-compress") == 0) {
+	client->appData.compressLevel = atoi(argv[i+1]);
+	j+=2;
+      } else if (i+1<*argc && strcmp(argv[i], "-quality") == 0) {
+	client->appData.qualityLevel = atoi(argv[i+1]);
+	j+=2;
+      } else if (i+1<*argc && strcmp(argv[i], "-scale") == 0) {
+        client->appData.scaleSetting = atoi(argv[i+1]);
+        j+=2;
+      } else if (i+1<*argc && strcmp(argv[i], "-qosdscp") == 0) {
+        client->QoS_DSCP = atoi(argv[i+1]);
+        j+=2;
+      } else if (i+1<*argc && strcmp(argv[i], "-repeaterdest") == 0) {
+	char* colon=strchr(argv[i+1],':');
+
+	if(client->destHost)
+	  free(client->destHost);
+        client->destPort = 5900;
+
+	client->destHost = strdup(argv[i+1]);
+	if(client->destHost && colon) {
+	  client->destHost[(int)(colon-argv[i+1])] = '\0';
+	  client->destPort = atoi(colon+1);
+	}
+        j+=2;
+      } else {
+	char* colon=strrchr(argv[i],':');
+
+	if(client->serverHost)
+	  free(client->serverHost);
+
+	if(colon) {
+	  client->serverHost = strdup(argv[i]);
+	  if(client->serverHost) {
+	    client->serverHost[(int)(colon-argv[i])] = '\0';
+	    client->serverPort = atoi(colon+1);
+	  }
+	} else {
+	  client->serverHost = strdup(argv[i]);
+	}
+	if(client->serverPort >= 0 && client->serverPort < 5900)
+	  client->serverPort += 5900;
+      }
+      /* purge arguments */
+      if (j>i) {
+	*argc-=j-i;
+	memmove(argv+i,argv+j,(*argc-i)*sizeof(char*));
+	i--;
+      }
+    }
+  }
+
+  if(!rfbInitConnection1(client)) {
+    rfbClientCleanup(client);
+    return FALSE;
+  }
+
+  return TRUE;
+}
+
+/* second */
+rfbBool rfbInitClient2(rfbClient* client) {
+
+  if(!rfbInitConnection2(client)) {
+    rfbClientCleanup(client);
+    return FALSE;
+  }
+
+  return TRUE;
+}
+
+/* third */
+rfbBool rfbInitClient3(rfbClient* client) {
+
+  if(!rfbInitConnection3(client)) {
+    rfbClientCleanup(client);
+    return FALSE;
+  }
+
+  return TRUE;
+}
+
+
 void rfbClientCleanup(rfbClient* client) {
 #ifdef LIBVNCSERVER_HAVE_LIBZ
   int i;
@@ -554,8 +747,10 @@ void rfbClientCleanup(rfbClient* client) {
   if(client->vncRec)
 	  free(client->vncRec);
 
-  if (client->sock != RFB_INVALID_SOCKET)
-    rfbCloseSocket(client->sock);
+  if (!client->external_sock) {
+    if (client->sock != RFB_INVALID_SOCKET)
+      rfbCloseSocket(client->sock);
+  }
   if (client->listenSock != RFB_INVALID_SOCKET)
     rfbCloseSocket(client->listenSock);
   if (client->listen6Sock != RFB_INVALID_SOCKET)
