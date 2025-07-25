--- src/3rdparty/chromium/chrome/browser/ui/webui/settings/appearance_handler.cc.orig	2024-08-26 12:06:38 UTC
+++ src/3rdparty/chromium/chrome/browser/ui/webui/settings/appearance_handler.cc
@@ -34,7 +34,7 @@ void AppearanceHandler::RegisterMessages() {
       "useDefaultTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
                           base::Unretained(this), ui::SystemTheme::kDefault));
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_ui()->RegisterMessageCallback(
       "useGtkTheme",
       base::BindRepeating(&AppearanceHandler::HandleUseTheme,
