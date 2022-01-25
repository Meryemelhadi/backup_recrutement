<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_category_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").")"; ?>