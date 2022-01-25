<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_civility,_gender,_date_of_birth,_nationality,_email,_phone_1,_phone_2,_mobile,_address,_zip,_country_oid,_town_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("civility","DB","NULL").",".
$record->getFieldValue("gender","DB","NULL").",".
$record->getFieldValue("date_of_birth","DB","NOW()").",".
$record->getFieldValue("nationality","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("phone_2","DB","NULL").",".
$record->getFieldValue("mobile","DB","NULL").",".
$record->getFieldValue("address","DB","NULL").",".
$record->getFieldValue("zip","DB","NULL").",".
$record->getFieldValue("country_oid","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").")"; ?>