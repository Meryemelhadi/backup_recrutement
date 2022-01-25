<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_etat_oid,_phone_1,_mobile,_email,_years_of_practice,_studies_level,_last_employment,_last_employment_start_date,_last_employment_end_date,_last_training,_last_training_start_date,_last_training_end_date,_provider) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("mobile","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("last_employment","DB","NULL").",".
$record->getFieldValue("last_employment_start_date","DB","NOW()").",".
$record->getFieldValue("last_employment_end_date","DB","NOW()").",".
$record->getFieldValue("last_training","DB","NULL").",".
$record->getFieldValue("last_training_start_date","DB","NOW()").",".
$record->getFieldValue("last_training_end_date","DB","NOW()").",".
$record->getFieldValue("provider","DB","NULL").")"; ?>