--- chirp/drivers/baofeng_common.py	2019-03-02 11:00:23.000000000 +0300
+++ chirp/drivers/baofeng_common.py	2020-02-15 14:11:38.778942000 +0300
@@ -84,7 +84,7 @@
     LOG.debug(util.hexprint(hdr + data))
 
     c, a, l = struct.unpack(">BHB", hdr)
-    if a != addr or l != length or c != ord("X"):
+    if a != addr or l != length or c != ord(radio._write_cmd):
         LOG.error("Invalid answer for block 0x%04x:" % addr)
         LOG.debug("CMD: %s  ADDR: %04x  SIZE: %02x" % (c, a, l))
         raise errors.RadioError("Unknown response from the radio")
@@ -92,17 +92,45 @@
     return data
 
 
-def _get_radio_firmware_version(radio):
-    msg = struct.pack(">BHB", ord("S"), radio._fw_ver_start,
-                      radio._recv_block_size)
-    radio.pipe.write(msg)
-    block = _recv(radio, radio._fw_ver_start, radio._recv_block_size)
+def _read_block(radio, addr):
+    """Read data block from the radio, addr must be aligned
+       to _recv_block_size """
+
+    frame = _make_frame(radio._read_cmd, addr, radio._recv_block_size)
+    # DEBUG
+    LOG.info("Request sent:")
+    LOG.debug(util.hexprint(frame))
+
+    # sending the read request
+    _rawsend(radio, frame)
+
+    if radio._ack_block:
+        ack = _rawrecv(radio, 1)
+        if ack != "\x06":
+            raise errors.RadioError(
+                "Radio refused to send block 0x%04x" % addr)
+
+    # now we read
+    data = _recv(radio, addr, radio._recv_block_size)
+
     _rawsend(radio, "\x06")
     time.sleep(0.05)
-    version = block[0:16]
-    return version
 
+    return data
 
+
+def _get_radio_firmware_version(radio):
+    offset = radio._fw_ver_start % radio._recv_block_size
+    start = radio._fw_ver_start - offset
+    end = radio._fw_ver_start + offset + 16
+    data = ""
+    for addr in range(start, end, radio._recv_block_size):
+        # aggregate the data
+        data += _read_block(radio, addr)
+
+    return data[offset:offset + 16]
+
+
 def _image_ident_from_data(data, start, stop):
     return data[start:stop]
 
@@ -137,7 +165,8 @@
     ident = _rawrecv(radio, radio._magic_response_length)
 
     # check if response is OK
-    if not ident.startswith("\xaa") or not ident.endswith("\xdd"):
+    if ident != radio._magic_response and \
+       (not ident.startswith("\xaa") or not ident.endswith("\xdd")):
         # bad response
         msg = "Unexpected response, got this:"
         msg +=  util.hexprint(ident)
@@ -202,32 +231,11 @@
 
     data = ""
     for addr in range(0, radio._mem_size, radio._recv_block_size):
-        frame = _make_frame("S", addr, radio._recv_block_size)
-        # DEBUG
-        LOG.info("Request sent:")
-        LOG.debug(util.hexprint(frame))
-
-        # sending the read request
-        _rawsend(radio, frame)
-
-        if radio._ack_block:
-            ack = _rawrecv(radio, 1)
-            if ack != "\x06":
-                raise errors.RadioError(
-                    "Radio refused to send block 0x%04x" % addr)
-
-        # now we read
-        d = _recv(radio, addr, radio._recv_block_size)
-
-        _rawsend(radio, "\x06")
-        time.sleep(0.05)
-
         # aggregate the data
-        data += d
+        data += _read_block(radio, addr)
 
         # UI Update
         status.cur = addr / radio._recv_block_size
-        status.msg = "Cloning from radio..."
         radio.status_fn(status)
 
     data += ident
@@ -276,7 +284,8 @@
             # sending the data
             data = radio.get_mmap()[addr:addr + radio._send_block_size]
 
-            frame = _make_frame("X", addr, radio._send_block_size, data)
+            frame = _make_frame(radio._write_cmd, addr,
+                                radio._send_block_size, data)
 
             _rawsend(radio, frame)
             time.sleep(0.05)
@@ -289,7 +298,6 @@
 
             # UI Update
             status.cur = addr / radio._send_block_size
-            status.msg = "Cloning to radio..."
             radio.status_fn(status)
 
 
@@ -313,6 +321,9 @@
     VENDOR = "Baofeng"
     MODEL = ""
     IDENT = ""
+
+    _read_cmd = "S"
+    _write_cmd = "X"
 
     def sync_in(self):
         """Download from radio"""
