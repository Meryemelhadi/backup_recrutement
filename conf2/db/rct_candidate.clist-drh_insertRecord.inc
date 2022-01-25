<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_email,_cv_path) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").")"; ?>