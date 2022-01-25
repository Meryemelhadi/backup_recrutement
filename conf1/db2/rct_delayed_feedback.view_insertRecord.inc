<?php $properties["query"]="INSERT INTO _rct_delayed_feedback(_candidate_oid,_scheduled_by,_scheduled_on,_filled_by,_filled_on,_launch_date,_fill_state,_still_in_office,_integration_degree,_job_ownership_degree,_learning_ease,_autonomy_degree,_recruit_satisfaction,_comment) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("scheduled_by","DB","NULL").",".
$record->getFieldValue("scheduled_on","DB","NOW()").",".
$record->getFieldValue("filled_by","DB","NULL").",".
$record->getFieldValue("filled_on","DB","NOW()").",".
$record->getFieldValue("launch_date","DB","NOW()").",".
$record->getFieldValue("fill_state","DB","NULL").",".
$record->getFieldValue("still_in_office","DB","NULL").",".
$record->getFieldValue("integration_degree","DB","NULL").",".
$record->getFieldValue("job_ownership_degree","DB","NULL").",".
$record->getFieldValue("learning_ease","DB","NULL").",".
$record->getFieldValue("autonomy_degree","DB","NULL").",".
$record->getFieldValue("recruit_satisfaction","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>