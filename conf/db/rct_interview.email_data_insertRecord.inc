<?php $properties["query"]="INSERT INTO _rct_interview(_docs,_user_docs,_ical_uid,_ical_seq) VALUES(".$record->getFieldValue("docs","DB","NULL").",".
$record->getFieldValue("user_docs","DB","NULL").",".
$record->getFieldValue("ical_uid","DB","NULL").",".
$record->getFieldValue("ical_seq","DB","0").")"; ?>