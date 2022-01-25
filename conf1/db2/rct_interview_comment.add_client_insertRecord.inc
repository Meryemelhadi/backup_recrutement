<?php $properties["query"]="INSERT INTO _rct_interview_comment(_candidate_oid,_vacancy_oid,_created_by,_interview_by_oid,_creation_date,_date,_time_start,_time_end,_validation_state,_ical_uid,_ical_seq) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("interview_by_oid","DB","%{user:oid}").",".
"NOW(),".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","now").",".
$record->getFieldValue("time_end","DB","now+10").",".
"'0',".
$record->getFieldValue("ical_uid","DB","NULL").",".
$record->getFieldValue("ical_seq","DB","0").")"; ?>