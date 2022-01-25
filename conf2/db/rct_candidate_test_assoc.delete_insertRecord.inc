<?php $properties["query"]="INSERT INTO _rct_candidate_test_assoc(_oid,_candidate_oid,_test_oid,_pourcentage,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("test_oid","DB","NULL").",".
$record->getFieldValue("pourcentage","DB","NULL").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>