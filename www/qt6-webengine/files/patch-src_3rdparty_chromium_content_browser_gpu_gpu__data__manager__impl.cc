--- src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.cc.orig	2023-04-28 17:01:32 UTC
+++ src/3rdparty/chromium/content/browser/gpu/gpu_data_manager_impl.cc
@@ -405,7 +405,7 @@ void GpuDataManagerImpl::OnDisplayMetricsChanged(
   private_->OnDisplayMetricsChanged(display, changed_metrics);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool GpuDataManagerImpl::IsGpuMemoryBufferNV12Supported() {
   base::AutoLock auto_lock(lock_);
   return private_->IsGpuMemoryBufferNV12Supported();
