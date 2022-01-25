<?php $properties["query"]="INSERT INTO _rct_interview_comment(_oid,_created_by,_candidate_oid,_validated_by,_interview_by_oid,_interview_type,_date,_interview_etat,_interview_feedback,_time_start,_time_end,_location,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("validated_by","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("time_start","DB","now").",".
$record->getFieldValue("time_end","DB","now+10").",".
$record->getFieldValue("location","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>