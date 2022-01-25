<?php $properties["query"]="INSERT INTO _rct_actions_candidate_etat(_oid,_name,_service_web,_actif,_etat_candidate) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("service_web","DB","NULL").",".
$record->getFieldValue("actif","DB","NULL").",".
$record->getFieldValue("etat_candidate","DB","NULL").")"; ?>