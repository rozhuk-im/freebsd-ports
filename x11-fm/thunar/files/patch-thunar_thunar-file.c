--- thunar/thunar-file.c.orig	2015-05-22 13:25:36 UTC
+++ thunar/thunar-file.c
@@ -3544,22 +3544,11 @@
 {
   _thunar_return_val_if_fail (THUNAR_IS_FILE (file), FALSE);
 
-  /* we can only change the mode if we the euid is
-   *   a) equal to the file owner id
-   * or
-   *   b) the super-user id
-   * and the file is not in the trash.
-   */
-  if (file->info == NULL)
-    {
-      return (effective_user_id == 0 && !thunar_file_is_trashed (file));
-    }
-  else
-    {
-      return ((effective_user_id == 0
-               || effective_user_id == g_file_info_get_attribute_uint32 (file->info, G_FILE_ATTRIBUTE_UNIX_UID))
-              && !thunar_file_is_trashed (file));
-    }
+  if (thunar_file_is_trashed (file))
+      return (FALSE);
+  if (effective_user_id == 0)
+      return (TRUE);
+  return (thunar_file_is_writable (file));
 }
 
 
