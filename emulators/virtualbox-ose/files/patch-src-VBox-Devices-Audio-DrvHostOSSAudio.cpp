--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp	2020-07-09 09:52:47.000000000 -0700
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp	2020-07-31 20:50:47.097483000 -0700
@@ -248,11 +248,11 @@ 
                 break;
 
             default:
-                rc = VERR_AUDIO_STREAM_COULD_NOT_CREATE;
+                iFormat = -1;
                 break;
         }
 
-        if (RT_FAILURE(rc))
+        if (RT_UNLIKELY(iFormat == -1))
             break;
 
         if (ioctl(hFile, SNDCTL_DSP_SAMPLESIZE, &iFormat))
@@ -660,6 +660,7 @@ 
 
                 pCfgAcq->Backend.cfPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, ossAcq.cbFragmentSize);
                 pCfgAcq->Backend.cfBufferSize = pCfgAcq->Backend.cfPeriod * 2; /* Use "double buffering". */
+                pCfgAcq->Backend.cfPreBuf     = pCfgAcq->Backend.cfBufferSize;
                 /** @todo Pre-buffering required? */
             }
         }
@@ -778,6 +779,7 @@ 
 #endif
             pCfgAcq->Backend.cfPeriod     = PDMAUDIOSTREAMCFG_B2F(pCfgAcq, obtStream.cbFragmentSize);
             pCfgAcq->Backend.cfBufferSize = pCfgAcq->Backend.cfPeriod * 2; /* Use "double buffering" */
+            pCfgAcq->Backend.cfPreBuf     = pCfgAcq->Backend.cfBufferSize;
         }
 
     } while (0);
