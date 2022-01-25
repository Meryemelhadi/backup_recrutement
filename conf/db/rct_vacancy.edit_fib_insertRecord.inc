<?php $properties["query"]="INSERT INTO _rct_vacancy(_oid,_subsidiary_oid,_establishment,_service_oid,_duty_station_oid,_work_schedule,_years_of_practice,_years_of_practice_max,_suited_diplomas,_companies_having_same_profile,_recruitment_reasons,_technical_qualifications,_behavioral_qualifications,_mission_definitions,_organisme_definitions,_mission_means) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("subsidiary_oid","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("service_oid","DB","NULL").",".
$record->getFieldValue("duty_station_oid","DB","NULL").",".
$record->getFieldValue("work_schedule","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("years_of_practice_max","DB","NULL").",".
$record->getFieldValue("suited_diplomas","DB","NULL").",".
$record->getFieldValue("companies_having_same_profile","DB","NULL").",".
$record->getFieldValue("recruitment_reasons","DB","NULL").",".
$record->getFieldValue("technical_qualifications","DB","NULL").",".
$record->getFieldValue("behavioral_qualifications","DB","NULL").",".
$record->getFieldValue("mission_definitions","DB","NULL").",".
$record->getFieldValue("organisme_definitions","DB","NULL").",".
$record->getFieldValue("mission_means","DB","NULL").")"; ?>