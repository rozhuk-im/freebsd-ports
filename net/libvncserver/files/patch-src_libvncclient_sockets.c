--- src/libvncclient/sockets.c.orig	2024-12-22 09:54:53 UTC
+++ src/libvncclient/sockets.c
@@ -59,17 +59,57 @@ rfbBool errorMessageOnReadFailure = TRUE;
  *    events are processed, as there is no XtAppMainLoop in the program.
  */
 
+
+
+ssize_t ReadFromFile(rfbClient* client, void *out, size_t n) {
+  ssize_t j;
+
+  if (client->ExternalFileRead) {
+    j = client->ExternalFileRead(client->external_ctx, out, n);
+  } else {
+    j = fread(out,1,n,client->vncRec->file);
+  }
+
+  return j;
+}
+
+ssize_t ReadFromSocket(rfbClient* client, void *out, size_t n) {
+  ssize_t j;
+
+  if (client->ExternalRead) {
+    j = client->ExternalRead(client->external_ctx, client->sock, out, n);
+  } else {  
+    j = read(client->sock, out, n);
+  }
+
+  return j;
+}
+
+ssize_t WriteToSocket(rfbClient* client, const void *buf, size_t count) {
+  ssize_t j;
+
+  if (client->ExternalWrite) {
+    j = client->ExternalWrite(client->external_ctx, client->sock, buf, count);
+  } else {
+    j = write(client->sock, buf, count);
+  }
+
+  return j;
+}
+
+
 rfbBool
 ReadFromRFBServer(rfbClient* client, char *out, unsigned int n)
 {
+  rfbBool ret;
   const int USECS_WAIT_PER_RETRY = 100000;
   int retries = 0;
 #undef DEBUG_READ_EXACT
 #ifdef DEBUG_READ_EXACT
 	char* oout=out;
 	unsigned int nn=n;
-	rfbClientLog("ReadFromRFBServer %d bytes\n",n);
 #endif
+  rfbClientLog("ReadFromRFBServer %d bytes\n",n);
 
   /* Handle attempts to write to NULL out buffer that might occur
      when an outside malloc() fails. For instance, memcpy() to NULL
@@ -81,12 +121,27 @@ ReadFromRFBServer(rfbClient* client, char *out, unsign
     /* vncrec playing */
     rfbVNCRec* rec = client->vncRec;
     struct timeval tv;
+    unsigned char *ptr;
+    ssize_t j;
 
+    if (client->ExternalFileRead) {
+      rec->readTimestamp = FALSE;
+    }
     if (rec->readTimestamp) {
       rec->readTimestamp = FALSE;
       if (!fread(&tv,sizeof(struct timeval),1,rec->file))
         return FALSE;
 
+      /* inspect timeval value format */
+      if (rfbEnableClientLogging) {
+        int ii;
+        fprintf(stderr,"time:\n");
+        ptr = (unsigned char *)&tv;
+        for(ii=0;ii<sizeof(struct timeval);ii++)
+          fprintf(stderr,"%02x ", ptr[ii]);
+        fprintf(stderr,"\n");
+      }
+
       tv.tv_sec = rfbClientSwap32IfLE (tv.tv_sec);
       tv.tv_usec = rfbClientSwap32IfLE (tv.tv_usec);
 
@@ -108,8 +163,21 @@ ReadFromRFBServer(rfbClient* client, char *out, unsign
 
       rec->tv=tv;
     }
-    
-    return (fread(out,1,n,rec->file) != n ? FALSE : TRUE);
+
+    j = ReadFromFile(client, out, n);
+    ret = (j != n) ? FALSE : TRUE;
+
+    rfbClientLog("ReadFromFile (retcode: %d, j = %d, n = %d)\n", ret, j, n);
+
+    /* inspect return readed file data */
+    if (rfbEnableClientLogging) {
+      int ii;
+      for(ii=0;ii<n;ii++)
+        fprintf(stderr,"%02x ",(unsigned char)out[ii]);
+      fprintf(stderr,"\n");
+    }
+
+    return ret;
   }
   
   if (n <= client->buffered) {
@@ -142,7 +210,7 @@ ReadFromRFBServer(rfbClient* client, char *out, unsign
         i = ReadFromSASL(client, client->buf + client->buffered, RFB_BUF_SIZE - client->buffered);
       else {
 #endif /* LIBVNCSERVER_HAVE_SASL */
-        i = read(client->sock, client->buf + client->buffered, RFB_BUF_SIZE - client->buffered);
+        i = ReadFromSocket(client, client->buf + client->buffered, RFB_BUF_SIZE - client->buffered);
 #ifdef WIN32
 	if (i < 0) errno=WSAGetLastError();
 #endif
@@ -194,7 +262,7 @@ ReadFromRFBServer(rfbClient* client, char *out, unsign
         i = ReadFromSASL(client, out, n);
       else
 #endif
-        i = read(client->sock, out, n);
+        i = ReadFromSocket(client, out, n);
 
       if (i <= 0) {
 	if (i < 0) {
@@ -251,13 +319,14 @@ WriteToRFBServer(rfbClient* client, const char *buf, u
 {
   fd_set fds;
   int i = 0;
-  int j;
+  ssize_t j;
   const char *obuf = buf;
 #ifdef LIBVNCSERVER_HAVE_SASL
   const char *output;
   unsigned int outputlen;
   int err;
 #endif /* LIBVNCSERVER_HAVE_SASL */
+  rfbClientLog("WriteToRFBServer %d bytes\n", n);
 
   if (client->serverPort==-1)
     return TRUE; /* vncrec playing */
@@ -285,7 +354,7 @@ WriteToRFBServer(rfbClient* client, const char *buf, u
 #endif /* LIBVNCSERVER_HAVE_SASL */
 
   while (i < n) {
-    j = write(client->sock, obuf + i, (n - i));
+    j = WriteToSocket(client, obuf + i, (n - i));
     if (j <= 0) {
       if (j < 0) {
 #ifdef WIN32
