<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_oid,_name,_number,_cand_channel,_category_oid,_contract_type_oid,_mission_start_date,_suited_recruitment_date,_duty_station_oid,_service_oid,_establishment,_subsidiary_oid,_work_schedule,_years_of_practice,_suited_diplomas,_companies_having_same_profile,_recruitment_reasons,_technical_qualifications,_behavioral_qualifications,_mission_definitions,_mission_means,_workflow_state,_request_date,_requested_by,_client_oid,_archive_state,_manager_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","1").",".
$record->getFieldValue("cand_channel","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("mission_start_date","DB","NOW()").",".
$record->getFieldValue("suited_recruitment_date","DB","NOW()").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("work_schedule","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("suited_diplomas","DB","NULL").",".
$record->getFieldValue("companies_having_same_profile","DB","NULL").",".
$record->getFieldValue("recruitment_reasons","DB","NULL").",".
$record->getFieldValue("technical_qualifications","DB","NULL").",".
$record->getFieldValue("behavioral_qualifications","DB","NULL").",".
$record->getFieldValue("mission_definitions","DB","NULL").",".
$record->getFieldValue("mission_means","DB","NULL").",".
"'1',".
"NOW(),".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"'0',".
$record->getFieldValue("manager_oid","DB","NULL").")"; ?>