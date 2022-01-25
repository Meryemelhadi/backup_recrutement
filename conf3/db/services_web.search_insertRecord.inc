<?php $properties["query"]="INSERT INTO _rct_services_web(_name,_url,_key) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").")"; ?>