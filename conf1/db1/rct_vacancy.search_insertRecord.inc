<?php $properties["query"]="INSERT INTO _rct_vacancy(_name,_subsidiary_oid,_current_step,_opening_date,_code,_service_oid,_progress_level,_closing_date,_category_oid,_duty_station_oid,_application_type,_contract_type_oid,_archive_state) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("closing_date","DB","NOW()").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("application_type","DB","0").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
"'".$this->getParamValue("archive_state","0","request",",")."')"; ?>