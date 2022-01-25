<?php $properties["query"]="INSERT INTO _rct_candidate_email(_oid,_candidate_oid,_date,_email_from_name,_email_from,_email_title,_email_content,_email_content_html,_lmkey,_lm,_cvkey,_cv) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("date","DB","now").",".
$record->getFieldValue("email_from_name","DB","NULL").",".
$record->getFieldValue("email_from","DB","NULL").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").",".
$record->getFieldValue("email_content_html","DB","NULL").",".
$record->getFieldValue("lmkey","DB","NULL").",".
$record->getFieldValue("lm","DB","NULL").",".
$record->getFieldValue("cvkey","DB","NULL").",".
$record->getFieldValue("cv","DB","NULL").")"; ?>