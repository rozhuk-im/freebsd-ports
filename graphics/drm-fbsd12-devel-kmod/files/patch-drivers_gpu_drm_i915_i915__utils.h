--- drivers/gpu/drm/i915/i915_utils.h	2020-01-15 12:22:44.000000000 +0300
+++ drivers/gpu/drm/i915/i915_utils.h	2020-08-26 06:17:28.764476000 +0300
@@ -123,11 +123,13 @@
 
 #include <linux/list.h>
 
+#if __FreeBSD_version < 1201523
 static inline int list_is_first(const struct list_head *list,
 				const struct list_head *head)
 {
 	return head->next == list;
 }
+#endif
 
 static inline void __list_del_many(struct list_head *head,
 				   struct list_head *first)
