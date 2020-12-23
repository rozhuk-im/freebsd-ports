--- gio/gunixmounts.c.orig	2020-10-01 16:17:53.138733000 +0300
+++ gio/gunixmounts.c	2020-10-18 01:26:30.563084000 +0300
@@ -1654,10 +1654,28 @@
 GList *
 g_unix_mount_points_get (guint64 *time_read)
 {
+  static GList *mnt_pts_last = NULL;
+  static guint64 time_read_last = 0;
+  GList *mnt_pts = NULL;
+  guint64 time_read_now;
+  G_LOCK_DEFINE_STATIC (unix_mount_points);
+
+  G_LOCK (unix_mount_points);
+
+  time_read_now = get_mount_points_timestamp ();
+  if (time_read_now != time_read_last || mnt_pts_last == NULL) {
+    time_read_last = time_read_now;
+    g_list_free_full (mnt_pts_last, (GDestroyNotify) g_unix_mount_point_free);
+    mnt_pts_last = _g_get_unix_mount_points ();
+  }
+  mnt_pts = g_list_copy_deep(mnt_pts_last, g_unix_mount_point_copy, NULL);
+
+  G_UNLOCK (unix_mount_points);
+
   if (time_read)
-    *time_read = get_mount_points_timestamp ();
+    *time_read = time_read_last;
 
-  return _g_get_unix_mount_points ();
+  return mnt_pts;
 }
 
 /**
