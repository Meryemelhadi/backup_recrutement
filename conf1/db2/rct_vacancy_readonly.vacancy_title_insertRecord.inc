<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_name,_code,_current_step) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").")"; ?>