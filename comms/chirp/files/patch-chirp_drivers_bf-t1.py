--- chirp/drivers/bf-t1.py	2019-03-04 11:00:22.000000000 +0300
+++ chirp/drivers/bf-t1.py	2020-02-15 04:07:28.908906000 +0300
@@ -1,4 +1,5 @@
 # Copyright 2017 Pavel Milanes, CO7WT, <pavelmc@gmail.com>
+# Copyright 2020 Rozhuk Ivan <rozhuk.im@gmail.com>
 #
 # This driver is a community effort as I don't have the radio on my hands, so
 # I was only the director of the orchestra, without the players this may never
@@ -25,7 +26,11 @@
 # You should have received a copy of the GNU General Public License
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
-from time import sleep
+import time
+import struct
+import logging
+
+from chirp.drivers import baofeng_common
 from chirp import chirp_common, directory, memmap
 from chirp import bitwise, errors, util
 from chirp.settings import RadioSetting, RadioSettingGroup, \
@@ -34,8 +39,6 @@
                 RadioSettingValueFloat, RadioSettings
 from textwrap import dedent
 
-import struct
-import logging
 
 LOG = logging.getLogger(__name__)
 
@@ -73,10 +76,6 @@
 BACKLIGHT_LIST = ["Off", "Key", "On"]
 POWER_LIST = ["0.5 Watt", "1.0 Watt"]
 
-# This is a general serial timeout for all serial read functions.
-# Practice has show that about 0.07 sec will be enough to cover all radios.
-STIMEOUT = 0.07
-
 # this var controls the verbosity in the debug and by default it's low (False)
 # make it True and you will to get a very verbose debug.log
 debug = False
@@ -86,293 +85,13 @@
 # BF-T1 handheld
 BFT1_magic = "\x05PROGRAM"
 BFT1_ident = " BF9100S"
+BFT1_ident_offset = 0x06f8
 
-
-def _clean_buffer(radio):
-    """Cleaning the read serial buffer, hard timeout to survive an infinite
-    data stream"""
-
-    dump = "1"
-    datacount = 0
-
-    try:
-        while len(dump) > 0:
-            dump = radio.pipe.read(100)
-            datacount += len(dump)
-            # hard limit to survive a infinite serial data stream
-            # 5 times bigger than a normal rx block (20 bytes)
-            if datacount > 101:
-                seriale = "Please check your serial port selection."
-                raise errors.RadioError(seriale)
-
-    except Exception:
-        raise errors.RadioError("Unknown error cleaning the serial buffer")
-
-
-def _rawrecv(radio, amount=0):
-    """Raw read from the radio device"""
-
-    # var to hold the data to return
-    data = ""
-
-    try:
-        if amount == 0:
-            data = radio.pipe.read()
-        else:
-            data = radio.pipe.read(amount)
-
-        # DEBUG
-        if debug is True:
-            LOG.debug("<== (%d) bytes:\n\n%s" %
-                      (len(data), util.hexprint(data)))
-
-        # fail if no data is received
-        if len(data) == 0:
-            raise errors.RadioError("No data received from radio")
-
-    except:
-        raise errors.RadioError("Error reading data from radio")
-
-    return data
-
-
-def _send(radio, data):
-    """Send data to the radio device"""
-
-    try:
-        radio.pipe.write(data)
-
-        # DEBUG
-        if debug is True:
-            LOG.debug("==> (%d) bytes:\n\n%s" %
-                      (len(data), util.hexprint(data)))
-    except:
-        raise errors.RadioError("Error sending data to radio")
-
-
-def _make_frame(cmd, addr, data=""):
-    """Pack the info in the header format"""
-    frame = struct.pack(">BHB", ord(cmd), addr, BLOCK_SIZE)
-
-    # add the data if set
-    if len(data) != 0:
-        frame += data
-
-    return frame
-
-
-def _recv(radio, addr):
-    """Get data from the radio"""
-
-    # Get the full 20 bytes at a time
-    # 4 bytes header + 16 bytes of data (BLOCK_SIZE)
-
-    # get the whole block
-    block = _rawrecv(radio, BLOCK_SIZE + 4)
-
-    # short answer
-    if len(block) < (BLOCK_SIZE + 4):
-        raise errors.RadioError("Wrong block length (short) at 0x%04x" % addr)
-
-    # long answer
-    if len(block) > (BLOCK_SIZE + 4):
-        raise errors.RadioError("Wrong block length (long) at 0x%04x" % addr)
-
-    # header validation
-    c, a, l = struct.unpack(">cHB", block[0:4])
-    if c != "W" or a != addr or l != BLOCK_SIZE:
-        LOG.debug("Invalid header for block 0x%04x:" % addr)
-        LOG.debug("CMD: %s  ADDR: %04x  SIZE: %02x" % (c, a, l))
-        raise errors.RadioError("Invalid header for block 0x%04x:" % addr)
-
-    # return the data, 16 bytes of payload
-    return block[4:]
-
-
-def _start_clone_mode(radio, status):
-    """Put the radio in clone mode, 3 tries"""
-
-    # cleaning the serial buffer
-    _clean_buffer(radio)
-
-    # prep the data to show in the UI
-    status.cur = 0
-    status.msg = "Identifying the radio..."
-    status.max = 3
-    radio.status_fn(status)
-
-    try:
-        for a in range(0, status.max):
-            # Update the UI
-            status.cur = a + 1
-            radio.status_fn(status)
-
-            # send the magic word
-            _send(radio, radio._magic)
-
-            # Now you get a x06 of ACK if all goes well
-            ack = _rawrecv(radio, 1)
-
-            if ack == ACK_CMD:
-                # DEBUG
-                LOG.info("Magic ACK received")
-                status.cur = status.max
-                radio.status_fn(status)
-
-                return True
-
-        return False
-
-    except errors.RadioError:
-        raise
-    except Exception, e:
-        raise errors.RadioError("Error sending Magic to radio:\n%s" % e)
-
-
-def _do_ident(radio, status):
-    """Put the radio in PROGRAM mode & identify it"""
-    #  set the serial discipline (default)
-    radio.pipe.baudrate = 9600
-    radio.pipe.parity = "N"
-    radio.pipe.bytesize = 8
-    radio.pipe.stopbits = 1
-    radio.pipe.timeout = STIMEOUT
-
-    # open the radio into program mode
-    if _start_clone_mode(radio, status) is False:
-        raise errors.RadioError("Radio did not enter clone mode, wrong model?")
-
-    # Ok, poke it to get the ident string
-    _send(radio, "\x02")
-    ident = _rawrecv(radio, len(radio._id))
-
-    # basic check for the ident
-    if len(ident) != len(radio._id):
-        raise errors.RadioError("Radio send a odd identification block.")
-
-    # check if ident is OK
-    if ident != radio._id:
-        LOG.debug("Incorrect model ID, got this:\n\n" + util.hexprint(ident))
-        raise errors.RadioError("Radio identification failed.")
-
-    # handshake
-    _send(radio, ACK_CMD)
-    ack = _rawrecv(radio, 1)
-
-    # checking handshake
-    if len(ack) == 1 and ack == ACK_CMD:
-        # DEBUG
-        LOG.info("ID ACK received")
-    else:
-        LOG.debug("Radio handshake failed.")
-        raise errors.RadioError("Radio handshake failed.")
-
-    # DEBUG
-    LOG.info("Positive ident, this is a %s %s" % (radio.VENDOR, radio.MODEL))
-
-    return True
-
-
-def _download(radio):
-    """Get the memory map"""
-
-    # UI progress
-    status = chirp_common.Status()
-
-    # put radio in program mode and identify it
-    _do_ident(radio, status)
-
-    # reset the progress bar in the UI
-    status.max = MEM_SIZE / BLOCK_SIZE
-    status.msg = "Cloning from radio..."
-    status.cur = 0
-    radio.status_fn(status)
-
-    # cleaning the serial buffer
-    _clean_buffer(radio)
-
-    data = ""
-    for addr in range(0, MEM_SIZE, BLOCK_SIZE):
-        # sending the read request
-        _send(radio, _make_frame("R", addr))
-
-        # read
-        d = _recv(radio, addr)
-
-        # aggregate the data
-        data += d
-
-        # UI Update
-        status.cur = addr / BLOCK_SIZE
-        status.msg = "Cloning from radio..."
-        radio.status_fn(status)
-
-    # close comms with the radio
-    _send(radio, "\x62")
-    # DEBUG
-    LOG.info("Close comms cmd sent, radio must reboot now.")
-
-    return data
-
-
-def _upload(radio):
-    """Upload procedure, we only upload to the radio the Writable space"""
-
-    # UI progress
-    status = chirp_common.Status()
-
-    # put radio in program mode and identify it
-    _do_ident(radio, status)
-
-    # get the data to upload to radio
-    data = radio.get_mmap()
-
-    # Reset the UI progress
-    status.max = WRITE_SIZE / BLOCK_SIZE
-    status.cur = 0
-    status.msg = "Cloning to radio..."
-    radio.status_fn(status)
-
-    # cleaning the serial buffer
-    _clean_buffer(radio)
-
-    # the fun start here, we use WRITE_SIZE instead of the full MEM_SIZE
-    for addr in range(0, WRITE_SIZE, BLOCK_SIZE):
-        # getting the block of data to send
-        d = data[addr:addr + BLOCK_SIZE]
-
-        # build the frame to send
-        frame = _make_frame("W", addr, d)
-
-        # send the frame
-        _send(radio, frame)
-
-        # receiving the response
-        ack = _rawrecv(radio, 1)
-
-        # basic check
-        if len(ack) != 1:
-            raise errors.RadioError("No ACK when writing block 0x%04x" % addr)
-
-        if ack != ACK_CMD:
-            raise errors.RadioError("Bad ACK writing block 0x%04x:" % addr)
-
-        # UI Update
-        status.cur = addr / BLOCK_SIZE
-        status.msg = "Cloning to radio..."
-        radio.status_fn(status)
-
-    # close comms with the radio
-    _send(radio, "\x62")
-    # DEBUG
-    LOG.info("Close comms cmd sent, radio must reboot now.")
-
-
 def _model_match(cls, data):
     """Match the opened/downloaded image to the correct version"""
 
     # a reliable fingerprint: the model name at
-    rid = data[0x06f8:0x0700]
+    rid = data[BFT1_ident_offset:BFT1_ident_offset + len(BFT1_ident)]
 
     if rid == BFT1_ident:
         return True
@@ -456,16 +175,29 @@
 
 
 @directory.register
-class BFT1(chirp_common.CloneModeRadio, chirp_common.ExperimentalRadio):
+class BFT1(baofeng_common.BaofengCommonHT):
     """Baofeng BT-F1 radio & possibly alike radios"""
     VENDOR = "Baofeng"
     MODEL = "BF-T1"
     _vhf_range = (130000000, 174000000)
     _uhf_range = (400000000, 520000000)
     _upper = 20
-    _magic = BFT1_magic
-    _id = BFT1_ident
 
+    _fileid = []
+    _magic = ["\x05PROGRAM", ]
+    _magic_response = BFT1_ident
+    _magic_response_length = len(BFT1_ident)
+    _fw_ver_start = BFT1_ident_offset
+    _recv_block_size = BLOCK_SIZE
+    _mem_size = MEM_SIZE
+    _ack_block = False
+
+    _ranges = [(0x0000, WRITE_SIZE)]
+    _send_block_size = BLOCK_SIZE
+
+    _read_cmd = "R"
+    _write_cmd = "W"
+
     @classmethod
     def get_prompts(cls):
         rp = chirp_common.RadioPrompts()
@@ -547,22 +279,6 @@
         settings = self._memobj.settings
         self._vhf_range = _decode_ranges(settings.vhfl, settings.vhfh)
         self._uhf_range = _decode_ranges(settings.uhfl, settings.uhfh)
-
-    def sync_in(self):
-        """Download from radio"""
-        data = _download(self)
-        self._mmap = memmap.MemoryMap(data)
-        self.process_mmap()
-
-    def sync_out(self):
-        """Upload to radio"""
-
-        try:
-            _upload(self)
-        except errors.RadioError:
-            raise
-        except Exception, e:
-            raise errors.RadioError("Error: %s" % e)
 
     def _decode_tone(self, val, inv):
         """Parse the tone data to decode from mem, it returns:
