<?php $properties["query"]="INSERT INTO _rct_provider(_oid,_name,_code,_contact_name,_email,_web,_color,_adress,_notes) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("contact_name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("web","DB","NULL").",".
$record->getFieldValue("color","DB","NULL").",".
$record->getFieldValue("adress","DB","NULL").",".
$record->getFieldValue("notes","DB","NULL").")"; ?>