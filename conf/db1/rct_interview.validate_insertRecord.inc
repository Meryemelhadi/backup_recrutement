<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_created_by,_candidate_oid,_validated_by,_interview_by,_date,_time_start,_time_end) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("validated_by","DB","NULL").",".
$record->getFieldValue("interview_by","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","09:00").",".
$record->getFieldValue("time_end","DB","11:00").")"; ?>