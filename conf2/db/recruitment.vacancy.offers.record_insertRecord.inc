<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_provider_oid,_active,_date,_vacancy_oid) VALUES(".$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("active","DB","NULL").",".
"NOW(),".
$record->getFieldValue("vacancy_oid","DB","NULL").")"; ?>