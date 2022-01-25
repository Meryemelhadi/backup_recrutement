<?php $properties["query"]="INSERT INTO _rct_vacancy(_name,_manager_oid,_requested_by) VALUES(".$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").",".
$record->getFieldValue("requested_by","DB","NULL").")"; ?>