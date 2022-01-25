<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_contrat_signing) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("contrat_signing","DB","0").")"; ?>