<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_candidate_oid,_interview_type,_interview_etat,_interview_feedback,_date,_time_start,_time_end,_location,_interview_by_oid,_comment,_candidate_email_not,_default_email,_vacancy_oid,_email_title,_email_content,_email_docs,_interviewer_email_not,_user_default_email,_user_email_title,_user_email_content,_user_email_docs,_created_by,_validated_by,_ical_uid,_ical_seq,_video_link) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("date","DB","now").",".
$record->getFieldValue("time_start","DB","now").",".
$record->getFieldValue("time_end","DB","now+10min").",".
$record->getFieldValue("location","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("candidate_email_not","DB","0").",".
$record->getFieldValue("default_email","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_docs","DB","NULL").",".
$record->getFieldValue("interviewer_email_not","DB","0").",".
$record->getFieldValue("user_default_email","DB","NULL").",".
$record->getFieldValue("user_email_title","DB","NULL").",".
$record->getFieldValue("user_email_content","DB","NULL").",".
$record->getFieldValue("user_email_docs","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("validated_by","DB","NULL").",".
$record->getFieldValue("ical_uid","DB","NULL").",".
$record->getFieldValue("ical_seq","DB","0").",".
$record->getFieldValue("video_link","DB","NULL").")"; ?>