<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_country_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("country_oid","DB","NULL").")"; ?>