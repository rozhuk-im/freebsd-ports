--- conf/config.php	2019-07-20 15:17:00.000000000 +0300
+++ conf/config.php	2019-08-06 00:54:08.595573000 +0300
@@ -28,14 +28,14 @@
 	$do_diagnostic = true;
 	$log_file = '/tmp/errors.log';		// path to log file (comment or leave blank to disable logging)
 
-	$saveUploadedTorrents = true;		// Save uploaded torrents to profile/torrents directory or not
+	$saveUploadedTorrents = false;		// Save uploaded torrents to profile/torrents directory or not
 	$overwriteUploadedTorrents = false;     // Overwrite existing uploaded torrents in profile/torrents directory or make unique name
 
 	$topDirectory = '/';			// Upper available directory. Absolute path with trail slash.
 	$forbidUserSettings = false;
 
-	$scgi_port = 5000;
-	$scgi_host = "127.0.0.1";
+	$scgi_port = 0;
+	$scgi_host = "unix:///var/run/rtorrent-rpc.sock";
 
 	// For web->rtorrent link through unix domain socket 
 	// (scgi_local in rtorrent conf file), change variables 
@@ -47,11 +47,17 @@
 	$XMLRPCMountPoint = "/RPC2";		// DO NOT DELETE THIS LINE!!! DO NOT COMMENT THIS LINE!!!
 
 	$pathToExternals = array(
-		"php" 	=> '',			// Something like /usr/bin/php. If empty, will be found in PATH.
-		"curl"	=> '',			// Something like /usr/bin/curl. If empty, will be found in PATH.
-		"gzip"	=> '',			// Something like /usr/bin/gzip. If empty, will be found in PATH.
-		"id"	=> '',			// Something like /usr/bin/id. If empty, will be found in PATH.
-		"stat"	=> '',			// Something like /usr/bin/stat. If empty, will be found in PATH.
+		"php" 	=> '/usr/local/bin/php',
+		"curl"	=> '/usr/local/bin/curl',
+		"gzip"	=> '/usr/bin/gzip',
+		"id"	=> '/usr/bin/id',
+		"stat"	=> '/usr/bin/stat',
+		"pgrep"	=> '/usr/bin/pgrep',
+		"unzip"	=> '/usr/bin/unzip',
+		"unrar"	=> '/usr/local/bin/unrar',
+		"ffmpeg"=> '/usr/local/bin/ffmpeg',
+		"sox"	=> '/usr/local/bin/sox',
+		"mediainfo"=> '/usr/local/bin/mediainfo',
 	);
 
 	$localhosts = array( 			// list of local interfaces
@@ -64,7 +70,7 @@
 						// Both Webserver and rtorrent users must have read-write access to it.
 						// For example, if Webserver and rtorrent users are in the same group then the value may be 0770.
 
-	$tempDirectory = null;			// Temp directory. Absolute path with trail slash. If null, then autodetect will be used.
+	$tempDirectory = '/tmp';		// Temp directory. Absolute path with trail slash. If null, then autodetect will be used.
 
 	$canUseXSendFile = false;		// If true then use X-Sendfile feature if it exist
 
