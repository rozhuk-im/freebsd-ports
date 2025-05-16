--- src/elf/needed_libc.rs.orig	2025-02-22 01:43:36 UTC
+++ src/elf/needed_libc.rs
@@ -237,8 +237,8 @@ impl NeededLibC {
 }
 
 // If this changes, then update the command line reference.
-static KNOWN_PREFIXES: &[&str] = &["", "usr"];
-static KNOWN_LIB_DIRS: &[&str] = &["lib", "lib64", "lib32"];
+static KNOWN_PREFIXES: &[&str] = &["", "usr", "usr/local"];
+static KNOWN_LIB_DIRS: &[&str] = &["lib", "lib32"];
 
 static KNOWN_LIBC_PATTERN: once_cell::sync::Lazy<Regex> = once_cell::sync::Lazy::new(|| {
     RegexBuilder::new(r"\blib(c|bionic)\b[^/]+$")
