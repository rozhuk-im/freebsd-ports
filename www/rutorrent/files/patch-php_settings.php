--- php/settings.php.orig	2025-06-18 11:47:50 UTC
+++ php/settings.php
@@ -230,7 +230,10 @@ class rTorrentSettings
 					$this->apiVersion = $req->val[0];
 			}
 
-                        $req = new rXMLRPCRequest( new rXMLRPCCommand("to_kb", floatval(1024)) );
+			$req = new rXMLRPCRequest(new rXMLRPCCommand(
+				"convert.kb",
+				$this->iVersion >= 0x1000 ? array('',floatval(1024)) : floatval(1024)
+			));
 			if($req->run())
 			{
 				if(!$req->fault)
@@ -305,7 +308,13 @@ class rTorrentSettings
 	}
 	public function getRatioGroupCommand($ratio,$cmd,$args)
 	{
-		$prefix = ($this->iVersion >= 0x904) && in_array($cmd,$this->ratioCmds) ? "group2." : "group.";
+		if (($this->iVersion >= 0x904) && ($this->iVersion < 0x1000) && in_array($cmd,$this->ratioCmds)) {
+			$prefix = "group2.";
+		} else {
+			$prefix = "group.";
+			if (!is_array($args))
+				$args = array('', $args);
+		}
 		return( new rXMLRPCCommand( $prefix.$ratio.".".$cmd, $args ) );
 	}
 	public function getEventCommand($cmd1,$cmd2,$args)
