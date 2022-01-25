<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_created_by,_creation_date,_validated_by,_candidate_oid,_interview_by,_date,_time_start,_time_end,_email_title,_email_content,_user_email_title,_user_email_content,_candidate_email_not,_interviewer_email_not) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("validated_by","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_by","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","09:00").",".
$record->getFieldValue("time_end","DB","11:00").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("user_email_title","DB","NULL").",".
$record->getFieldValue("user_email_content","DB","NULL").",".
$record->getFieldValue("candidate_email_not","DB","0").",".
$record->getFieldValue("interviewer_email_not","DB","0").")"; ?>