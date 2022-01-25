<?php $properties["query"]="INSERT INTO _rct_candidate_short_list(_oid,_short_list_oid,_candidate_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("short_list_oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").")"; ?>