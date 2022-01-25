<?php $properties["query"]="INSERT INTO _rct_vacancy_provider_attached_file(_oid,_vacancy_provider_oid,_file_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_provider_oid","DB","NULL").",".
$record->getFieldValue("file_name","DB","NULL").")"; ?>