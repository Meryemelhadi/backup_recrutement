<?php $properties["query"]="INSERT INTO _rct_employment(_oid,_candidate_oid,_employment_end_date,_employment_start_date,_employment_content,_type) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("employment_end_date","DB","NOW()").",".
$record->getFieldValue("employment_start_date","DB","NOW()").",".
$record->getFieldValue("employment_content","DB","NULL").",".
$record->getFieldValue("type","DB","NULL").")"; ?>