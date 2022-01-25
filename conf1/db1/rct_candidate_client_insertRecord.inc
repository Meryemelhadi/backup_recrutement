<?php $properties["query"]="INSERT INTO _rct_candidate_client(_oid,_date,_proposed_by,_proposed_to,_candidate_oid,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("proposed_by","DB","NULL").",".
$record->getFieldValue("proposed_to","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>