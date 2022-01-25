<?php $properties["query"]="INSERT INTO _journal_categories(_oid,_category_label,_category_description) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("category_label","DB","NULL").",".
$record->getFieldValue("category_description","DB","NULL").")"; ?>