<?php $properties["query"]="INSERT INTO _rct_candidate_read_state(_oid,_candidate_oid,_user_oid,_read_time) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
"NOW())"; ?>