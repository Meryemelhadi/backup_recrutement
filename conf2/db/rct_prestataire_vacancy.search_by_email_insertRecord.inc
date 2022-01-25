<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_oid,_vacancy_oid,_provider_oid,_ref,_from_email,_to_email) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","%{property:vacancy_oid}").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("ref","DB","NULL").",".
$record->getFieldValue("from_email","DB","NULL").",".
$record->getFieldValue("to_email","DB","NULL").")"; ?>