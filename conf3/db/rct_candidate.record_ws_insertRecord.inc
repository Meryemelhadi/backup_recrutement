<?php $properties["query"]="INSERT INTO _rct_candidate(_oid,_first_name,_last_name,_civility,_gender,_date_of_birth,_nationality,_email,_phone_1,_phone_2,_mobile,_address,_zip,_country_oid,_town_oid,_cand_channel,_hr_manager,_etat_oid,_category_oid,_establishment,_years_of_practice,_application_type,_keywords,_src_text,_profile,_bachelor_title,_bachelor_school,_bachelor_year,_cv_path,_cl_path,_available_from,_available_delai,_salary_min,_salary_max,_add_date,_studies_level,_creation_date,_update_date,_update_info_date,_reading_state,_archive_state,_relevance,_diploma_type,_institution,_diploma,_provider,_vacancies_oid,_last_employment_start_date,_last_employment_end_date,_last_employment,_last_training_start_date,_last_training_end_date,_last_training,_age,_vacancy_name,_contract_type_oid) VALUES(".$record->getFieldValue("oid","DB","NULL").",".
$record->getFieldValue("first_name","DB","NULL").",".
$record->getFieldValue("last_name","DB","NULL").",".
$record->getFieldValue("civility","DB","NULL").",".
$record->getFieldValue("gender","DB","NULL").",".
$record->getFieldValue("date_of_birth","DB","NOW()").",".
$record->getFieldValue("nationality","DB","NULL").",".
$record->getFieldValue("email","DB","NULL").",".
$record->getFieldValue("phone_1","DB","NULL").",".
$record->getFieldValue("phone_2","DB","NULL").",".
$record->getFieldValue("mobile","DB","NULL").",".
$record->getFieldValue("address","DB","NULL").",".
$record->getFieldValue("zip","DB","NULL").",".
$record->getFieldValue("country_oid","DB","NULL").",".
$record->getFieldValue("town_oid","DB","NULL").",".
$record->getFieldValue("cand_channel","DB","NULL").",".
$record->getFieldValue("hr_manager","DB","NULL").",".
$record->getFieldValue("etat_oid","DB","NULL").",".
$record->getFieldValue("category_oid","DB","NULL").",".
$record->getFieldValue("establishment","DB","NULL").",".
$record->getFieldValue("years_of_practice","DB","NULL").",".
$record->getFieldValue("application_type","DB","NULL").",".
$record->getFieldValue("keywords","DB","NULL").",".
$record->getFieldValue("src_text","DB","NULL").",".
$record->getFieldValue("profile","DB","NULL").",".
$record->getFieldValue("bachelor_title","DB","NULL").",".
$record->getFieldValue("bachelor_school","DB","NULL").",".
$record->getFieldValue("bachelor_year","DB","NOW()").",".
$record->getFieldValue("cv_path","DB","NULL").",".
$record->getFieldValue("cl_path","DB","NULL").",".
$record->getFieldValue("available_from","DB","NOW()").",".
$record->getFieldValue("available_delai","DB","NULL").",".
$record->getFieldValue("salary_min","DB","NULL").",".
$record->getFieldValue("salary_max","DB","NULL").",".
$record->getFieldValue("add_date","DB","NOW()").",".
$record->getFieldValue("studies_level","DB","NULL").",".
$record->getFieldValue("creation_date","DB","NOW()").",".
$record->getFieldValue("update_date","DB","NOW()").",".
$record->getFieldValue("update_info_date","DB","NOW()").",".
$record->getFieldValue("reading_state","DB","1").",".
$record->getFieldValue("archive_state","DB","0").",".
$record->getFieldValue("relevance","DB","NULL").",".
$record->getFieldValue("diploma_type","DB","NULL").",".
$record->getFieldValue("institution","DB","NULL").",".
$record->getFieldValue("diploma","DB","NULL").",".
$record->getFieldValue("provider","DB","NULL").",".
$record->getFieldValue("vacancies_oid","DB","NULL").",".
$record->getFieldValue("last_employment_start_date","DB","NOW()").",".
$record->getFieldValue("last_employment_end_date","DB","NOW()").",".
$record->getFieldValue("last_employment","DB","NULL").",".
$record->getFieldValue("last_training_start_date","DB","NOW()").",".
$record->getFieldValue("last_training_end_date","DB","NOW()").",".
$record->getFieldValue("last_training","DB","NULL").",".
$record->getFieldValue("age","DB","NULL").",".
$record->getFieldValue("vacancy_name","DB","NULL").",".
$record->getFieldValue("contract_type_oid","DB","NULL").")"; ?>