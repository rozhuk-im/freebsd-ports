--- src/nvidia/nvidia_os.c.orig	2017-05-01 21:17:21 UTC
+++ src/nvidia/nvidia_os.c
@@ -8,6 +8,7 @@
  * _NVRM_COPYRIGHT_END_
  */
 
+#include "opt_syscons.h"
 #include "nv-misc.h"
 #include "os-interface.h"
 #include "nv.h"
@@ -17,7 +18,9 @@
 #include <sys/fbio.h>
 #include <sys/linker.h>
 #include <sys/timex.h>
+#ifdef DEV_SC
 #include <dev/syscons/syscons.h>
+#endif
 
 // This bootloader metadata interface was added to metadata.h in FreeBSD 10.1
 // with commit 3a7cd99956b1 and FreeBSD 11 with commit d2c99117cd3b.
@@ -800,29 +803,32 @@
         }
     }
 #endif
+
+#ifdef DEV_VT
+	/* TODO */
+#endif
+
+#ifdef DEV_SC
     {
         const sc_softc_t *sc = sc_get_softc(0, SC_KERNEL_CONSOLE);
+        const struct video_info *vi;
 
-        if (sc)
+        if (sc && sc->adp)
         {
-            const video_adapter_t *adp = sc->adp;
+            vi = &sc->adp->va_info;
 
-            if (adp)
+            if (vi && (vi->vi_flags & V_INFO_LINEAR))
             {
-                const struct video_info *vi = &adp->va_info;
-
-                if (vi && (vi->vi_flags & V_INFO_LINEAR))
-                {
-                    *pPhysicalAddress = vi->vi_buffer;
-                    *pFbWidth = vi->vi_width;
-                    *pFbHeight = vi->vi_height;
-                    *pFbDepth = vi->vi_depth;
-                    *pFbPitch = adp->va_line_width;
-                    return;
-                }
+                *pPhysicalAddress = vi->vi_buffer;
+                *pFbWidth = vi->vi_width;
+                *pFbHeight = vi->vi_height;
+                *pFbDepth = vi->vi_depth;
+                *pFbPitch = sc->adp->va_line_width;
+                return;
             }
         }
     }
+#endif
 
     *pPhysicalAddress = 0;
     *pFbWidth = *pFbHeight = *pFbDepth = *pFbPitch = 0;
