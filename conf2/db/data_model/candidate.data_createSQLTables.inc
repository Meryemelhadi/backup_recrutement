<?php $properties["query"]=array("CREATE TABLE IF NOT EXISTS _rct_candidate(_oid INT AUTO_INCREMENT NOT NULL,_first_name TEXT,_last_name TEXT,_civility integer,_gender integer,_date_of_birth DATE,_nationality TEXT,_email TEXT,_phone_1 TEXT,_phone_2 TEXT,_mobile TEXT,_address TEXT,_zip TEXT,_country_oid integer,_town_oid TEXT,_cand_channel integer,_hr_manager integer,_etat_oid integer,_category_oid TEXT,_establishment TEXT,_years_of_practice INT,_application_type integer,_keywords TEXT,_src_text text,_profile TEXT,_bachelor_title TEXT,_bachelor_school TEXT,_bachelor_year DATE,_cv_path TEXT,_cl_path TEXT,_available_from DATE,_available_delai TEXT,_salary_min varchar(20),_salary_max varchar(20),_add_date DATETIME,_studies_level TEXT,_creation_date DATETIME,_update_date DATETIME,_update_info_date DATETIME,_reading_state integer,_archive_state integer,_relevance integer,_diploma_type TEXT,_institution TEXT,_diploma TEXT,_provider integer,_vacancies_oid TEXT,_last_employment_start_date DATE,_last_employment_end_date DATE,_last_employment TEXT,_last_training_start_date DATE,_last_training_end_date DATE,_last_training TEXT,_age INT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_keywords(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid),KEY IDX_MAIN (_key))","CREATE TABLE IF NOT EXISTS _rct_employment(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid INT,_employment_end_date DATE,_employment_start_date DATE,_employment_job TEXT,_employment_company TEXT,_employment_content VARCHAR(255),_type integer,_salary_min_exp VARCHAR(15),_salary_max_exp VARCHAR(15),PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_action(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid integer,_user_oid TEXT,_date DATETIME,_action_oid integer,_ref_oid integer,_additional_infos TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_school(_oid INT AUTO_INCREMENT NOT NULL,_code TEXT,_label TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_diploma(_oid INT AUTO_INCREMENT NOT NULL,_code TEXT,_label TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_education(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid INT,_diploma TEXT,_diploma_type TEXT,_institution TEXT,_date DATE,_description VARCHAR(255),PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_language(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid INT,_lang TEXT,_language_level integer,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_read_state(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid INT,_user_oid INT,_read_time DATETIME,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_client(_oid INT AUTO_INCREMENT NOT NULL,_date DATETIME,_proposed_by TEXT,_proposed_to TEXT,_candidate_oid INT,_comment TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_proposed_to(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_comment(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid integer,_user_oid integer,_date DATETIME,_comment TEXT,PRIMARY KEY(_oid))",); ?>