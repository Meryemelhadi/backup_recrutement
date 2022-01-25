<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_full_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("full_name","DB","NULL").")"; ?>