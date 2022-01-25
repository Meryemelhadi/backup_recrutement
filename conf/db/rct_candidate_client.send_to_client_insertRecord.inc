<?php $properties["query"]="INSERT INTO _rct_candidate_client(_candidate_oid,_comment,_email_title,_email_content,_email_docs) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_docs","DB","NULL").")"; ?>