<?php $properties["query"]="INSERT INTO _rct_announcement_lydec(_created_by,_creation_date,_vacancy_oid,_reference,_intitule,_typeoffre,_typereponses,_codeContrat,_codeExperience,_codeEducation,_salaire,_descriptionEntreprise,_descriptionPoste,_descriptionProfil,_duree,_contactMail,_typeAlerte,_codeRegion,_codeSecteur,_codeFonction1,_codeFonction2,_codeLangue1,_codeLangue2,_cadre,_nombrePoste,_startDate,_endDate) VALUES('".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
"'".$props->getProperty("vacancy_oid","",true)."',".
$record->getFieldValue("reference","DB","NULL").",".
$record->getFieldValue("intitule","DB","NULL").",".
$record->getFieldValue("typeoffre","DB","NULL").",".
$record->getFieldValue("typereponses","DB","NULL").",".
$record->getFieldValue("codeContrat","DB","NULL").",".
$record->getFieldValue("codeExperience","DB","NULL").",".
$record->getFieldValue("codeEducation","DB","NULL").",".
$record->getFieldValue("salaire","DB","NULL").",".
$record->getFieldValue("descriptionEntreprise","DB","NULL").",".
$record->getFieldValue("descriptionPoste","DB","NULL").",".
$record->getFieldValue("descriptionProfil","DB","NULL").",".
$record->getFieldValue("duree","DB","NULL").",".
$record->getFieldValue("contactMail","DB","NULL").",".
$record->getFieldValue("typeAlerte","DB","NULL").",".
$record->getFieldValue("codeRegion","DB","NULL").",".
$record->getFieldValue("codeSecteur","DB","NULL").",".
$record->getFieldValue("codeFonction1","DB","NULL").",".
$record->getFieldValue("codeFonction2","DB","NULL").",".
$record->getFieldValue("codeLangue1","DB","NULL").",".
$record->getFieldValue("codeLangue2","DB","NULL").",".
$record->getFieldValue("cadre","DB","NULL").",".
$record->getFieldValue("nombrePoste","DB","NULL").",".
$record->getFieldValue("startDate","DB","NOW()").",".
$record->getFieldValue("endDate","DB","NOW()").")"; ?>