<?php $properties["query"]="INSERT INTO _rct_interview(_time_start,_time_end,_interview_type,_candidate_oid,_date) VALUES(".$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").")"; ?>