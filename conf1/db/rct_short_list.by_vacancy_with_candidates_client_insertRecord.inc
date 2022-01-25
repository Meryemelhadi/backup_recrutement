<?php $properties["query"]="INSERT INTO _rct_short_list(_oid,_vacancy_oid,_name,_proposed_by,_proposal_date,_comment) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("proposed_by","DB","NULL").",".
$record->getFieldValue("proposal_date","DB","NOW()").",".
$record->getFieldValue("comment","DB","NULL").")"; ?>