<?php $properties["query"]="INSERT INTO _rct_email(_oid,_candidate_oid,_user_cc,_created_by,_creation_date,_email_type,_email_title,_email_content,_docs) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
"'".$this->getParamValue("coid","","request",",")."',".
$record->getFieldValue("user_cc","DB","NULL").",".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
"NOW(),".
$record->getFieldValue("email_type","DB","1").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("docs","DB","NULL").")"; ?>