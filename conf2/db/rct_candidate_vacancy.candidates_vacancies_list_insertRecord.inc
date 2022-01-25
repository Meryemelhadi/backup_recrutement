<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_manager_oid,_candidate_oid,_name,_number,_code,_category_oid,_contract_type_oid,_subsidiary_oid,_establishment,_service_oid,_duty_station_oid,_current_step,_progress_level,_application_type,_opening_date,_closing_date,_creator,_job_acceptance_state,_status,_is_visible,_ci_acceptance_state,_proposal_acceptance_state,_proposal_acceptance_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
"'1',".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("closing_date","DB","NOW()").",".
$record->getFieldValue("creator","DB","NULL").",".
$record->getFieldValue("job_acceptance_state","DB","0").",".
$record->getFieldValue("status","DB","NULL").",".
$record->getFieldValue("is_visible","DB","0").",".
$record->getFieldValue("ci_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_date","DB","NOW()").")"; ?>