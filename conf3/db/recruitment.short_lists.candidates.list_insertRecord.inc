<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_assoc_oid,_first_name,_last_name,_cv_path,_years_of_practice,_keywords,_rating,_status,_is_visible,_etat_color,_ci_acceptance_state,_job_acceptance_state,_proposal_acceptance_state,_proposal_acceptance_date,_add_date,_studies_level,_creation_date,_update_date,_last_employment_start_date,_last_employment_end_date,_last_employment,_last_training_start_date,_last_training_end_date,_last_training,_relevance,_provider,_profile,_read_state,_user_read_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("assoc_oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("rating","DB","NULL").",".
$record->getFieldValue("status","DB","NULL").",".
$record->getFieldValue("is_visible","DB","0").",".
$record->getFieldValue("etat_color","DB","NULL").",".
$record->getFieldValue("ci_acceptance_state","DB","0").",".
$record->getFieldValue("job_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_date","DB","NOW()").",".
$record->getFieldValue("add_date","DB","NOW()").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("update_date","DB","NOW()").",".
$record->getFieldValue("last_employment_start_date","DB","NOW()").",".
$record->getFieldValue("last_employment_end_date","DB","NOW()").",".
$record->getFieldValue("last_employment","DB","NULL").",".
$record->getFieldValue("last_training_start_date","DB","NOW()").",".
$record->getFieldValue("last_training_end_date","DB","NOW()").",".
$record->getFieldValue("last_training","DB","NULL").",".
$record->getFieldValue("relevance","DB","NULL").",".
$record->getFieldValue("provider","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
$record->getFieldValue("read_state","DB","NULL").",".
$record->getFieldValue("user_read_state","DB","NULL").")"; ?>