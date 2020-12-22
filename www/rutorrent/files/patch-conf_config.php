--- conf/config.php.orig	2024-10-27 15:31:31 UTC
+++ conf/config.php
@@ -36,15 +36,15 @@
 	$topDirectory = $_ENV['RU_TOP_DIR'] ?? '/';			// Upper available directory. Absolute path with trail slash.
 	$forbidUserSettings = false;
 
-	$scgi_port = $_ENV['RU_SCGI_PORT'] ?? 5000;
-	$scgi_host = $_ENV['RU_SCGI_HOST'] ?? "127.0.0.1";
+//	$scgi_port = $_ENV['RU_SCGI_PORT'] ?? 5000;
+//	$scgi_host = $_ENV['RU_SCGI_HOST'] ?? "127.0.0.1";
 
 	// For web->rtorrent link through unix domain socket
 	// (scgi_local in rtorrent conf file), change variables
 	// above to something like this:
 	//
-	// $scgi_port = 0;
-	// $scgi_host = "unix:///tmp/rpc.socket";
+	$scgi_port = 0;
+	$scgi_host = "unix:///var/run/rtorrent/rtorrent-rpc.sock";
 
 	$XMLRPCMountPoint = "/RPC2";		// DO NOT DELETE THIS LINE!!! DO NOT COMMENT THIS LINE!!!
 
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
