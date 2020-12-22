--- modules/cron/tasks_extended.go.orig	2020-09-04 00:44:50.000000000 +0300
+++ modules/cron/tasks_extended.go	2020-10-16 15:13:25.923723000 +0300
@@ -77,26 +77,6 @@
 	})
 }
 
-func registerReinitMissingRepositories() {
-	RegisterTaskFatal("reinit_missing_repos", &BaseConfig{
-		Enabled:    false,
-		RunAtStart: false,
-		Schedule:   "@every 72h",
-	}, func(ctx context.Context, _ *models.User, _ Config) error {
-		return repo_module.ReinitMissingRepositories(ctx)
-	})
-}
-
-func registerDeleteMissingRepositories() {
-	RegisterTaskFatal("delete_missing_repos", &BaseConfig{
-		Enabled:    false,
-		RunAtStart: false,
-		Schedule:   "@every 72h",
-	}, func(ctx context.Context, user *models.User, _ Config) error {
-		return repo_module.DeleteMissingRepositories(ctx, user)
-	})
-}
-
 func registerRemoveRandomAvatars() {
 	RegisterTaskFatal("delete_generated_repository_avatars", &BaseConfig{
 		Enabled:    false,
@@ -113,7 +93,5 @@
 	registerGarbageCollectRepositories()
 	registerRewriteAllPublicKeys()
 	registerRepositoryUpdateHook()
-	registerReinitMissingRepositories()
-	registerDeleteMissingRepositories()
 	registerRemoveRandomAvatars()
 }
