<?php $properties["query"]="INSERT INTO _rct_vacancy_provider(_provider_oid,_vacancy_oid,_requested_by,_request_date,_email_title,_email_content,_from_email,_to_email,_active,_salaire,_descriptionEntreprise,_descriptionPoste,_descriptionProfil,_date,_duree,_nombrePoste,_startDate,_endDate) VALUES(".$record->getFieldValue("provider_oid","DB","NULL").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
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