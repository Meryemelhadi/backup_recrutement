<?php $properties["query"]="INSERT INTO _rct_email(_oid,_candidate_oid,_vacancy_oid,_created_by,_creation_date,_email_type,_email_title,_email_content) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("email_type","DB","1").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").")"; ?>