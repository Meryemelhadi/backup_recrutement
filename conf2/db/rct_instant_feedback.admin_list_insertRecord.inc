<?php $properties["query"]="INSERT INTO _rct_instant_feedback(_oid,_filled_by,_scheduled_by,_scheduled_on,_fill_state,_completed_by,_completed_on,_complete_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("filled_by","DB","NULL").",".
$record->getFieldValue("scheduled_by","DB","NULL").",".
"NOW(),".
$record->getFieldValue("fill_state","DB","NULL").",".
$record->getFieldValue("completed_by","DB","NULL").",".
$record->getFieldValue("completed_on","DB","NOW()").",".
$record->getFieldValue("complete_state","DB","NULL").")"; ?>