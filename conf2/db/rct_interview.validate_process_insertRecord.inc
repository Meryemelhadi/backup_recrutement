<?php $properties["query"]="INSERT INTO _rct_interview(_validation_state,_validated_by) VALUES('".$props->getProperty("validation_state","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."')"; ?>