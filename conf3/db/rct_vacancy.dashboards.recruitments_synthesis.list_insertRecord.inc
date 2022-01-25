<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_name,_number,_service_name,_years_of_practice,_suited_diplomas,_mission_start_date,_application_type,_providers,_current_step,_nb_candidates,_manager_oid,_progress_level) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","NULL").",".
$record->getFieldValue("service_name","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("suited_diplomas","DB","NULL").",".
$record->getFieldValue("mission_start_date","DB","NOW()").",".
$record->getFieldValue("application_type","DB","0").",".
$record->getFieldValue("providers","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("nb_candidates","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").")"; ?>