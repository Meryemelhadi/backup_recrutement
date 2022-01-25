<?php $properties["query"]="INSERT INTO _rct_vacancy_action(_name,_number,_category_oid,_contract_type_oid,_mission_start_date,_suited_recruitment_date,_taking_office_date,_code,_manager_oid,_client_oid,_current_step,_progress_level,_closing_date,_opening_date,_duty_station_oid,_service_oid,_subsidiary_oid,_workflow_state,_internship_title,_internship_start,_internship_end,_archive_state,_creator,_groups_user) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","1").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("mission_start_date","DB","NOW()").",".
$record->getFieldValue("suited_recruitment_date","DB","NOW()").",".
$record->getFieldValue("taking_office_date","DB","NOW()").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("client_oid","DB","NULL").",".
$record->getFieldValue("current_step","DB","0").",".
"'0',".
$record->getFieldValue("closing_date","DB","NOW()").",".
"NOW(),".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
"'2',".
$record->getFieldValue("internship_title","DB","NULL").",".
$record->getFieldValue("internship_start","DB","NOW()").",".
$record->getFieldValue("internship_end","DB","NOW()").",".
"'0',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)." show=',".
$record->getFieldValue("groups_user","DB","NULL").")"; ?>