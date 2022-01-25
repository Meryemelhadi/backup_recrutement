<?php $properties["query"]="INSERT INTO _rct_candidate_etat(_oid,_name,_index,_taskType,_in_home,_color,_vacancy_status,_etat_type,_etat_next,_is_short_list,_is_default) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("index","DB","NULL").",".
$record->getFieldValue("taskType","DB","0").",".
$record->getFieldValue("in_home","DB","1").",".
$record->getFieldValue("color","DB","NULL").",".
$record->getFieldValue("vacancy_status","DB","NULL").",".
$record->getFieldValue("etat_type","DB","NULL").",".
$record->getFieldValue("etat_next","DB","NULL").",".
$record->getFieldValue("is_short_list","DB","NULL").",".
$record->getFieldValue("is_default","DB","NULL").")"; ?>