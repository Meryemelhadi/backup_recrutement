<?php $properties["query"]="INSERT INTO _rct_candidate_client(_oid,_date,_proposed_by,_proposed_to,_candidate_oid,_comment,_email_type,_email_title,_email_content,_email_docs) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("proposed_by","DB","NULL").",".
$record->getFieldValue("proposed_to","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("email_type","DB","10").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_docs","DB","NULL").")"; ?>