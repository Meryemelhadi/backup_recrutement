<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_name,_email,_phone_1,_phone_2,_mobile,_md5_cv_ori,_md5_cv_pdf) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("phone_2","DB","NULL").",".
$record->getFieldValue("mobile","DB","NULL").",".
$record->getFieldValue("md5_cv_ori","DB","NULL").",".
$record->getFieldValue("md5_cv_pdf","DB","NULL").")"; ?>