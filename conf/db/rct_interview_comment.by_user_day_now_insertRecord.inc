<?php $properties["query"]="INSERT INTO _rct_interview_comment(_time_start,_time_end,_candidate_oid) VALUES(".$record->getFieldValue("time_start","DB","NOW()").",".
$record->getFieldValue("time_end","DB","NOW()").",".
$record->getFieldValue("candidate_oid","DB","NULL").")"; ?>