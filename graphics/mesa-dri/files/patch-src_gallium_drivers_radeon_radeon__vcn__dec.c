--- src/gallium/drivers/radeon/radeon_vcn_dec.c	2019-01-17 14:26:22.000000000 +0300
+++ src/gallium/drivers/radeon/radeon_vcn_dec.c	2020-04-23 18:19:49.324669000 +0300
@@ -1401,7 +1401,7 @@
    msg_fb_it_probs_buf = &dec->msg_fb_it_probs_buffers[dec->cur_buffer];
    bs_buf = &dec->bs_buffers[dec->cur_buffer];
 
-   memset(dec->bs_ptr, 0, align(dec->bs_size, 128) - dec->bs_size);
+   memset(dec->bs_ptr, 0, dec->bs_size);
    dec->ws->buffer_unmap(bs_buf->res->buf);
    dec->bs_ptr = NULL;
 
