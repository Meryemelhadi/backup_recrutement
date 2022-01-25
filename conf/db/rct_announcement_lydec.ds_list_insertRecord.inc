<?php $properties["query"]="INSERT INTO _rct_announcement_lydec(_oid,_candidate_oid,_vacancy_oid,_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").")"; ?>