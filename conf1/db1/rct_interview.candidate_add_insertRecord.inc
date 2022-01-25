<?php $properties["query"]="INSERT INTO _rct_interview(_candidate_oid,_vacancy_oid,_created_by,_validated_by,_interview_by,_creation_date,_validation_date,_date,_time_start,_time_end,_email_title,_email_content,_user_email_title,_user_email_content,_candidate_email_not,_interviewer_email_not,_validation_state) VALUES('".$props->getProperty("candidate_oid","",true)."',".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("interview_by","DB","NULL").",".
"NOW(),".
"NOW(),".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","09:00").",".
$record->getFieldValue("time_end","DB","11:00").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("user_email_title","DB","NULL").",".
$record->getFieldValue("user_email_content","DB","NULL").",".
$record->getFieldValue("candidate_email_not","DB","0").",".
$record->getFieldValue("interviewer_email_not","DB","0").",".
"'1')"; ?>