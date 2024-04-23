--- src/cairo-xlib-display.c
+++ src/cairo-xlib-display.c
@@ -213,6 +213,7 @@
 	goto UNLOCK;
     }
 
+    memset (display, 0, sizeof (cairo_xlib_display_t));
     _cairo_device_init (&display->base, &_cairo_xlib_device_backend);
 
     display->display = dpy;
