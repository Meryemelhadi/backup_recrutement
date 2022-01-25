<?php $properties["query"]="INSERT INTO _rct_services_web(_oid,_name,_url,_key,_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("type","DB","NULL").")"; ?>