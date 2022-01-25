<?php $properties["query"]="INSERT INTO _rct_candidate_comment(_oid,_candidate_oid,_user_oid,_date,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>