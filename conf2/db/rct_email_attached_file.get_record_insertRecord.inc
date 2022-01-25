<?php $properties["query"]="INSERT INTO _rct_email_attached_file(_oid,_email_oid,_file) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("email_oid","DB","NULL").",".
$record->getFieldValue("file","DB","NULL").")"; ?>