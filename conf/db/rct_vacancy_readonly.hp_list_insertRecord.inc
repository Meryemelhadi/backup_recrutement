<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_oid,_key,_key,_progress_level,_client_oid,_archive_state,_manager_oid,_name,_number,_code,_creator,_count) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("key","DB","NULL").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("client_oid","DB","NULL").",".
"'0',".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("creator","DB","NULL").",".
$record->getFieldValue("count","DB","NULL").")"; ?>