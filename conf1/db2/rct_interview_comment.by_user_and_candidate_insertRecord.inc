<?php $properties["query"]="INSERT INTO _rct_interview_comment(_oid,_time_start,_time_end,_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").")"; ?>