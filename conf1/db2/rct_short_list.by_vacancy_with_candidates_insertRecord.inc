<?php $properties["query"]="INSERT INTO _rct_short_list(_oid,_name,_created_by,_creation_date,_sent_by,_sending_date,_vacancy_oid,_is_visible) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("sent_by","DB","NULL").",".
$record->getFieldValue("sending_date","DB","NOW()").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("is_visible","DB","0").")"; ?>