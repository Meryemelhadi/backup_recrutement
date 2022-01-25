<?php $properties["query"]="INSERT INTO _rct_client(_oid,_nom_societe,_rep_first_name,_rep_last_name,_rep_fonction,_ville,_site_web) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("nom_societe","DB","NULL").",".
$record->getFieldValue("rep_first_name","DB","NULL").",".
$record->getFieldValue("rep_last_name","DB","NULL").",".
$record->getFieldValue("rep_fonction","DB","NULL").",".
$record->getFieldValue("ville","DB","NULL").",".
$record->getFieldValue("site_web","DB","NULL").")"; ?>