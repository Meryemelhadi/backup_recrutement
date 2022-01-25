<?php $properties["query"]="INSERT INTO _rct_interview_synthesis_criterias(_oid,_interview_synthesis_oid,_name,_level) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("interview_synthesis_oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("level","DB","NULL").")"; ?>