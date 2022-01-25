<?php $properties["query"]="INSERT INTO _rct_candidate_client(_comment,_proposed_to,_proposed,_candidate_oid) VALUES(".$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("proposed_to","DB","NULL").",".
$record->getFieldValue("proposed","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").")"; ?>