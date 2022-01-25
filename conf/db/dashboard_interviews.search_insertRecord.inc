<?php $properties["query"]="INSERT INTO _rct_interview(_candidate_oid,_vacancy_oid,_interview_by_oid) VALUES(".$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").")"; ?>