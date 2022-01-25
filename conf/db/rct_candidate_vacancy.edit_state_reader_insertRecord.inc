<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_etat_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").")"; ?>