<?php $properties["query"]="INSERT INTO _rct_vacancy_permission_readonly(_oid,_vacancy_oid,_user_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").")"; ?>