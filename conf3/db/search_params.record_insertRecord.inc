<?php $properties["query"]="INSERT INTO _rct_search_params(_oid,_name,_fields,_is_default) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("fields","DB","NULL").",".
$record->getFieldValue("is_default","DB","NULL").")"; ?>