<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_email) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").")"; ?>