<?php $properties["query"]="INSERT INTO _rct_client(_oid,_logo,_nom_societe,_site_web,_tel,_rep_first_name,_rep_last_name,_rep_fonction,_rep_tel_mobile,_rep_email,_ville) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("logo","DB","NULL").",".
$record->getFieldValue("nom_societe","DB","NULL").",".
"'".$props->getProperty("site_web","",true)."',".
$record->getFieldValue("tel","DB","NULL").",".
$record->getFieldValue("rep_first_name","DB","NULL").",".
$record->getFieldValue("rep_last_name","DB","NULL").",".
$record->getFieldValue("rep_fonction","DB","NULL").",".
$record->getFieldValue("rep_tel_mobile","DB","NULL").",".
$record->getFieldValue("rep_email","DB","NULL").",".
$record->getFieldValue("ville","DB","NULL").")"; ?>