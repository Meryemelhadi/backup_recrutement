<?php $properties["query"]="INSERT INTO _rct_delayed_feedback(_oid,_still_in_office,_integration_degree,_job_ownership_degree,_learning_ease,_autonomy_degree,_recruit_satisfaction,_comment,_filled_on,_fill_state,_notification_state) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("still_in_office","DB","NULL").",".
$record->getFieldValue("integration_degree","DB","NULL").",".
$record->getFieldValue("job_ownership_degree","DB","NULL").",".
$record->getFieldValue("learning_ease","DB","NULL").",".
$record->getFieldValue("autonomy_degree","DB","NULL").",".
$record->getFieldValue("recruit_satisfaction","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").",".
"NOW(),".
"'1',".
"'1')"; ?>