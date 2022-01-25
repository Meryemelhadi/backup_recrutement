<?php $properties["query"]="INSERT INTO _rct_channel(_oid,_name,_to_email) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("to_email","DB","NULL").")"; ?>