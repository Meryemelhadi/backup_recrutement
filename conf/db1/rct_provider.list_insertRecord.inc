<?php $properties["query"]="INSERT INTO _rct_provider(_oid,_name,_email,_contact_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("contact_name","DB","NULL").")"; ?>