--- src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc.orig	2023-10-11 18:22:24 UTC
+++ src/3rdparty/chromium/third_party/perfetto/src/tracing/core/tracing_service_impl.cc
@@ -3213,7 +3213,8 @@ bool TracingServiceImpl::SnapshotClocks(
 
 #if !PERFETTO_BUILDFLAG(PERFETTO_OS_APPLE) && \
     !PERFETTO_BUILDFLAG(PERFETTO_OS_WIN) &&   \
-    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL)
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_NACL) && \
+    !PERFETTO_BUILDFLAG(PERFETTO_OS_BSD)
   struct {
     clockid_t id;
     protos::pbzero::BuiltinClock type;
