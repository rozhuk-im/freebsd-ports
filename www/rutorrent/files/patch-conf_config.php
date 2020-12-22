--- conf/config.php.orig	2024-10-27 15:31:31 UTC
+++ conf/config.php
@@ -30,14 +30,14 @@
 
 	$log_file = '/tmp/errors.log';		// path to log file (comment or leave blank to disable logging)
 
-	$saveUploadedTorrents = true;		// Save uploaded torrents to profile/torrents directory or not
+	$saveUploadedTorrents = false;		// Save uploaded torrents to profile/torrents directory or not
 	$overwriteUploadedTorrents = false;	// Overwrite existing uploaded torrents in profile/torrents directory or make unique name
 
 	$topDirectory = '/';			// Upper available directory. Absolute path with trail slash.
 	$forbidUserSettings = false;
 
-	$scgi_port = 5000;
-	$scgi_host = "127.0.0.1";
+	$scgi_port = 0;
+	$scgi_host = "unix:///var/run/rtorrent-rpc.sock";
 
 	// For web->rtorrent link through unix domain socket
 	// (scgi_local in rtorrent conf file), change variables
@@ -52,11 +52,17 @@
 	// Can't be greater then 327625*1024 due to limitation in libtorrent ResourceManager::set_max_upload_unchoked function.
 
 	$pathToExternals = array(
-		"php"	=> '',			// Something like /usr/bin/php. If empty, will be found in PATH.
-		"curl"	=> '',			// Something like /usr/bin/curl. If empty, will be found in PATH.
-		"gzip"	=> '',			// Something like /usr/bin/gzip. If empty, will be found in PATH.
-		"id"	=> '',			// Something like /usr/bin/id. If empty, will be found in PATH.
-		"stat"	=> '',			// Something like /usr/bin/stat. If empty, will be found in PATH.
+		"php"	=> '/usr/local/bin/php',	// Something like /usr/bin/php. If empty, will be found in PATH.
+		"curl"	=> '/usr/local/bin/curl',	// Something like /usr/bin/curl. If empty, will be found in PATH.
+		"gzip"	=> '/usr/bin/gzip',		// Something like /usr/bin/gzip. If empty, will be found in PATH.
+		"id"	=> '/usr/bin/id',		// Something like /usr/bin/id. If empty, will be found in PATH.
+		"stat"	=> '/usr/bin/stat',		// Something like /usr/bin/stat. If empty, will be found in PATH.
+		"pgrep"	=> '/bin/pgrep',
+		"unzip"	=> '/usr/bin/unzip',
+		"unrar"	=> '/usr/local/bin/unrar',
+		"ffmpeg"=> '/usr/local/bin/ffmpeg',
+		"sox"	=> '/usr/local/bin/sox',
+		"mediainfo"=> '/usr/local/bin/mediainfo',
 	);
 
 	$localHostedMode = false;		// Set to true if rTorrent is hosted on the SAME machine as ruTorrent
@@ -65,6 +71,7 @@
 										// Required to clear web browser cache when upgrading versions	
 
 	$localhosts = array(			// list of local interfaces
+		"::1",
 		"127.0.0.1",
 		"localhost",
 	);
