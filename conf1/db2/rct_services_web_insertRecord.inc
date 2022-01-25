<?php $properties["query"]="INSERT INTO _rct_services_web(_oid,_name,_url,_key,_login,_password,_active_app,_type,_notification,_comment,_auth_type,_data_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("login","DB","NULL").",".
$record->getFieldValue("password","DB","NULL").",".
$record->getFieldValue("active_app","DB","NULL").",".
$record->getFieldValue("type","DB","NULL").",".
$record->getFieldValue("notification","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("auth_type","DB","2").",".
$record->getFieldValue("data_type","DB","NULL").")"; ?>