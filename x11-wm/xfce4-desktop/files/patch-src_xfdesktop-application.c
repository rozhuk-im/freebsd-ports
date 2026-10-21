--- src/xfdesktop-application.c.orig	2026-03-27 13:45:10.000000000 +0200
+++ src/xfdesktop-application.c	2026-10-21 23:35:48.449130000 +0300
@@ -1002,7 +1002,7 @@
     TRACE("entering, %s", xfw_monitor_get_description(monitor));
     g_signal_handlers_disconnect_by_data(monitor, app);
     remove_monitor_desktop(app, monitor);
-    handle_monitors_changed(app);
+    //handle_monitors_changed(app);
 }
 
 static void
