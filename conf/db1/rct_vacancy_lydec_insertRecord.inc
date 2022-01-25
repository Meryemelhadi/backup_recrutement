<?php $properties["query"]="INSERT INTO _rct_vacancy_lydec(_oid,_budget_O_N,_budget,_csp,_cc,_version,_Cout) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("budget_O_N","DB","NULL").",".
$record->getFieldValue("budget","DB","NULL").",".
$record->getFieldValue("csp","DB","NULL").",".
$record->getFieldValue("cc","DB","NULL").",".
$record->getFieldValue("version","DB","NULL").",".
$record->getFieldValue("Cout","DB","NULL").")"; ?>