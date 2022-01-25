<?php $properties["query"]="INSERT INTO _rct_channel(_oid,_name,_to_email,_establishment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("to_email","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").")"; ?>