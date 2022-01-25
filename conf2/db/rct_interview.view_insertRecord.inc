<?php $properties["query"]="INSERT INTO _rct_interview(_candidate_oid,_interview_type,_interview_etat,_interview_feedback,_date,_time_start,_time_end,_interview_by_oid,_location,_comment,_oid,_created_by,_validated_by) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("interview_etat","DB","1").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("date","DB","now").",".
$record->getFieldValue("time_start","DB","now").",".
$record->getFieldValue("time_end","DB","now+10min").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("location","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("validated_by","DB","NULL").")"; ?>