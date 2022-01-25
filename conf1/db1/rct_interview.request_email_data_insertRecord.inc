<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_vacancy_oid,_date,_time_start,_time_end) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").")"; ?>