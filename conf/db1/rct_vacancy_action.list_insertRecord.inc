<?php $properties["query"]="INSERT INTO _rct_vacancy_action(_oid,_name,_number,_code,_category_oid,_contract_type_oid,_subsidiary_oid,_service_oid,_duty_station_oid,_current_step,_progress_level,_application_type,_opening_date,_closing_date,_creator) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("closing_date","DB","NOW()").",".
$record->getFieldValue("creator","DB","NULL").")"; ?>