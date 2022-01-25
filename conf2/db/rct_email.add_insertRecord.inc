<?php $properties["query"]="INSERT INTO _rct_email(_candidate_oid,_email_type,_vacancy_oid,_created_by,_creation_date,_email_title,_email_content,_email_docs) VALUES('".$props->getProperty("candidate_oid","",true)."',".
$record->getFieldValue("email_type","DB","1").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_docs","DB","NULL").")"; ?>