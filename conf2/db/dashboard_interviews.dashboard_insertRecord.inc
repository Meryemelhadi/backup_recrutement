<?php $properties["query"]="INSERT INTO _rct_interview(_oid,_date,_interview_type,_interview_by_oid,_interview_feedback,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("interview_type","DB","NULL").",".
$record->getFieldValue("interview_by_oid","DB","NULL").",".
$record->getFieldValue("interview_feedback","DB","1").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>