<?php $properties["query"]="INSERT INTO _rct_candidate_files(_oid,_candidate_oid,_file) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("file","DB","NULL").")"; ?>