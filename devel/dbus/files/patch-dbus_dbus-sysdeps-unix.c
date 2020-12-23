--- dbus/dbus-sysdeps-unix.c.bak	2018-08-02 19:13:02.000000000 +0300
+++ dbus/dbus-sysdeps-unix.c	2019-09-13 02:55:41.904210000 +0300
@@ -4479,6 +4479,11 @@
     }
 #endif
 
+#if defined(HAVE_CLOSEFROM) || defined(__FreeBSD__)
+  closefrom(3);
+  return;
+#endif
+
   maxfds = sysconf (_SC_OPEN_MAX);
 
   /* Pick something reasonable if for some reason sysconf says
