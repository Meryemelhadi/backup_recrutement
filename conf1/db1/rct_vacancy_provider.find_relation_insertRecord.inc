<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_oid,_provider_oid,_vacancy_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").")"; ?>