<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_ci_acceptance_state,_job_acceptance_state,_proposal_acceptance_state,_proposal_acceptance_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("ci_acceptance_state","DB","0").",".
$record->getFieldValue("job_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_state","DB","0").",".
$record->getFieldValue("proposal_acceptance_date","DB","NOW()").")"; ?>