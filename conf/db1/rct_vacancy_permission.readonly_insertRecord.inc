<?php $properties["query"]="INSERT INTO _rct_vacancy_permission(_oid,_vacancy_oid,_user_oid,_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
"'0')"; ?>