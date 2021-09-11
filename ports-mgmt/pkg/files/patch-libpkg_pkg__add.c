--- libpkg/pkg_add.c
+++ libpkg/pkg_add.c
@@ -276,7 +276,7 @@
 	times[0] = *ats;
 	times[1] = *mts;
 	if (utimensat(fd, RELATIVE_PATH(path), times,
-	    AT_SYMLINK_NOFOLLOW) == -1 && errno != EOPNOTSUPP){
+	    AT_SYMLINK_NOFOLLOW) == -1 && errno != EOPNOTSUPP && ENOENT != errno){
 		pkg_fatal_errno("Failed to set time on %s", path);
 	}
 
