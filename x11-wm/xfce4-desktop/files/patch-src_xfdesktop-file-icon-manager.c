--- src/xfdesktop-file-icon-manager.c.orig	2026-03-27 13:45:10.000000000 +0200
+++ src/xfdesktop-file-icon-manager.c	2026-10-21 23:13:26.903870000 +0300
@@ -1473,6 +1473,7 @@
             mdata->position_config = candidates->data;
         }
 
+        monitor = xfce_desktop_get_monitor(desktop);
         xfdesktop_icon_position_configs_assign_monitor(fmanager->position_configs, mdata->position_config, monitor);
 
         g_list_free(candidates);
