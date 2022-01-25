<?php $properties["query"]="INSERT INTO _rct_candidate_action(_oid,_candidate_oid,_user_oid,_date,_action_oid,_ref_oid,_additional_infos,_vacancy_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
$record->getFieldValue("date","DB","now").",".
$record->getFieldValue("action_oid","DB","NULL").",".
$record->getFieldValue("ref_oid","DB","NULL").",".
$record->getFieldValue("additional_infos","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").")"; ?>