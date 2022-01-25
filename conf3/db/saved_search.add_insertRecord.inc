<?php $properties["query"]="INSERT INTO _rct_saved_search(_oid,_name,_url,_user_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."')"; ?>