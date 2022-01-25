<?php $properties["query"]="INSERT INTO _rct_candidate_vacancy(_oid,_vacancy_oid,_contrat_signing,_integration_plan,_integration_note,_hire_date) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("vacancy_oid","DB","NULL").",".
$record->getFieldValue("contrat_signing","DB","0").",".
$record->getFieldValue("integration_plan","DB","0").",".
$record->getFieldValue("integration_note","DB","0").",".
$record->getFieldValue("hire_date","DB","NOW()").")"; ?>