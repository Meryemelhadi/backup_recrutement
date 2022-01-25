<?php $properties["query"]="INSERT INTO _rct_email(_candidate_oid,_email_type,_created_by,_creation_date,_vacancy_oid,_email_title,_email_content) VALUES('".$this->getParamValue("candidate_oid","","request",",")."',".
$record->getFieldValue("email_type","DB","1").",".
$record->getFieldValue("created_by","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
"'".$props->getProperty("vacancy_oid","",true)."',".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").")"; ?>