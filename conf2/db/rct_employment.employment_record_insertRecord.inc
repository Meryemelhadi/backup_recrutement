<?php $properties["query"]="INSERT INTO _rct_employment(_oid,_candidate_oid,_employment_end_date,_employment_start_date,_employment_content,_type,_salary_min_exp,_salary_max_exp,_employment_job,_employment_company) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("candidate_oid","DB","NULL").",".
$record->getFieldValue("employment_end_date","DB","NOW()").",".
$record->getFieldValue("employment_start_date","DB","NOW()").",".
$record->getFieldValue("employment_content","DB","NULL").",".
"'1',".
$record->getFieldValue("salary_min_exp","DB","NULL").",".
$record->getFieldValue("salary_max_exp","DB","NULL").",".
$record->getFieldValue("employment_job","DB","NULL").",".
$record->getFieldValue("employment_company","DB","NULL").")"; ?>