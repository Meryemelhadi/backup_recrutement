<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_update_date,_update_info_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("update_date","DB","now").",".
$record->getFieldValue("update_info_date","DB","NOW()").")"; ?>