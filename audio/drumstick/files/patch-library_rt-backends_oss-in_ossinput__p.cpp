--- library/rt-backends/oss-in/ossinput_p.cpp
+++ library/rt-backends/oss-in/ossinput_p.cpp
@@ -43,9 +43,9 @@
     QDir dir("/dev");
     QStringList filters;
     m_advanced = advanced;
-    filters << "dmmidi*" << "admmidi*";
+    filters << "midi*" << "umidi*";
     if (advanced) {
-        filters << "midi*" << "amidi*";
+        filters << "amidi*" << "admmidi*" << "dmmidi*";
     }
     dir.setNameFilters(filters);
     dir.setFilter(QDir::System);
