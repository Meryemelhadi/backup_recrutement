<?php $properties["query"]="INSERT INTO _rct_entreprise_description_rekrute(_oid,_name_description,_entreprise,_identifiant,_descriptionEntreprise) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name_description","DB","NULL").",".
$record->getFieldValue("entreprise","DB","NULL").",".
$record->getFieldValue("identifiant","DB","NULL").",".
$record->getFieldValue("descriptionEntreprise","DB","NULL").")"; ?>