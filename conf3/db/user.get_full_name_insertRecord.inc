<?php $properties["query"]="INSERT INTO _user(_first_name,_last_name) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").")"; ?>