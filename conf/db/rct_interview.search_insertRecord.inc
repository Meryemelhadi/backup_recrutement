<?php $properties["query"]="INSERT INTO _rct_interview(_candidate_oid,_vacancy_oid,_interview_type) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("interview_type","DB","1").")"; ?>