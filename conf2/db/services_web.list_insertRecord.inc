<?php $properties["query"]="INSERT INTO _rct_services_web(_oid,_name,_url,_key,_comment,_auth_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("auth_type","DB","2").")"; ?>