<?php $properties["query"]="INSERT INTO _rct_vacancy_readonly(_oid,_code,_name,_number,_workflow_state,_request_date,_requested_by) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("number","DB","NULL").",".
$record->getFieldValue("workflow_state","DB","NULL").",".
$record->getFieldValue("request_date","DB","NOW()").",".
$record->getFieldValue("requested_by","DB","NULL").")"; ?>