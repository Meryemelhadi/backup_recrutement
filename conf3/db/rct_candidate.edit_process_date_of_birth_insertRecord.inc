<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_date_of_birth) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date_of_birth","DB","NOW()").")"; ?>