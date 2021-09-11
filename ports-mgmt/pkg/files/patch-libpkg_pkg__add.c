--- libpkg/pkg_add.c
+++ libpkg/pkg_add.c
@@ -321,7 +321,7 @@
 	times[0] = *ats;
 	times[1] = *mts;
 	if (utimensat(fd, RELATIVE_PATH(path), times,
-	    AT_SYMLINK_NOFOLLOW) == -1 && errno != EOPNOTSUPP){
+	    AT_SYMLINK_NOFOLLOW) == -1 && errno != EOPNOTSUPP && ENOENT != errno){
 		pkg_fatal_errno("Fail to set time on %s", path);
 	}
 
