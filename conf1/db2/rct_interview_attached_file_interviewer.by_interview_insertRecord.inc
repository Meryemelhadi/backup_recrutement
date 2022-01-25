<?php $properties["query"]="INSERT INTO _rct_interview_attached_file_interviewer(_oid,_interview_oid,_file_name) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("interview_oid","DB","NULL").",".
$record->getFieldValue("file_name","DB","NULL").")"; ?>