<?php $properties["query"]="INSERT INTO _rct_education(_oid,_candidate_oid,_diploma,_diploma_type,_institution,_date,_description) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("diploma","DB","NULL").",".
$record->getFieldValue("diploma_type","DB","NULL").",".
$record->getFieldValue("institution","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("description","DB","NULL").")"; ?>