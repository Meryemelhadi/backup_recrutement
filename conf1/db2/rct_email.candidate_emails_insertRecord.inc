<?php $properties["query"]="INSERT INTO _rct_email(_oid,_creation_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").")"; ?>