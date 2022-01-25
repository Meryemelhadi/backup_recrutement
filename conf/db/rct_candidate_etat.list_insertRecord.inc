<?php $properties["query"]="INSERT INTO _rct_candidate_etat(_oid,_index,_name,_taskType,_in_home,_vacancy_status,_color) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("index","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("taskType","DB","0").",".
$record->getFieldValue("in_home","DB","1").",".
$record->getFieldValue("vacancy_status","DB","NULL").",".
$record->getFieldValue("color","DB","NULL").")"; ?>