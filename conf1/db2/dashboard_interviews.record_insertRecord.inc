<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_candidate_oid,_vacancy_oid,_created_by,_validated_by,_interview_by_oid,_creation_date,_validation_date,_date,_time_start,_time_end,_validation_state,_interview_type,_interview_etat,_interview_feedback,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("validated_by","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("validation_date","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("validation_state","DB","NULL").",".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>