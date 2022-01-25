<?php $properties["query"]=array("CREATE TABLE IF NOT EXISTS _rct_vacancy(_oid INT AUTO_INCREMENT NOT NULL,_code TEXT,_name TEXT,_cand_channel integer,_job_email VARCHAR(100),_announce_date DATE,_closing_announce_date DATE,_opening_date DATETIME,_closing_date DATETIME,_manager_oid TEXT,_client_oid TEXT,_current_step integer,_progress_level integer,_workflow_state integer,_request_date DATETIME,_requested_by integer,_validation_state integer,_archive_state integer,_type_ao integer,_creator integer,_groups_user_readonly TEXT,_groups_user_total_control TEXT,_application_type char(6),_number INT,_category_oid integer,_contract_type_oid integer,_subsidiary_oid integer,_service_oid integer,_duty_station_oid integer,_establishment TEXT,_recruitment_motivation TEXT,_work_schedule TEXT,_years_of_practice INT,_years_of_practice_max INT,_suited_diplomas TEXT,_companies_having_same_profile TEXT,_recruitment_reasons integer,_technical_qualifications TEXT,_behavioral_qualifications TEXT,_organisme_definitions TEXT,_mission_definitions TEXT,_mission_means TEXT,_mission_start_date DATE,_suited_recruitment_date DATE,_taking_office_date DATE,_proposal_acceptance_date DATE,_synthesis_writing_state DATE,_announcement_broadcasting_state DATE,_internship_title TEXT,_internship_start DATE,_internship_end DATE,_executive_committee_presentation integer,_email VARCHAR(100),_descriptionProfil TEXT,_direction integer,_pole integer,_vacancy_lydec integer,_budget_O_N TEXT,_budget TEXT,_csp integer,_cc TEXT,_version TEXT,_Cout TEXT,_vacancy_project integer,_app_connected TEXT,_salary_min TEXT,_salary_max TEXT,_salary_type integer,_evaluation_criteria varchar(255),_sector_oid TEXT,_vacancy_success integer,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_readonly(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid),KEY IDX_MAIN (_key))","CREATE TABLE IF NOT EXISTS _rct_vacancy_total_control(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid),KEY IDX_MAIN (_key))","CREATE TABLE IF NOT EXISTS _rct_vacancy_action(_oid INT AUTO_INCREMENT NOT NULL,_vacancy_oid integer,_user_oid TEXT,_date DATETIME,_action_oid integer,_ref_oid integer,_additional_infos TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_attached_file(_oid INT AUTO_INCREMENT NOT NULL,_vacancy_oid integer,_file_name TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_comment(_oid INT AUTO_INCREMENT NOT NULL,_vacancy_oid integer,_user_oid integer,_date DATETIME,_comment TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_vacancy_comment(_oid INT AUTO_INCREMENT NOT NULL,_vacancy_oid integer,_candidate_oid integer,_user_oid integer,_date DATETIME,_comment TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_vacancy(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid integer,_vacancy_oid integer,_add_date DATETIME,_rating integer,_status integer,_is_visible integer,_cv_source_oid integer,_proposal_acceptance_date DATE,_contrat_signing integer,_hire_date DATE,_integration_plan integer,_integration_note integer,_ci_acceptance_state integer,_ci_acceptance_date DATETIME,_job_acceptance_state integer,_job_acceptance_date DATETIME,_proposal_acceptance_state integer,_integration_date DATE,_etat_oid integer,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_vacancy_action(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid integer,_vacancy_oid integer,_user_oid TEXT,_date DATETIME,_action_oid integer,_ref_oid integer,_additional_infos TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_short_list_vacancy_client(_oid INT AUTO_INCREMENT NOT NULL,_short_list_oid TEXT,_vacancy_oid integer,_proposed_by TEXT,_proposal_date DATETIME,_comment TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_candidate_vacancy_client(_oid INT AUTO_INCREMENT NOT NULL,_candidate_oid TEXT,_vacancy_oid integer,_proposed_by TEXT,_proposal_date DATETIME,_comment TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_manager(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_client(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_sector(_oid INT AUTO_INCREMENT NOT NULL,_key INT,_val INT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_history(_oid INT AUTO_INCREMENT NOT NULL,_date DATETIME,_vacancy_oid integer,_progress_level integer,_progress_level_meta TEXT,PRIMARY KEY(_oid))","CREATE TABLE IF NOT EXISTS _rct_vacancy_provider(_oid INT AUTO_INCREMENT NOT NULL,_provider_oid integer,_active TEXT,_date DATE,_vacancy_oid integer,_ref TEXT,_offer_name TEXT,_id_index VARCHAR(200),_index INT,PRIMARY KEY(_oid))",); ?>