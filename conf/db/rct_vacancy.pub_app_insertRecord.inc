<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_name,_email,_number,_code,_opening_date,_duty_station_oid,_contract_type_oid,_mission_definitions,_organisme_definitions,_descriptionProfil,_behavioral_qualifications,_url,_technical_qualifications,_suited_diplomas,_work_schedule,_years_of_practice,_companies_having_same_profile,_mission_means,_description) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("name","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("number","DB","1").",".
$record->getFieldValue("code","DB","NULL").",".
$record->getFieldValue("opening_date","DB","NOW()").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").",".
$record->getFieldValue("mission_definitions","DB","NULL").",".
$record->getFieldValue("organisme_definitions","DB","NULL").",".
$record->getFieldValue("descriptionProfil","DB","NULL").",".
$record->getFieldValue("behavioral_qualifications","DB","NULL").",".
$record->getFieldValue("url","DB","NULL").",".
$record->getFieldValue("technical_qualifications","DB","NULL").",".
$record->getFieldValue("suited_diplomas","DB","NULL").",".
$record->getFieldValue("work_schedule","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("companies_having_same_profile","DB","NULL").",".
$record->getFieldValue("mission_means","DB","NULL").",".
$record->getFieldValue("description","DB","NULL").")"; ?>