<?php $properties["query"]="INSERT INTO _rct_client(_oid,_nom_societe,_tel,_fax,_email,_adresse,_ville,_site_web,_rep_first_name,_rep_last_name,_rep_fonction,_rep_tel_fixe,_rep_tel_mobile,_rep_fax,_rep_email) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("nom_societe","DB","NULL").",".
$record->getFieldValue("tel","DB","NULL").",".
$record->getFieldValue("fax","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("adresse","DB","NULL").",".
$record->getFieldValue("ville","DB","NULL").",".
$record->getFieldValue("site_web","DB","NULL").",".
$record->getFieldValue("rep_first_name","DB","NULL").",".
$record->getFieldValue("rep_last_name","DB","NULL").",".
$record->getFieldValue("rep_fonction","DB","NULL").",".
$record->getFieldValue("rep_tel_fixe","DB","NULL").",".
$record->getFieldValue("rep_tel_mobile","DB","NULL").",".
$record->getFieldValue("rep_fax","DB","NULL").",".
$record->getFieldValue("rep_email","DB","NULL").")"; ?>