<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_candidate_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").")"; ?>