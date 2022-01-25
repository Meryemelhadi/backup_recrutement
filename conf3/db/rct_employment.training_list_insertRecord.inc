<?php $properties["query"]="INSERT INTO _rct_employment(_oid,_candidate_oid,_employment_end_date,_employment_start_date,_employment_job,_employment_company,_employment_content,_type,_salary_min_exp,_salary_max_exp) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("employment_end_date","DB","NOW()").",".
$record->getFieldValue("employment_start_date","DB","NOW()").",".
$record->getFieldValue("employment_job","DB","NULL").",".
$record->getFieldValue("employment_company","DB","NULL").",".
$record->getFieldValue("employment_content","DB","NULL").",".
$record->getFieldValue("type","DB","NULL").",".
$record->getFieldValue("salary_min_exp","DB","NULL").",".
$record->getFieldValue("salary_max_exp","DB","NULL").")"; ?>