--- src/xfdesktop-icon-view.c.orig	2026-03-27 13:45:10.000000000 +0200
+++ src/xfdesktop-icon-view.c	2026-10-21 22:40:16.777046000 +0300
@@ -4251,8 +4251,8 @@
 xfdesktop_icon_view_set_model(XfdesktopIconView *icon_view,
                               GtkTreeModel *model)
 {
-    g_return_if_fail(XFDESKTOP_IS_ICON_VIEW(icon_view));
     g_return_if_fail(model == NULL || GTK_IS_TREE_MODEL(model));
+    g_return_if_fail(XFDESKTOP_IS_ICON_VIEW(icon_view));
 
     if (model == icon_view->model) {
         return;
