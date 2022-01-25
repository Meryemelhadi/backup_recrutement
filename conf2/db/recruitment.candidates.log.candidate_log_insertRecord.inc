<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy_action(_candidate_oid,_vacancy_oid,_user_oid,_date,_action_oid,_ref_oid,_additional_infos,_candidate_full_name,_user_full_name,_short_list_name) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
"NOW(),".
$record->getFieldValue("action_oid","DB","NULL").",".
$record->getFieldValue("ref_oid","DB","NULL").",".
$record->getFieldValue("additional_infos","DB","NULL").",".
$record->getFieldValue("candidate_full_name","DB","NULL").",".
$record->getFieldValue("user_full_name","DB","NULL").",".
$record->getFieldValue("short_list_name","DB","NULL").")"; ?>