<?php $properties["query"]="INSERT INTO _rct_email_attached_file(_email_oid,_file_name) VALUES('".$props->getProperty("object_oid","",true)."',".
"'".$props->getProperty("file_name","",true)."')"; ?>