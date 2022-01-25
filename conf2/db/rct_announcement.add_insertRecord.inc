<?php $properties["query"]="INSERT INTO _rct_announcement(_vacancy_oid,_created_by,_creation_date,_ann_title,_ann_content,_ref_oid,_provider_oid,_type) VALUES('".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("ann_title","DB","NULL").",".
$record->getFieldValue("ann_content","DB","NULL").",".
$record->getFieldValue("ref_oid","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("type","DB","NULL").")"; ?>