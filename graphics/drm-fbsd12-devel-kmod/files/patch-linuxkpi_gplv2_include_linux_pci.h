--- linuxkpi/gplv2/include/linux/pci.h	2020-01-15 12:22:44.000000000 +0300
+++ linuxkpi/gplv2/include/linux/pci.h	2020-08-26 06:12:45.751666000 +0300
@@ -172,6 +172,7 @@
 	return 128 << ((ctl & PCI_EXP_DEVCTL_READRQ) >> 12);
 }
 
+#if __FreeBSD_version < 1201523
 static inline void *
 pci_iomap(struct pci_dev *dev, int bar, unsigned long maxlen)
 {
@@ -184,5 +185,6 @@
 {
 	/* NOP */
 }
+#endif
 
 #endif /* _LINUX_GPLV2_PCI_H_ */
