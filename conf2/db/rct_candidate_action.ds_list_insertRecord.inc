<?php $properties["query"]="INSERT INTO _rct_candidate_action(_oid,_candidate_oid,_user_oid,_date,_action_oid,_ref_oid,_additional_infos) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
"NOW(),".
$record->getFieldValue("action_oid","DB","NULL").",".
$record->getFieldValue("ref_oid","DB","NULL").",".
$record->getFieldValue("additional_infos","DB","NULL").")"; ?>