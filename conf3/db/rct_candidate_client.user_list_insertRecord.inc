<?php $properties["query"]="INSERT INTO _rct_candidate_client(_oid,_proposed_by,_date,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("proposed_by","DB","NULL").",".
"NOW(),".
$record->getFieldValue("comment","DB","NULL").")"; ?>