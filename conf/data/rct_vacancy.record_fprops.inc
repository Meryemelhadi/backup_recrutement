<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'cand_channel','label'=>'cand_channel','type'=>'text_choice','prompt'=>'cand_channel...','multiple'=>false,'control'=>'select','ds'=>'db:rct_channel.ds_list@recruitment','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'cand_channel','ufname'=>'_cand_channel','qname'=>'rct_vacancy_cand_channel','list'=>'cand_channel','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'job_email','label'=>'job_email','type'=>'text','srcName'=>'job_email','ufname'=>'_job_email','qname'=>'rct_vacancy_job_email','size'=>'100','multiLines'=>false,'onSubmitCheck'=>"checkReg('%3\$s',%1\$s.%2\$s,%4\$s,'^[0-9a-zA-Z_.-]+@[0-9a-zA-Z_.-]+\.[0-9a-zA-Z_.-]+','wrong email syntax')",),
array('name'=>'announce_date','label'=>'announce_date','type'=>'date','srcName'=>'announce_date','ufname'=>'_announce_date','qname'=>'rct_vacancy_announce_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'closing_announce_date','label'=>'closing_announce_date','type'=>'date','srcName'=>'closing_announce_date','ufname'=>'_closing_announce_date','qname'=>'rct_vacancy_closing_announce_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'opening_date','label'=>'opening_date','type'=>'datetime','format'=>'%d %B %Y','srcName'=>'opening_date','ufname'=>'_opening_date','qname'=>'rct_vacancy_opening_date',),
array('name'=>'closing_date','label'=>'closing_date','type'=>'datetime','format'=>'%d %B %Y','srcName'=>'closing_date','ufname'=>'_closing_date','qname'=>'rct_vacancy_closing_date',),
array('name'=>'manager_oid','label'=>'manager_oid','type'=>'text_choice','srcName'=>'manager_oid','ufname'=>'_manager_oid','qname'=>'rct_vacancy_manager_oid','list'=>'manager_oid','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'client_oid','label'=>'client_oid','type'=>'text_choice_table','srcName'=>'client_oid','ufname'=>'_client_oid','qname'=>'rct_vacancy_client_oid','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'current_step','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.vacancy_step','control'=>'select','sqltype'=>'integer','srcName'=>'current_step','ufname'=>'_current_step','qname'=>'rct_vacancy_current_step','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_progress_level','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'workflow_state','label'=>'workflow_state','type'=>'text','sqltype'=>'integer','srcName'=>'workflow_state','ufname'=>'_workflow_state','qname'=>'rct_vacancy_workflow_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'request_date','label'=>'request_date','type'=>'datetime','srcName'=>'request_date','ufname'=>'_request_date','qname'=>'rct_vacancy_request_date',),
array('name'=>'requested_by','label'=>'requested_by','type'=>'text','sqltype'=>'integer','srcName'=>'requested_by','ufname'=>'_requested_by','qname'=>'rct_vacancy_requested_by','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'validation_state','label'=>'validation_state','type'=>'text_choice','list'=>'recruitment.validation_state','control'=>'select','sqltype'=>'integer','srcName'=>'validation_state','ufname'=>'_validation_state','qname'=>'rct_vacancy_validation_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'archive_state','label'=>'archive_state','type'=>'text_choice','list'=>'recruitment.archive_state','control'=>'select','sqltype'=>'integer','srcName'=>'archive_state','ufname'=>'_archive_state','qname'=>'rct_vacancy_archive_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'type_ao','label'=>'type_ao','type'=>'text_choice','list'=>'recruitment.type_ao','control'=>'select','sqltype'=>'integer','srcName'=>'type_ao','ufname'=>'_type_ao','qname'=>'rct_vacancy_type_ao','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'creator','label'=>'creator','type'=>'text','sqltype'=>'integer','srcName'=>'creator','ufname'=>'_creator','qname'=>'rct_vacancy_creator','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'groups_user_readonly','label'=>'groups_user_readonly','type'=>'text_choice_table','srcName'=>'groups_user_readonly','ufname'=>'_groups_user_readonly','qname'=>'rct_vacancy_groups_user_readonly','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'groups_user_total_control','label'=>'groups_user_total_control','type'=>'text_choice','srcName'=>'groups_user_total_control','ufname'=>'_groups_user_total_control','qname'=>'rct_vacancy_groups_user_total_control','list'=>'groups_user_total_control','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'application_type','label'=>'application_type','type'=>'text_choice','list'=>'recruitment.application_type','control'=>'checkbox','sqltype'=>'char(6)','multiple'=>true,'default'=>'0','srcName'=>'application_type','ufname'=>'_application_type','qname'=>'rct_vacancy_application_type','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'number','label'=>'number','type'=>'text','default'=>'1','srcName'=>'number','ufname'=>'_number','qname'=>'rct_vacancy_number','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'category_oid','label'=>'category_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy_category.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'category_oid','ufname'=>'_category_oid','qname'=>'rct_vacancy_category_oid','list'=>'category_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'contract_type_oid','label'=>'contract_type_oid','type'=>'text_choice_table','control'=>'radio','columns'=>'4','multiple'=>false,'ds'=>'db:rct_contract_type.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'contract_type_oid','ufname'=>'_contract_type_oid','qname'=>'rct_vacancy_contract_type_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'subsidiary_oid','label'=>'subsidiary_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_subsidiary.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'subsidiary_oid','ufname'=>'_subsidiary_oid','qname'=>'rct_vacancy_subsidiary_oid','list'=>'subsidiary_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'service_oid','label'=>'service_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_service.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'service_oid','ufname'=>'_service_oid','qname'=>'rct_vacancy_service_oid','list'=>'service_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'duty_station_oid','label'=>'duty_station_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_duty_station.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'duty_station_oid','ufname'=>'_duty_station_oid','qname'=>'rct_vacancy_duty_station_oid','list'=>'duty_station_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'establishment','label'=>'establishment','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_vacancy_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'recruitment_motivation','label'=>'recruitment_motivation','type'=>'text','srcName'=>'recruitment_motivation','ufname'=>'_recruitment_motivation','qname'=>'rct_vacancy_recruitment_motivation','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'work_schedule','label'=>'work_schedule','type'=>'text','srcName'=>'work_schedule','ufname'=>'_work_schedule','qname'=>'rct_vacancy_work_schedule','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'years_of_practice','type'=>'text','label'=>'years_of_practice','srcName'=>'years_of_practice','ufname'=>'_years_of_practice','qname'=>'rct_vacancy_years_of_practice','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'years_of_practice_max','type'=>'text','label'=>'years_of_practice_max','srcName'=>'years_of_practice_max','ufname'=>'_years_of_practice_max','qname'=>'rct_vacancy_years_of_practice_max','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'suited_diplomas','label'=>'suited_diplomas','type'=>'text','srcName'=>'suited_diplomas','ufname'=>'_suited_diplomas','qname'=>'rct_vacancy_suited_diplomas','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'companies_having_same_profile','label'=>'companies_having_same_profile','type'=>'text','srcName'=>'companies_having_same_profile','ufname'=>'_companies_having_same_profile','qname'=>'rct_vacancy_companies_having_same_profile','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'recruitment_reasons','label'=>'recruitment_reasons','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_recruitment_reason.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','prompt'=>'recruitment_reasons...','srcName'=>'recruitment_reasons','ufname'=>'_recruitment_reasons','qname'=>'rct_vacancy_recruitment_reasons','list'=>'recruitment_reasons','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'technical_qualifications','label'=>'technical_qualifications','type'=>'rich_text','srcName'=>'technical_qualifications','ufname'=>'_technical_qualifications','qname'=>'rct_vacancy_technical_qualifications','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'behavioral_qualifications','label'=>'behavioral_qualifications','type'=>'rich_text','srcName'=>'behavioral_qualifications','ufname'=>'_behavioral_qualifications','qname'=>'rct_vacancy_behavioral_qualifications','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'organisme_definitions','label'=>'organisme_definitions','type'=>'rich_text','srcName'=>'organisme_definitions','ufname'=>'_organisme_definitions','qname'=>'rct_vacancy_organisme_definitions','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'mission_definitions','label'=>'mission_definitions','type'=>'rich_text','srcName'=>'mission_definitions','ufname'=>'_mission_definitions','qname'=>'rct_vacancy_mission_definitions','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'mission_means','label'=>'mission_means','type'=>'rich_text','srcName'=>'mission_means','ufname'=>'_mission_means','qname'=>'rct_vacancy_mission_means','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'mission_start_date','label'=>'mission_start_date','type'=>'date','srcName'=>'mission_start_date','ufname'=>'_mission_start_date','qname'=>'rct_vacancy_mission_start_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'suited_recruitment_date','label'=>'suited_recruitment_date','type'=>'date','srcName'=>'suited_recruitment_date','ufname'=>'_suited_recruitment_date','qname'=>'rct_vacancy_suited_recruitment_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'taking_office_date','label'=>'taking_office_date','type'=>'date','srcName'=>'taking_office_date','ufname'=>'_taking_office_date','qname'=>'rct_vacancy_taking_office_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'proposal_acceptance_date','label'=>'proposal_acceptance_date','type'=>'date','srcName'=>'proposal_acceptance_date','ufname'=>'_proposal_acceptance_date','qname'=>'rct_vacancy_proposal_acceptance_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'synthesis_writing_state','label'=>'synthesis_writing_state','type'=>'date','srcName'=>'synthesis_writing_state','ufname'=>'_synthesis_writing_state','qname'=>'rct_vacancy_synthesis_writing_state','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'announcement_broadcasting_state','label'=>'announcement_broadcasting_state','type'=>'date','srcName'=>'announcement_broadcasting_state','ufname'=>'_announcement_broadcasting_state','qname'=>'rct_vacancy_announcement_broadcasting_state','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'internship_title','label'=>'internship_title','type'=>'text','srcName'=>'internship_title','ufname'=>'_internship_title','qname'=>'rct_vacancy_internship_title','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'internship_start','label'=>'internship_start','type'=>'date','srcName'=>'internship_start','ufname'=>'_internship_start','qname'=>'rct_vacancy_internship_start','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'internship_end','label'=>'internship_end','type'=>'date','srcName'=>'internship_end','ufname'=>'_internship_end','qname'=>'rct_vacancy_internship_end','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'executive_committee_presentation','label'=>'executive_committee_presentation','type'=>'text_choice','list'=>'recruitment.boolean_list','control'=>'checkbox','sqltype'=>'integer','multiple'=>false,'default'=>'0','srcName'=>'executive_committee_presentation','ufname'=>'_executive_committee_presentation','qname'=>'rct_vacancy_executive_committee_presentation','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_vacancy_email','size'=>'100','multiLines'=>false,'onSubmitCheck'=>"checkReg('%3\$s',%1\$s.%2\$s,%4\$s,'^[0-9a-zA-Z_.-]+@[0-9a-zA-Z_.-]+\.[0-9a-zA-Z_.-]+','wrong email syntax')",),
array('name'=>'descriptionProfil','label'=>'descriptionProfil','type'=>'rich_text','csslayout'=>'normal-layout','srcName'=>'descriptionProfil','ufname'=>'_descriptionProfil','qname'=>'rct_vacancy_descriptionProfil','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'direction','label'=>'direction','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:directions','ds_format'=>'{field:group_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'direction','ufname'=>'_direction','qname'=>'rct_vacancy_direction','list'=>'direction','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'pole','label'=>'pole','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:poles','ds_format'=>'{field:group_name}','ds_field_value'=>'oid','sqltype'=>'integer','prompt'=>'direction ...','srcName'=>'pole','ufname'=>'_pole','qname'=>'rct_vacancy_pole','list'=>'pole','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'vacancy_lydec','label'=>'vacancy','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'vacancy_lydec','ufname'=>'_vacancy_lydec','qname'=>'rct_vacancy_vacancy_lydec','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'budget_O_N','label'=>'budget_O_N','type'=>'text','srcName'=>'budget_O_N','ufname'=>'_budget_O_N','qname'=>'rct_vacancy_budget_O_N','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'budget','label'=>'budget','type'=>'text','srcName'=>'budget','ufname'=>'_budget','qname'=>'rct_vacancy_budget','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'csp','label'=>'csp','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:directory_csp@admin','ds_format'=>'{field:csp_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'csp','ufname'=>'_csp','qname'=>'rct_vacancy_csp','list'=>'csp','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'cc','label'=>'cc','type'=>'text','srcName'=>'cc','ufname'=>'_cc','qname'=>'rct_vacancy_cc','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'version','label'=>'version','type'=>'text','srcName'=>'version','ufname'=>'_version','qname'=>'rct_vacancy_version','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'Cout','label'=>'cout','type'=>'text','srcName'=>'Cout','ufname'=>'_Cout','qname'=>'rct_vacancy_Cout','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'vacancy_project','label'=>'vacancy_project','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:vacancy_project.list@recruitment','ds_format'=>'{field:name}','default'=>'0','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'vacancy_project','ufname'=>'_vacancy_project','qname'=>'rct_vacancy_vacancy_project','list'=>'vacancy_project','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'app_connected','label'=>'app_connected','type'=>'text_choice','srcName'=>'app_connected','ufname'=>'_app_connected','qname'=>'rct_vacancy_app_connected','list'=>'app_connected','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'salary_min','label'=>'salary_min','type'=>'text','srcName'=>'salary_min','ufname'=>'_salary_min','qname'=>'rct_vacancy_salary_min','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'salary_max','label'=>'salary_max','type'=>'text','srcName'=>'salary_max','ufname'=>'_salary_max','qname'=>'rct_vacancy_salary_max','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'salary_type','label'=>'salary_type','type'=>'text_choice','list'=>'recruitment.salary_type','control'=>'select','sqltype'=>'integer','srcName'=>'salary_type','ufname'=>'_salary_type','qname'=>'rct_vacancy_salary_type','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'evaluation_criteria','label'=>'evaluation_criteria','type'=>'text_choice','ds'=>'db:rct_interview_default_criteria.ds_list@recruitment','control'=>'checkbox','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'varchar(255)','controlLayout'=>'table','columns'=>'2','prompt'=>'select criteria ...','multiple'=>true,'srcName'=>'evaluation_criteria','ufname'=>'_evaluation_criteria','qname'=>'rct_vacancy_evaluation_criteria','list'=>'evaluation_criteria','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'offers_list','label'=>'offers_list','type'=>'records','ds'=>'db:rct_vacancy_provider.list','ds_record'=>'db:rct_vacancy_provider.record','key'=>'oid','fkey'=>'vacancy_oid','view'=>'recruitment.vacancies.components.offer','edit_view'=>'recruitment.vacancies.components.offer','srcName'=>'offers_list','ufname'=>'_offers_list','qname'=>'rct_vacancy_offers_list','is_transient'=>true,),
array('name'=>'sector_oid','label'=>'sector_oid','type'=>'text_choice_table','list'=>'product_range','prompt'=>'sector_oid...','multiple'=>true,'control'=>'facebook_list','ds'=>'db:rct_job_sector.list@recruitment3','ds_link'=>'rct_vacancy_sector','ds_format'=>'{field:name}','ds_field_value'=>'oid','srcName'=>'sector_oid','ufname'=>'_sector_oid','qname'=>'rct_vacancy_sector_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'vacancy_success','label'=>'vacancy_success','type'=>'text_choice','list'=>'recruitment.vacancy_success','control'=>'select','sqltype'=>'integer','srcName'=>'vacancy_success','ufname'=>'_vacancy_success','qname'=>'rct_vacancy_vacancy_success','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','code'=>'code','_code'=>'code','name'=>'name','_name'=>'name','cand_channel'=>'cand_channel','_cand_channel'=>'cand_channel','job_email'=>'job_email','_job_email'=>'job_email','announce_date'=>'announce_date','_announce_date'=>'announce_date','closing_announce_date'=>'closing_announce_date','_closing_announce_date'=>'closing_announce_date','opening_date'=>'opening_date','_opening_date'=>'opening_date','closing_date'=>'closing_date','_closing_date'=>'closing_date','manager_oid'=>'manager_oid','_manager_oid'=>'manager_oid','client_oid'=>'client_oid','_client_oid'=>'client_oid','current_step'=>'current_step','_current_step'=>'current_step','progress_level'=>'progress_level','_progress_level'=>'progress_level','workflow_state'=>'workflow_state','_workflow_state'=>'workflow_state','request_date'=>'request_date','_request_date'=>'request_date','requested_by'=>'requested_by','_requested_by'=>'requested_by','validation_state'=>'validation_state','_validation_state'=>'validation_state','archive_state'=>'archive_state','_archive_state'=>'archive_state','type_ao'=>'type_ao','_type_ao'=>'type_ao','creator'=>'creator','_creator'=>'creator','groups_user_readonly'=>'groups_user_readonly','_groups_user_readonly'=>'groups_user_readonly','groups_user_total_control'=>'groups_user_total_control','_groups_user_total_control'=>'groups_user_total_control','application_type'=>'application_type','_application_type'=>'application_type','number'=>'number','_number'=>'number','category_oid'=>'category_oid','_category_oid'=>'category_oid','contract_type_oid'=>'contract_type_oid','_contract_type_oid'=>'contract_type_oid','subsidiary_oid'=>'subsidiary_oid','_subsidiary_oid'=>'subsidiary_oid','service_oid'=>'service_oid','_service_oid'=>'service_oid','duty_station_oid'=>'duty_station_oid','_duty_station_oid'=>'duty_station_oid','establishment'=>'establishment','_establishment'=>'establishment','recruitment_motivation'=>'recruitment_motivation','_recruitment_motivation'=>'recruitment_motivation','work_schedule'=>'work_schedule','_work_schedule'=>'work_schedule','years_of_practice'=>'years_of_practice','_years_of_practice'=>'years_of_practice','years_of_practice_max'=>'years_of_practice_max','_years_of_practice_max'=>'years_of_practice_max','suited_diplomas'=>'suited_diplomas','_suited_diplomas'=>'suited_diplomas','companies_having_same_profile'=>'companies_having_same_profile','_companies_having_same_profile'=>'companies_having_same_profile','recruitment_reasons'=>'recruitment_reasons','_recruitment_reasons'=>'recruitment_reasons','technical_qualifications'=>'technical_qualifications','_technical_qualifications'=>'technical_qualifications','behavioral_qualifications'=>'behavioral_qualifications','_behavioral_qualifications'=>'behavioral_qualifications','organisme_definitions'=>'organisme_definitions','_organisme_definitions'=>'organisme_definitions','mission_definitions'=>'mission_definitions','_mission_definitions'=>'mission_definitions','mission_means'=>'mission_means','_mission_means'=>'mission_means','mission_start_date'=>'mission_start_date','_mission_start_date'=>'mission_start_date','suited_recruitment_date'=>'suited_recruitment_date','_suited_recruitment_date'=>'suited_recruitment_date','taking_office_date'=>'taking_office_date','_taking_office_date'=>'taking_office_date','proposal_acceptance_date'=>'proposal_acceptance_date','_proposal_acceptance_date'=>'proposal_acceptance_date','synthesis_writing_state'=>'synthesis_writing_state','_synthesis_writing_state'=>'synthesis_writing_state','announcement_broadcasting_state'=>'announcement_broadcasting_state','_announcement_broadcasting_state'=>'announcement_broadcasting_state','internship_title'=>'internship_title','_internship_title'=>'internship_title','internship_start'=>'internship_start','_internship_start'=>'internship_start','internship_end'=>'internship_end','_internship_end'=>'internship_end','executive_committee_presentation'=>'executive_committee_presentation','_executive_committee_presentation'=>'executive_committee_presentation','email'=>'email','_email'=>'email','descriptionProfil'=>'descriptionProfil','_descriptionProfil'=>'descriptionProfil','direction'=>'direction','_direction'=>'direction','pole'=>'pole','_pole'=>'pole','vacancy_lydec'=>'vacancy_lydec','_vacancy_lydec'=>'vacancy_lydec','budget_O_N'=>'budget_O_N','_budget_O_N'=>'budget_O_N','budget'=>'budget','_budget'=>'budget','csp'=>'csp','_csp'=>'csp','cc'=>'cc','_cc'=>'cc','version'=>'version','_version'=>'version','Cout'=>'Cout','_Cout'=>'Cout','vacancy_project'=>'vacancy_project','_vacancy_project'=>'vacancy_project','app_connected'=>'app_connected','_app_connected'=>'app_connected','salary_min'=>'salary_min','_salary_min'=>'salary_min','salary_max'=>'salary_max','_salary_max'=>'salary_max','salary_type'=>'salary_type','_salary_type'=>'salary_type','evaluation_criteria'=>'evaluation_criteria','_evaluation_criteria'=>'evaluation_criteria','offers_list'=>'offers_list','_offers_list'=>'offers_list','sector_oid'=>'sector_oid','_sector_oid'=>'sector_oid','vacancy_success'=>'vacancy_success','_vacancy_success'=>'vacancy_success',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.record','table'=>'_rct_vacancy');
 ?>