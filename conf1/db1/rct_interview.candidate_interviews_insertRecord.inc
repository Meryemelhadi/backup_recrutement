<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_candidate_oid,_interview_by,_vacancy_oid,_date,_time_start) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("interview_by","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").")"; ?>