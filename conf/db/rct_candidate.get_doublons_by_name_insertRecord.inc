<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_cv_path,_phone_1,_email,_etat_oid,_creation_date,_add_date,_update_date,_provider,_hr_manager) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("add_date","DB","NOW()").",".
$record->getFieldValue("update_date","DB","NOW()").",".
$record->getFieldValue("provider","DB","NULL").",".
$record->getFieldValue("hr_manager","DB","NULL").")"; ?>