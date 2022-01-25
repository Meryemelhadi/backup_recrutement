<?php $properties["query"]="INSERT INTO _rct_interview_synthesis(_interview_oid,_date,_synthesis_oid,_date_eval) VALUES(".$record->getFieldValue("interview_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("synthesis_oid","DB","NULL").",".
$record->getFieldValue("date_eval","DB","NOW()").")"; ?>