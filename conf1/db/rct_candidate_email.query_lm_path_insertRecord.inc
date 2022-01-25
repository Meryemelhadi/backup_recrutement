<?php $properties["query"]="INSERT INTO _rct_candidate_email(_candidate_oid,_oid,_lm) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("lm","DB","NULL").")"; ?>