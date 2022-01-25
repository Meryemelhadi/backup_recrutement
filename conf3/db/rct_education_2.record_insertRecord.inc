<?php $properties["query"]="INSERT INTO _rct_education(_oid,_candidate_oid,_date,_institution,_description) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("institution","DB","NULL").",".
$record->getFieldValue("description","DB","NULL").")"; ?>