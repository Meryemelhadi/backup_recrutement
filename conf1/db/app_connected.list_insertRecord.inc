<?php $properties["query"]="INSERT INTO _rct_app_connected(_oid,_name,_url,_key,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>