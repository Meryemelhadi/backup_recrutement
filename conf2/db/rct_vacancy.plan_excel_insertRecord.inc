<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_name,_job_email,_budget_O_N,_budget,_opening_date,_csp,_current_step,_cc,_version,_contract_type_oid,_direction,_pole,_cout,_manager_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("job_email","DB","NULL").",".
$record->getFieldValue("budget_O_N","DB","NULL").",".
$record->getFieldValue("budget","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("csp","DB","NULL").",".
$record->getFieldValue("current_step","DB","NULL").",".
$record->getFieldValue("cc","DB","NULL").",".
$record->getFieldValue("version","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("direction","DB","NULL").",".
$record->getFieldValue("pole","DB","NULL").",".
$record->getFieldValue("cout","DB","NULL").",".
$record->getFieldValue("manager_oid","DB","NULL").")"; ?>