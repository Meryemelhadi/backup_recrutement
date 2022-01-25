<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_email,_phone_1,_md5_cv_pdf) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("md5_cv_pdf","DB","NULL").")"; ?>