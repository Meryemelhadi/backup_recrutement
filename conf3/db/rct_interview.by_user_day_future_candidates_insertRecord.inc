<?php $properties["query"]="INSERT INTO _rct_interview(_time_start,_time_end,_date,_update_date,_creation_date,_update_info_date,_candidate_oid) VALUES(".$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("update_date","DB","NOW()").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("update_info_date","DB","NOW()").",".
$record->getFieldValue("candidate_oid","DB","NULL").")"; ?>