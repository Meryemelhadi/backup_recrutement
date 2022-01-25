<?php $properties["query"]="INSERT INTO _rct_interview_synthesis_lydec(_oid,_interview_oid,_user_oid,_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("interview_oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").")"; ?>