--- src/VBox/Main/src-server/freebsd/PerformanceFreeBSD.cpp.orig	2017-07-27 13:18:27 UTC
+++ src/VBox/Main/src-server/freebsd/PerformanceFreeBSD.cpp
@@ -58,45 +58,36 @@
 
 int CollectorFreeBSD::getHostMemoryUsage(ULONG *total, ULONG *used, ULONG *available)
 {
-    int rc = VINF_SUCCESS;
     u_long cbMemPhys = 0;
     u_int cPagesMemFree = 0;
-    u_int cPagesMemInactive = 0;
     u_int cPagesMemCached = 0;
     u_int cPagesMemUsed = 0;
     int cbPage = 0;
-    size_t cbParameter = sizeof(cbMemPhys);
-    int cProcessed = 0;
-
-    if (!sysctlbyname("hw.physmem", &cbMemPhys, &cbParameter, NULL, 0))
-        cProcessed++;
+    size_t cbParameter;
 
+    cbParameter = sizeof(cbMemPhys);
+    if (sysctlbyname("hw.physmem", &cbMemPhys, &cbParameter, NULL, 0))
+        return VERR_NOT_SUPPORTED;
     cbParameter = sizeof(cPagesMemFree);
-    if (!sysctlbyname("vm.stats.vm.v_free_count", &cPagesMemFree, &cbParameter, NULL, 0))
-        cProcessed++;
+    if (sysctlbyname("vm.stats.vm.v_free_count", &cPagesMemFree, &cbParameter, NULL, 0))
+        return VERR_NOT_SUPPORTED;
     cbParameter = sizeof(cPagesMemUsed);
-    if (!sysctlbyname("vm.stats.vm.v_active_count", &cPagesMemUsed, &cbParameter, NULL, 0))
-        cProcessed++;
-    cbParameter = sizeof(cPagesMemInactive);
-    if (!sysctlbyname("vm.stats.vm.v_inactive_count", &cPagesMemInactive, &cbParameter, NULL, 0))
-        cProcessed++;
+    if (sysctlbyname("vm.stats.vm.v_active_count", &cPagesMemUsed, &cbParameter, NULL, 0))
+        return VERR_NOT_SUPPORTED;
+#if __FreeBSD_version < 1200016
     cbParameter = sizeof(cPagesMemCached);
-    if (!sysctlbyname("vm.stats.vm.v_cache_count", &cPagesMemCached, &cbParameter, NULL, 0))
-        cProcessed++;
+    if (sysctlbyname("vm.stats.vm.v_cache_count", &cPagesMemCached, &cbParameter, NULL, 0))
+        return VERR_NOT_SUPPORTED;
+#endif
     cbParameter = sizeof(cbPage);
-    if (!sysctlbyname("hw.pagesize", &cbPage, &cbParameter, NULL, 0))
-        cProcessed++;
+    if (sysctlbyname("hw.pagesize", &cbPage, &cbParameter, NULL, 0))
+        return VERR_NOT_SUPPORTED;
 
-    if (cProcessed == 6)
-    {
-        *total     = cbMemPhys / _1K;
-        *used      = cPagesMemUsed * (cbPage / _1K);
-        *available = (cPagesMemFree + cPagesMemInactive + cPagesMemCached ) * (cbPage / _1K);
-    }
-    else
-        rc = VERR_NOT_SUPPORTED;
+    *total     = cbMemPhys / _1K;
+    *used      = (ULONG64)cPagesMemUsed * (cbPage / _1K);
+    *available = ((ULONG64)cPagesMemFree + cPagesMemCached) * (cbPage / _1K);
 
-    return rc;
+    return VINF_SUCCESS;
 }
 
 int CollectorFreeBSD::getProcessCpuLoad(RTPROCESS process, ULONG *user, ULONG *kernel)
