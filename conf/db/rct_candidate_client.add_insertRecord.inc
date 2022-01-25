<?php $properties["query"]="INSERT INTO _rct_candidate_client(_oid,_date,_proposed_by,_proposed_to,_email_type,_email_title,_email_content,_email_docs,_comment,_candidate_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
"NOW(),".
"'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."',".
$record->getFieldValue("proposed_to","DB","NULL").",".
$record->getFieldValue("email_type","DB","10").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_docs","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
"'".$props->getProperty("candidate_oid","",true)."')"; ?>