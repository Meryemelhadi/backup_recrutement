<?php $properties["query"]="INSERT INTO _rct_vacancy(_name,_service_oid,_opening_date_start,_opening_date_end,_application_type,_current_step,_progress_level) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("opening_date_start","DB","NOW()").",".
$record->getFieldValue("opening_date_end","DB","NOW()").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").")"; ?>