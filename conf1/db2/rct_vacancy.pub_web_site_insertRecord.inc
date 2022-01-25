<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_name,_email,_number,_code,_opening_date,_duty_station_oid,_salaire,_descriptionEntreprise,_descriptionPoste,_descriptionProfil,_date,_duree,_nombrePoste,_startDate,_endDate) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("number","DB","1").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("salaire","DB","NULL").",".
$record->getFieldValue("descriptionEntreprise","DB","NULL").",".
$record->getFieldValue("descriptionPoste","DB","NULL").",".
$record->getFieldValue("descriptionProfil","DB","NULL").",".
"NOW(),".
$record->getFieldValue("duree","DB","NULL").",".
$record->getFieldValue("nombrePoste","DB","NULL").",".
$record->getFieldValue("startDate","DB","NOW()").",".
$record->getFieldValue("endDate","DB","NOW()").")"; ?>