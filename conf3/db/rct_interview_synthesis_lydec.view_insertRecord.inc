<?php $properties["query"]="INSERT INTO _rct_interview_synthesis_lydec(_oid,_user_oid,_date,_post,_interview_oid,_direction,_technicite_comment,_technicite_note,_management_comment,_management_note,_communication_comment,_communication_note,_motivation_comment,_motivation_note,_general_comment,_avis) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("user_oid","DB","NULL").",".
$record->getFieldValue("date","DB","NOW()").",".
$record->getFieldValue("post","DB","NULL").",".
$record->getFieldValue("interview_oid","DB","NULL").",".
$record->getFieldValue("direction","DB","NULL").",".
$record->getFieldValue("technicite_comment","DB","NULL").",".
$record->getFieldValue("technicite_note","DB","0").",".
$record->getFieldValue("management_comment","DB","NULL").",".
$record->getFieldValue("management_note","DB","0").",".
$record->getFieldValue("communication_comment","DB","NULL").",".
$record->getFieldValue("communication_note","DB","0").",".
$record->getFieldValue("motivation_comment","DB","NULL").",".
$record->getFieldValue("motivation_note","DB","0").",".
$record->getFieldValue("general_comment","DB","NULL").",".
$record->getFieldValue("avis","DB","NULL").")"; ?>