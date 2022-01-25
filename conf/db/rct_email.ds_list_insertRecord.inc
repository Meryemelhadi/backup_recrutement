<?php $properties["query"]="INSERT INTO _rct_email(_oid,_candidate_oid,_vacancy_oid,_creation_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").")"; ?>