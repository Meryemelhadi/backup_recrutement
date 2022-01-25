<?php $properties["query"]="INSERT INTO _rct_provider(_oid,_provider_username,_provider_password) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("provider_username","DB","NULL").",".
$record->getFieldValue("provider_password","DB","NULL").")"; ?>