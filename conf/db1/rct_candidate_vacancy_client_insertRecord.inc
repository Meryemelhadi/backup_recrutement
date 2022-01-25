<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy_client(_oid,_candidate_oid,_vacancy_oid,_proposed_by,_proposal_date,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("proposed_by","DB","NULL").",".
$record->getFieldValue("proposal_date","DB","NOW()").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>