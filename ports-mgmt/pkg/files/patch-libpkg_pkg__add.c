--- libpkg/pkg_add.c	2021-07-27 19:05:47.000000000 +0300
+++ libpkg/pkg_add.c	2021-09-11 15:55:48.975343000 +0300
@@ -245,7 +245,7 @@
 	times[1] = *mts;
 	if (utimensat(fd, RELATIVE_PATH(path), times,
 	    AT_SYMLINK_NOFOLLOW) == -1 && errno != EOPNOTSUPP){
-		pkg_fatal_errno("Fail to set time on %s", path);
+		goto err_out_settime;
 	}
 	if (errno == EOPNOTSUPP) {
 #endif
@@ -264,6 +264,9 @@
 
 		if (errno != ENOSYS) {
 			close(fdcwd);
+err_out_settime:
+			if (ENOENT == errno)
+				return (EPKG_OK);
 			pkg_fatal_errno("Fail to set time on %s", path);
 		}
 		else {
