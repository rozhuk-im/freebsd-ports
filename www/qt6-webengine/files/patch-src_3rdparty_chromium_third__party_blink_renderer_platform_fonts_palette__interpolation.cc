--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/palette_interpolation.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/palette_interpolation.cc
@@ -31,7 +31,12 @@ Vector<FontPalette::FontPaletteOverride> PaletteInterp
         color_interpolation_space, hue_interpolation_method, start_color,
         end_color, percentage, alpha_multiplier);
 
-    FontPalette::FontPaletteOverride result_color_record{(int)i, result_color};
+#if defined(__clang__) && (__clang_major__ >= 16)
+    FontPalette::FontPaletteOverride result_color_record(i, result_color);
+#else
+    FontPalette::FontPaletteOverride fpo = { static_cast<int>(i), result_color };
+    FontPalette::FontPaletteOverride result_color_record(fpo);
+#endif
     result_color_records.push_back(result_color_record);
   }
   return result_color_records;
