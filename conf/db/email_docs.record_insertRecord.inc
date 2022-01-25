<?php $properties["query"]="INSERT INTO _rct_email_docs(_oid,_name,_file,_index,_dest) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("file","DB","NULL").",".
$record->getFieldValue("index","DB","NULL").",".
$record->getFieldValue("dest","DB","NULL").")"; ?>