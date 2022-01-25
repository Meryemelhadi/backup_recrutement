<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_assoc_oid,_first_name,_last_name,_cv_path,_years_of_practice,_keywords,_rating,_status,_is_visible,_ci_acceptance_state,_job_acceptance_state,_proposal_acceptance_state,_proposal_acceptance_date,_read_state,_user_read_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("assoc_oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("rating","DB","NULL").",".
$record->getFieldValue("status","DB","NULL").",".
$record->getFieldValue("is_visible","DB","0").",".
$record->getFieldValue("ci_acceptance_state","DB","0").",".
$record->getFieldValue("job_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_date","DB","NOW()").",".
$record->getFieldValue("read_state","DB","NULL").",".
$record->getFieldValue("user_read_state","DB","NULL").")"; ?>