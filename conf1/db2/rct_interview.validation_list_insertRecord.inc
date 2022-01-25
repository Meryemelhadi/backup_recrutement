<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_candidate_oid,_created_by,_date,_time_start,_time_end,_validation_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("validation_state","DB","NULL").")"; ?>