<?php $properties["query"]="INSERT INTO _rct_candidate(_first_name,_last_name,_civility,_email,_vacancies,_creation_date) VALUES(".$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("civility","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("vacancies","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").")"; ?>