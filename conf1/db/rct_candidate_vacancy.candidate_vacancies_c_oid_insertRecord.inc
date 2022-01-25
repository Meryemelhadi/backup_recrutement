<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_vacancy_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").")"; ?>