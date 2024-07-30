--- externals/phpmailer/class.phpmailer.php.orig	2024-07-30 15:40:58 UTC
+++ externals/phpmailer/class.phpmailer.php
@@ -1624,7 +1624,7 @@ class PHPMailer {
     $eol = "\r\n";
     $escape = '=';
     $output = '';
-    while( list(, $line) = each($lines) ) {
+    foreach ($lines as $i => $line) {
       $linlen = strlen($line);
       $newline = '';
       for($i = 0; $i < $linlen; $i++) {
