--- src/3rdparty/chromium/components/policy/core/common/cloud/cloud_policy_client.cc.orig	2024-10-22 08:31:56 UTC
+++ src/3rdparty/chromium/components/policy/core/common/cloud/cloud_policy_client.cc
@@ -703,7 +703,7 @@ void CloudPolicyClient::FetchPolicy(PolicyFetchReason 
         fetch_request->set_invalidation_payload(invalidation_payload_);
       }
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Only set browser device identifier for CBCM Chrome cloud policy on
     // desktop.
     if (type_to_fetch.first ==
