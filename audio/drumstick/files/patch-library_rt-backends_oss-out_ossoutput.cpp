--- library/rt-backends/oss-out/ossoutput.cpp
+++ library/rt-backends/oss-out/ossoutput.cpp
@@ -53,9 +53,9 @@
         QDir dir("/dev");
         QStringList filters;
         m_advanced = advanced;
-        filters << "dmmidi*" << "admmidi*";
+        filters << "midi*" << "umidi*";
         if (advanced) {
-            filters << "midi*" << "amidi*";
+            filters << "amidi*" << "admmidi*" << "dmmidi*";
         }
         dir.setNameFilters(filters);
         dir.setFilter(QDir::System);
