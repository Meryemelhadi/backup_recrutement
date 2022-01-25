<?php $properties["query"]="INSERT INTO _rct_interview(_candidate_oid,_vacancy_oid,_created_by,_interview_by,_creation_date,_date,_time_start,_time_end,_validation_state) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("interview_by","DB","NULL").",".
"NOW(),".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","09:00").",".
$record->getFieldValue("time_end","DB","11:00").",".
"'0')"; ?>