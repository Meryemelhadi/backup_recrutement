<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_candidate_oid,_vacancy_oid,_add_date,_rating,_status,_is_visible,_cv_source_oid,_proposal_acceptance_date,_contrat_signing,_hire_date,_integration_plan,_integration_note,_ci_acceptance_state,_ci_acceptance_date,_job_acceptance_state,_job_acceptance_date,_proposal_acceptance_state,_integration_date,_etat_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("add_date","DB","NOW()").",".
$record->getFieldValue("rating","DB","NULL").",".
$record->getFieldValue("status","DB","NULL").",".
$record->getFieldValue("is_visible","DB","0").",".
$record->getFieldValue("cv_source_oid","DB","NULL").",".
$record->getFieldValue("proposal_acceptance_date","DB","NOW()").",".
$record->getFieldValue("contrat_signing","DB","0").",".
$record->getFieldValue("hire_date","DB","NOW()").",".
$record->getFieldValue("integration_plan","DB","0").",".
$record->getFieldValue("integration_note","DB","0").",".
$record->getFieldValue("ci_acceptance_state","DB","0").",".
$record->getFieldValue("ci_acceptance_date","DB","NOW()").",".
$record->getFieldValue("job_acceptance_state","DB","0").",".
$record->getFieldValue("job_acceptance_date","DB","NOW()").",".
$record->getFieldValue("proposal_acceptance_state","DB","0").",".
$record->getFieldValue("integration_date","DB","NOW()").",".
$record->getFieldValue("etat_oid","DB","NULL").")"; ?>