<?php $properties["query"]="INSERT INTO _rct_announcement_rekrute(_vacancy_oid,_created_by,_creation_date,_descriptionPoste) VALUES('".$props->getProperty("vacancy_oid","",true)."',".
$record->getFieldValue("created_by","DB","NULL").",".
"NOW(),".
$record->getFieldValue("descriptionPoste","DB","NULL").")"; ?>