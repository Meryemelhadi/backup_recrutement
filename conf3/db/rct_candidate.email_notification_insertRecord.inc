<?php $properties["query"]="INSERT INTO _rct_candidate(_first_name,_last_name,_email) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").")"; ?>