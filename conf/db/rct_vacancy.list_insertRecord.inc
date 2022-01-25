<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_key,_key,_manager_oid,_name,_number,_code,_category_oid,_contract_type_oid,_subsidiary_oid,_establishment,_service_oid,_duty_station_oid,_current_step,_progress_level,_application_type,_vacancy_project,_opening_date,_closing_date,_creator,_email) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","1").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("application_type","DB","0").",".
$record->getFieldValue("vacancy_project","DB","0").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("closing_date","DB","NOW()").",".
$record->getFieldValue("creator","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").")"; ?>