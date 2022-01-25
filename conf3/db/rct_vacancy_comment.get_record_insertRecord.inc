<?php $properties["query"]="INSERT INTO _rct_vacancy_comment(_oid,_vacancy_oid,_user_oid,_date,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>