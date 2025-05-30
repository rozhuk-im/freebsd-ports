diff --git src/zig/samples.zig src/zig/samples.zig
index cb05a1f2..ccd5b149 100644
--- src/zig/samples.zig
+++ src/zig/samples.zig
@@ -28,7 +28,11 @@ const GENOTYPE_MISSING = -256;
 fn split_samples(str: []const u8) *ArrayList([] const u8) {
     var list = ArrayList([] const u8).init(allocator);
     defer list.deinit();
-    var splits = std.mem.split(u8, str, " ");
+    
+    var splits = if (@hasDecl(std.mem, "splitScalar"))
+        std.mem.splitScalar(u8, str, ' ')
+    else
+        std.mem.split(u8, str, ' ');
     while (splits.next()) |chunk| {
         list.append(chunk) catch |err| {
             std.debug.print("out of memory {}\n", .{err});
@@ -61,10 +65,10 @@ const Genotypes = struct {
     fn to_num(str: []const u8) !ArrayList(i64) {
         var list = ArrayList(i64).init(allocator);
 
-        var splits = if (is_phased(str)) 
-            std.mem.split(u8, str, "|")
+        var splits =  if (@hasDecl(std.mem, "splitScalar"))
+            std.mem.splitScalar(u8, str, if (is_phased(str)) '|' else '/')
         else
-            std.mem.split(u8, str, "/");
+            std.mem.split(u8, str, if (is_phased(str)) '|' else '/' );
 
         while (splits.next()) |chunk| {
             const i: i64 = 
