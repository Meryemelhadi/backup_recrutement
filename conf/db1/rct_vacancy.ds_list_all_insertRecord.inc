<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_name,_code) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").")"; ?>