<?php $properties["query"]="INSERT INTO _rct_interview_comment(_oid,_candidate_oid,_interview_by_oid,_vacancy_oid,_date,_time_start,_time_end,_validation_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("validation_state","DB","NULL").")"; ?>