--- coregrind/m_debuglog.c.orig	2016-01-13 22:20:20.000000000 +0300
+++ coregrind/m_debuglog.c	2019-03-17 13:06:51.971632000 +0300
@@ -482,8 +482,8 @@ static UInt local_sys_write_stderr ( HChar* buf, Int n
       "popq  %%r15\n"           /* restore r15 */
       "addq  $256, %%rsp\n"     /* restore stack ptr */
       : /*wr*/
-      : /*rd*/    "g" (block)
-      : /*trash*/ "rax", "rdi", "rsi", "rdx", "memory", "cc"
+      : /*rd*/    "r" (block)
+      : /*trash*/ "rax", "rdi", "rsi", "rdx", "memory", "cc", "rcx", "r11"
    );
    if (block[0] < 0) 
       block[0] = -1;
