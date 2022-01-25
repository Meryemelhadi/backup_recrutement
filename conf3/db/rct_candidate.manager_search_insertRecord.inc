<?php $properties["query"]="INSERT INTO _rct_candidate(_first_name,_last_name) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").")"; ?>