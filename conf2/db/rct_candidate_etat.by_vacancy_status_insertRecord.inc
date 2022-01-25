<?php $properties["query"]="INSERT INTO _rct_candidate_etat(_oid,_name,_vacancy_status) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("vacancy_status","DB","NULL").")"; ?>