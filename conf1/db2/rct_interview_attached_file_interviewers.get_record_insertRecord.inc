<?php $properties["query"]="INSERT INTO _rct_interview_attached_file_interviewers(_oid,_interview_oid,_file_name,_file) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("interview_oid","DB","NULL").",".
$record->getFieldValue("file_name","DB","NULL").",".
$record->getFieldValue("file","DB","NULL").")"; ?>