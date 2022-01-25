<?php $properties["query"]="INSERT INTO _directory_country(_oid,_country_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("country_name","DB","NULL").")"; ?>