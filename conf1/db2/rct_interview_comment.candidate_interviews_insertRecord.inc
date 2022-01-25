<?php $properties["query"]="INSERT INTO _rct_interview_comment(_oid,_candidate_oid,_interview_by_oid,_location,_interview_etat,_interview_feedback,_vacancy_oid,_date,_time_start) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("location","DB","NULL").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").")"; ?>