<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_oid,_ref,_provider_oid,_vacancy_oid,_from_email,_to_email,_active,_salaire,_descriptionEntreprise,_descriptionPoste,_descriptionProfil,_date,_duree,_nombrePoste,_startDate,_endDate) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("ref","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
$record->getFieldValue("from_email","DB","NULL").",".
$record->getFieldValue("to_email","DB","NULL").",".
$record->getFieldValue("active","DB","NULL").",".
$record->getFieldValue("salaire","DB","NULL").",".
$record->getFieldValue("descriptionEntreprise","DB","NULL").",".
$record->getFieldValue("descriptionPoste","DB","NULL").",".
$record->getFieldValue("descriptionProfil","DB","NULL").",".
"NOW(),".
$record->getFieldValue("duree","DB","NULL").",".
$record->getFieldValue("nombrePoste","DB","NULL").",".
$record->getFieldValue("startDate","DB","NOW()").",".
$record->getFieldValue("endDate","DB","NOW()").")"; ?>