<?php $properties["query"]="INSERT INTO _rct_announcement(_vacancy_oid,_created_by,_creation_date,_ann_title,_provider_oid) VALUES('".$props->getProperty("vacancy_oid","",true)."',".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("ann_title","DB","NULL").",".
$record->getFieldValue("provider_oid","DB","NULL").")"; ?>