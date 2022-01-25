<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_code,_name,_number,_progress_level,_workflow_state,_request_date,_requested_by,_manager_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","1").",".
$record->getFieldValue("progress_level","DB","NULL").",".
$record->getFieldValue("workflow_state","DB","NULL").",".
$record->getFieldValue("request_date","DB","NOW()").",".
$record->getFieldValue("requested_by","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").")"; ?>