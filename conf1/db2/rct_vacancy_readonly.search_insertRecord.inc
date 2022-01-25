<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_name,_subsidiary_oid,_current_step,_opening_date,_code,_service_oid,_progress_level,_closing_date,_establishment,_duty_station_oid,_application_type,_contract_type_oid,_category_oid,_archive_state,_vacancy_project,_app_connected) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("closing_date","DB","NOW()").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
"'".$this->getParamValue("archive_state","0","request",",")."',".
$record->getFieldValue("vacancy_project","DB","0").",".
$record->getFieldValue("app_connected","DB","NULL").")"; ?>