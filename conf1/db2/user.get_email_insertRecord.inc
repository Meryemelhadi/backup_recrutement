<?php $properties["query"]="INSERT INTO _user(_oid,_civility,_first_name,_last_name,_email,_role,_mobile_phone,_direct_phone,_local_phone,_personal_phone,_group,_photo) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("civility","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("role","DB","NULL").",".
$record->getFieldValue("mobile_phone","DB","NULL").",".
$record->getFieldValue("direct_phone","DB","NULL").",".
$record->getFieldValue("local_phone","DB","NULL").",".
$record->getFieldValue("personal_phone","DB","NULL").",".
$record->getFieldValue("group","DB","NULL").",".
$record->getFieldValue("photo","DB","NULL").")"; ?>