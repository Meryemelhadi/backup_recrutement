<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_candidate_oid,_vacancy_oid,_created_by,_validated_by,_interview_by,_creation_date,_validation_date,_date,_time_start,_time_end,_email_title,_email_content,_user_email_title,_user_email_content,_candidate_email_not,_interviewer_email_not,_validation_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("validated_by","DB","NULL").",".
$record->getFieldValue("interview_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("validation_date","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("user_email_title","DB","NULL").",".
$record->getFieldValue("user_email_content","DB","NULL").",".
$record->getFieldValue("candidate_email_not","DB","NULL").",".
$record->getFieldValue("interviewer_email_not","DB","NULL").",".
$record->getFieldValue("validation_state","DB","NULL").")"; ?>