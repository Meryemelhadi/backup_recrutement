<?php $properties["query"]="INSERT INTO _rct_vacancy_project(_oid,_name,_description) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("description","DB","NULL").")"; ?>