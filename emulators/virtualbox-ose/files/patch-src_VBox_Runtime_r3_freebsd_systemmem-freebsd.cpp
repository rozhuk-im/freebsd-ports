--- src/VBox/Runtime/r3/freebsd/systemmem-freebsd.cpp.orig	2017-07-27 13:18:46 UTC
+++ src/VBox/Runtime/r3/freebsd/systemmem-freebsd.cpp
@@ -63,9 +63,7 @@
 
     int rc = VINF_SUCCESS;
     u_int cPagesMemFree = 0;
-    u_int cPagesMemInactive = 0;
     u_int cPagesMemCached = 0;
-    u_int cPagesMemUsed = 0;
     int cbPage = 0;
     size_t cbParameter;
     int cProcessed = 0;
@@ -73,25 +71,19 @@
     cbParameter = sizeof(cPagesMemFree);
     if (sysctlbyname("vm.stats.vm.v_free_count", &cPagesMemFree, &cbParameter, NULL, 0))
         rc = RTErrConvertFromErrno(errno);
-    cbParameter = sizeof(cPagesMemUsed);
-    if (   RT_SUCCESS(rc)
-        && sysctlbyname("vm.stats.vm.v_active_count", &cPagesMemUsed, &cbParameter, NULL, 0))
-        rc = RTErrConvertFromErrno(errno);
-    cbParameter = sizeof(cPagesMemInactive);
-    if (   RT_SUCCESS(rc)
-        && sysctlbyname("vm.stats.vm.v_inactive_count", &cPagesMemInactive, &cbParameter, NULL, 0))
-        rc = RTErrConvertFromErrno(errno);
+#if __FreeBSD_version < 1200016
     cbParameter = sizeof(cPagesMemCached);
     if (   RT_SUCCESS(rc)
         && sysctlbyname("vm.stats.vm.v_cache_count", &cPagesMemCached, &cbParameter, NULL, 0))
         rc = RTErrConvertFromErrno(errno);
+#endif
     cbParameter = sizeof(cbPage);
     if (   RT_SUCCESS(rc)
         && sysctlbyname("hw.pagesize", &cbPage, &cbParameter, NULL, 0))
         rc = RTErrConvertFromErrno(errno);
 
     if (RT_SUCCESS(rc))
-        *pcb = (cPagesMemFree + cPagesMemInactive + cPagesMemCached ) * cbPage;
+        *pcb = ((uint64_t)cPagesMemFree + cPagesMemCached) * cbPage;
 
     return rc;
 }
