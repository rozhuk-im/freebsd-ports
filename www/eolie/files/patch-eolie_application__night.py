--- eolie/application_night.py.orig	2020-10-25 00:27:38.091392000 +0300
+++ eolie/application_night.py	2020-12-01 06:06:35.982844000 +0300
@@ -30,8 +30,7 @@
                                   self.__on_night_mode_changed)
             Gio.bus_get(Gio.BusType.SESSION, None, self.__on_get_bus)
             self.__wanted_temperature = None
-            settings = Gio.Settings.new(
-                "org.gnome.settings-daemon.plugins.color")
+            settings = None
             self.__wanted_temperature = settings.get_value(
                 "night-light-temperature").get_uint32()
         except Exception as e:
