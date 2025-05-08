--- drivers/gpu/drm/drm_gem_atomic_helper.c
+++ drivers/gpu/drm/drm_gem_atomic_helper.c
@@ -20,14 +20,13 @@ drm_gem_plane_helper_prepare_fb(struct drm_plane *dp,
 		obj = dps->fb->obj[0];
 		if (obj == NULL)
 			return -EINVAL;
-		if (dps->fence) {
-			printf("%s: explicit fence not handled\n", __func__);
-			return -EINVAL;
-		}
 		r = dma_resv_get_singleton(obj->resv, DMA_RESV_USAGE_WRITE, &f);
 		if (r)
 			return r;
-		dps->fence = f;
+		if (dps->fence)
+			dma_fence_put(f);
+		else
+			dps->fence = f;
 	}
 
 	return 0;

