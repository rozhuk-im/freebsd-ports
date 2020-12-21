--- thunar/thunar-application.c.orig	2020-05-24 12:27:08 UTC
+++ thunar/thunar-application.c
@@ -36,6 +36,9 @@
 #ifdef HAVE_TIME_H
 #include <time.h>
 #endif
+#ifdef HAVE_FCNTL_H
+#include <fcntl.h>
+#endif
 
 #include <stdlib.h>
 
@@ -542,6 +545,16 @@ thunar_application_command_line (GApplication         
           /* we failed to process the filenames or the bulk rename failed */
           g_application_command_line_printerr (command_line, "Thunar: %s\n", error->message);
         }
+    }
+  else if (daemon)
+    {
+      /* Close stdin, stdout, stderr and reopen. */
+      close(0);
+      close(1);
+      close(2);
+      open("/dev/null", O_RDONLY);
+      open("/dev/null", O_RDWR);
+      open("/dev/null", O_RDWR);
     }
 
 out:
