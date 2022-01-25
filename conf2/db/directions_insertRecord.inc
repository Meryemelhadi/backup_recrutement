<?php $properties["query"]="INSERT INTO _directory_group(_oid,_group_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("group_name","DB","NULL").")"; ?>