<?php $properties["query"]="INSERT INTO _rct_interview_comment(_oid,_vacancy_oid,_date,_time_start,_time_end,_ical_uid,_ical_seq) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("ical_uid","DB","NULL").",".
$record->getFieldValue("ical_seq","DB","0").")"; ?>