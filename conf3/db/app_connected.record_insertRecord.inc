<?php $properties["query"]="INSERT INTO _rct_app_connected(_oid,_name,_url,_key,_login,_password,_active_app,_data_type,_comment,_compagnie_name,_description,_contact_email,_logo,_banner_background_image) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("login","DB","NULL").",".
$record->getFieldValue("password","DB","NULL").",".
$record->getFieldValue("active_app","DB","NULL").",".
$record->getFieldValue("data_type","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("compagnie_name","DB","NULL").",".
$record->getFieldValue("description","DB","NULL").",".
$record->getFieldValue("contact_email","DB","NULL").",".
$record->getFieldValue("logo","DB","NULL").",".
$record->getFieldValue("banner_background_image","DB","NULL").")"; ?>