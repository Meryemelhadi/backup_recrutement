<?php $properties["query"]="INSERT INTO _rct_candidate_etat_assoc(_oid,_etat_oid,_vacancy_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").")"; ?>