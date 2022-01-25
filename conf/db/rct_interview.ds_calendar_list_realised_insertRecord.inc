<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_candidate_oid,_interview_by_oid,_vacancy_oid,_date,_time_start,_time_end,_validation_state,_etat_color,_created_by,_etat_oid,_interview_etat,_cv_path,_location,_phone_1,_phone_2,_mobile,_video_link,_interview_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("validation_state","DB","NULL").",".
$record->getFieldValue("etat_color","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("location","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("phone_2","DB","NULL").",".
$record->getFieldValue("mobile","DB","NULL").",".
$record->getFieldValue("video_link","DB","NULL").",".
$record->getFieldValue("interview_type","DB","1").")"; ?>