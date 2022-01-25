<?php $properties["query"]="INSERT INTO _rct_saved_search(_oid,_name,_url) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").")"; ?>