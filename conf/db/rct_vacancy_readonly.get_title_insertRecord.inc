<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_oid,_name,_code,_current_step,_progress_level) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").")"; ?>