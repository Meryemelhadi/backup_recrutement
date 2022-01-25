<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_oid,_ref,_provider_oid,_from_email,_to_email) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("ref","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("from_email","DB","NULL").",".
$record->getFieldValue("to_email","DB","NULL").")"; ?>