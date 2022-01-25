<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_vp_oid,_email,_code,_name,_ref,_id_index,_index,_offer_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vp_oid","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("ref","DB","NULL").",".
$record->getFieldValue("id_index","DB","NULL").",".
$record->getFieldValue("index","DB","NULL").",".
$record->getFieldValue("offer_name","DB","NULL").")"; ?>