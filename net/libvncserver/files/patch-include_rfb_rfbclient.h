--- include/rfb/rfbclient.h.orig	2024-12-22 09:54:53 UTC
+++ include/rfb/rfbclient.h
@@ -219,6 +219,17 @@ typedef void (*BellProc)(struct _rfbClient* client);
 typedef void (*GotXCutTextProc)(struct _rfbClient* client, const char *text, int textlen);
 typedef void (*GotXCutTextUTF8Proc)(struct _rfbClient* client, const char* buffer, int buffer_len);
 typedef void (*BellProc)(struct _rfbClient* client);
+typedef ssize_t (*ExternalReadProc)(char *sess, int fd, void *buf, size_t count);
+typedef ssize_t (*ExternalWriteProc)(char *sess, int fd, const void *buf, size_t count);
+
+typedef ssize_t (*ClientInfoReceivedProc)(char *context, char *desktopName,
+                                          uint16_t framebufferWidth,
+                                          uint16_t framebufferHeight);
+
+typedef void (*GotAuthDoneProc)(struct _rfbClient* client);
+
+/* The context here is the "struct _rfbClient* client". */
+typedef ssize_t (*ExternalFileReadProc)(char *context, void *buf, size_t count);
 /**
     Called when a cursor shape update was received from the server. The decoded cursor shape
     will be in client->rcSource. It's up to the application to do something with this, e.g. draw
@@ -252,6 +263,9 @@ typedef struct _rfbClient {
 	int serverPort; /**< if -1, then use file recorded by vncrec */
 	rfbBool listenSpecified;
 	int listenPort, flashPort;
+	rfbBool external_sock;
+	char *external_ctx;
+	char *vnc_actions; /* Hide HoundVncLibActions structure. */
 
 	struct {
 		int x, y, w, h;
@@ -280,6 +294,15 @@ typedef struct _rfbClient {
 	char *bufoutptr;
 	unsigned int buffered;
 
+	/* rfbproto.c */
+
+	/* SI Auth Addon */
+	uint8_t challenge[CHALLENGESIZE];
+	uint8_t response[CHALLENGESIZE];
+	int challenge_set;
+	int response_set;
+	int auth_done_set;
+
 	/* The zlib encoding requires expansion/decompression/deflation of the
 	   compressed data in the "buffer" above into another, result buffer.
 	   However, the size of the result buffer can be determined precisely
@@ -358,6 +381,12 @@ typedef struct _rfbClient {
 	MallocFrameBufferProc MallocFrameBuffer;
 	GotXCutTextProc GotXCutText;
 	BellProc Bell;
+	/* My add-on to rfbClient struct. */
+	ExternalReadProc ExternalRead;
+	ExternalWriteProc ExternalWrite;
+	ClientInfoReceivedProc ClientInfoReceived;
+	GotAuthDoneProc GotAuthDone;
+	ExternalFileReadProc ExternalFileRead; /* ExternalPlaybackFileRead */
 
 	GotCursorShapeProc GotCursorShape;
 	GotCopyRectProc GotCopyRect;
@@ -514,6 +543,12 @@ extern rfbBool InitialiseRFBConnection(rfbClient* clie
 extern rfbBool ConnectToRFBRepeater(rfbClient* client,const char *repeaterHost, int repeaterPort, const char *destHost, int destPort);
 extern void SetClientAuthSchemes(rfbClient* client,const uint32_t *authSchemes, int size);
 extern rfbBool InitialiseRFBConnection(rfbClient* client);
+
+/* Auth related, split auth on 3 stages. */
+extern rfbBool InitialiseRFBConnection1(rfbClient* client);
+extern rfbBool InitialiseRFBConnection2(rfbClient* client);
+extern rfbBool InitialiseRFBConnection3(rfbClient* client);
+
 /**
  * Sends format and encoding parameters to the server. Your application can
  * modify the 'client' data structure directly. However some changes to this
@@ -868,6 +903,12 @@ rfbBool rfbInitClient(rfbClient* client,int* argc,char
  * @return true if the client was initialized successfully, false otherwise.
  */
 rfbBool rfbInitClient(rfbClient* client,int* argc,char** argv);
+
+/* Auth related, split auth on 3 stages. */
+rfbBool rfbInitClient1(rfbClient* client,int* argc,char** argv);
+rfbBool rfbInitClient2(rfbClient* client);
+rfbBool rfbInitClient3(rfbClient* client);
+
 /**
  * Cleans up the client structure and releases the memory allocated for it. You
  * should call this when you're done with the rfbClient structure that you
