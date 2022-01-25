<?php $properties["query"]="INSERT INTO _rct_email_sample(_oid,_name,_email_title,_email_content) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("email_title","DB","NULL").",".
$record->getFieldValue("email_content","DB","NULL").")"; ?>