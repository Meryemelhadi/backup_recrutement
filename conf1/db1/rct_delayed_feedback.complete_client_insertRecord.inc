<?php $properties["query"]="INSERT INTO _rct_delayed_feedback(_oid,_candidate_oid,_still_in_office,_integration_degree,_job_ownership_degree,_learning_ease,_autonomy_degree,_recruit_satisfaction,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
"'1',".
$record->getFieldValue("integration_degree","DB","NULL").",".
$record->getFieldValue("job_ownership_degree","DB","NULL").",".
$record->getFieldValue("learning_ease","DB","NULL").",".
$record->getFieldValue("autonomy_degree","DB","NULL").",".
$record->getFieldValue("recruit_satisfaction","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>