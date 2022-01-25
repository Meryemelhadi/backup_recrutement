<?php $properties["query"]="INSERT INTO _rct_app_connected(_oid,_name,_url,_identifiant,_key,_app_credits,_compagnie_name,_description,_contact_email,_logo,_banner_background_image,_login,_password,_active_app,_comment,_data_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("identifiant","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("app_credits","DB","NULL").",".
$record->getFieldValue("compagnie_name","DB","NULL").",".
$record->getFieldValue("description","DB","NULL").",".
$record->getFieldValue("contact_email","DB","NULL").",".
$record->getFieldValue("logo","DB","NULL").",".
$record->getFieldValue("banner_background_image","DB","NULL").",".
$record->getFieldValue("login","DB","NULL").",".
$record->getFieldValue("password","DB","NULL").",".
$record->getFieldValue("active_app","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("data_type","DB","NULL").")"; ?>