<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_oid,_manager_oid,_creator) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("creator","DB","NULL").")"; ?>