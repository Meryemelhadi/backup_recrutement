<?php $properties["query"]="INSERT INTO _rct_announcement(_oid,_vacancy_oid,_created_by,_creation_date,_ann_title,_ann_content,_ref_oid,_provider_oid,_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("ann_title","DB","NULL").",".
$record->getFieldValue("ann_content","DB","NULL").",".
$record->getFieldValue("ref_oid","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").",".
$record->getFieldValue("type","DB","NULL").")"; ?>