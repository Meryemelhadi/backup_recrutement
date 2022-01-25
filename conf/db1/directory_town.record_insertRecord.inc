<?php $properties["query"]="INSERT INTO _directory_town(_oid,_town_name,_country_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("town_name","DB","NULL").",".
$record->getFieldValue("country_oid","DB","NULL").")"; ?>