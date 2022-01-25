<?php $properties["query"]="INSERT INTO _rct_delayed_feedback(_oid,_candidate_oid,_filled_by,_scheduled_by,_scheduled_on,_launch_date,_fill_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("filled_by","DB","NULL").",".
$record->getFieldValue("scheduled_by","DB","NULL").",".
"NOW(),".
$record->getFieldValue("launch_date","DB","NOW()").",".
$record->getFieldValue("fill_state","DB","NULL").")"; ?>