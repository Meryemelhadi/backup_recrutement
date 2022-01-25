<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_oid,_vacancy_oid,_provider_oid,_requested_by,_request_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("requested_by","DB","NULL").",".
$record->getFieldValue("request_date","DB","NOW()").")"; ?>