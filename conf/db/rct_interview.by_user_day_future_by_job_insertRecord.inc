<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_time_start,_time_end,_date,_candidate_oid,_candidate,_vacancy_oid,_vacancy_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("candidate","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("vacancy_name","DB","NULL").")"; ?>