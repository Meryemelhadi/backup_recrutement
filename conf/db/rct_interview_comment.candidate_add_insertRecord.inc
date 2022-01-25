<?php $properties["query"]="INSERT INTO _rct_interview_comment(_candidate_oid,_vacancy_oid,_created_by,_validated_by,_interview_type,_interview_etat,_interview_feedback,_date,_time_start,_time_end,_interview_by_oid,_location,_creation_date,_validation_date,_comment,_email_title,_email_content,_email_docs,_user_email_title,_user_email_content,_user_email_docs,_candidate_email_not,_interviewer_email_not,_validation_state,_ical_uid,_ical_seq) VALUES('".$props->getProperty("candidate_oid","",true)."',".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("date","DB","now").",".
$record->getFieldValue("time_start","DB","now").",".
$record->getFieldValue("time_end","DB","now+10min").",".
$record->getFieldValue("interview_by_oid","DB","%{user:oid}").",".
$record->getFieldValue("location","DB","NULL").",".
"NOW(),".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_docs","DB","NULL").",".
$record->getFieldValue("user_email_title","DB","NULL").",".
$record->getFieldValue("user_email_content","DB","NULL").",".
$record->getFieldValue("user_email_docs","DB","NULL").",".
$record->getFieldValue("candidate_email_not","DB","0").",".
$record->getFieldValue("interviewer_email_not","DB","0").",".
"'1',".
$record->getFieldValue("ical_uid","DB","NULL").",".
$record->getFieldValue("ical_seq","DB","0").")"; ?>