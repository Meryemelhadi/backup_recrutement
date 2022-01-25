<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','alias'=>'oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'expression','value'=>'{field.object:oid}','isKey'=>'secondary','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_candidate_oid','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'studies_level','label'=>'studies_level','type'=>'text','srcName'=>'studies_level','ufname'=>'_studies_level','qname'=>'rct_candidate_studies_level','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'relevance_rate','label'=>'relevance_rate','type'=>'text','srcName'=>'relevance_rate','ufname'=>'_relevance_rate','qname'=>'rct_candidate_relevance_rate','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'age','label'=>'age','type'=>'text','is_transient'=>true,'srcName'=>'age','ufname'=>'_age','qname'=>'rct_candidate_age','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'town_oid','label'=>'town_oid','type'=>'text','is_transient'=>true,'srcName'=>'town_oid','ufname'=>'_town_oid','qname'=>'rct_candidate_town_oid','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'town_name','label'=>'town_name','type'=>'text','is_transient'=>true,'srcName'=>'town_name','ufname'=>'_town_name','qname'=>'rct_candidate_town_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'zip','label'=>'zip','type'=>'text','is_transient'=>true,'srcName'=>'zip','ufname'=>'_zip','qname'=>'rct_candidate_zip','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','is_transient'=>true,'srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_candidate_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vacancy_name','label'=>'vacancy_name','type'=>'text','is_transient'=>true,'srcName'=>'vacancy_name','ufname'=>'_vacancy_name','qname'=>'rct_candidate_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'vacancy_code','label'=>'vacancy_code','type'=>'text','is_transient'=>true,'srcName'=>'vacancy_code','ufname'=>'_vacancy_code','qname'=>'rct_candidate_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'diploma','label'=>'diploma','type'=>'text','is_transient'=>true,'srcName'=>'diploma','ufname'=>'_diploma','qname'=>'rct_candidate_diploma','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'diploma_type','label'=>'diploma_type','type'=>'text','is_transient'=>true,'srcName'=>'diploma_type','ufname'=>'_diploma_type','qname'=>'rct_candidate_diploma_type','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'institution','label'=>'institution','type'=>'text','is_transient'=>true,'srcName'=>'institution','ufname'=>'_institution','qname'=>'rct_candidate_institution','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','isFile'=>'true',),
array('name'=>'years_of_practice','label'=>'years_of_practice','type'=>'text','srcName'=>'years_of_practice','ufname'=>'_years_of_practice','qname'=>'rct_candidate_years_of_practice','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'profile','prompt'=>'profile ...','label'=>'profile','type'=>'text_choice','control'=>'facebook_list','multiple'=>true,'ds'=>'db:rct_keyword.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'key','csv_sep'=>',','srcName'=>'profile','ufname'=>'_profile','qname'=>'rct_candidate_profile','list'=>'profile','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'summary_keywords','label'=>'summary_keywords','type'=>'expression','field'=>'profile','control_html'=>'summary','srcName'=>'summary_keywords','ufname'=>'_summary_keywords','qname'=>'rct_candidate_summary_keywords','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'read_state','label'=>'read_state','type'=>'text','srcName'=>'read_state','ufname'=>'_read_state','qname'=>'rct_candidate_read_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_read_state','label'=>'user_read_state','type'=>'text','srcName'=>'user_read_state','ufname'=>'_user_read_state','qname'=>'rct_candidate_user_read_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'establishment','label'=>'establishment','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_candidate_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'relevance','label'=>'relevance','type'=>'text_choice','list'=>'recruitment.relevance','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'relevance','ufname'=>'_relevance','qname'=>'rct_candidate_relevance','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'last_employment','label'=>'last_employment','type'=>'text','is_transient'=>true,'srcName'=>'last_employment','ufname'=>'_last_employment','qname'=>'rct_candidate_last_employment','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_employment_summary','label'=>'last_employment_summary','type'=>'expression','field'=>'last_employment','control_html'=>'summary','srcName'=>'last_employment_summary','ufname'=>'_last_employment_summary','qname'=>'rct_candidate_last_employment_summary','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_employment_start_date','label'=>'last_employment_start_date','type'=>'date','is_transient'=>true,'format'=>'%d/%m/%y','srcName'=>'last_employment_start_date','ufname'=>'_last_employment_start_date','qname'=>'rct_candidate_last_employment_start_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_employment_end_date','label'=>'last_employment_end_date','type'=>'date','is_transient'=>true,'format'=>'%d/%m/%y','srcName'=>'last_employment_end_date','ufname'=>'_last_employment_end_date','qname'=>'rct_candidate_last_employment_end_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_training','label'=>'last_training','type'=>'text','is_transient'=>true,'srcName'=>'last_training','ufname'=>'_last_training','qname'=>'rct_candidate_last_training','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'provider','label'=>'provider','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_provider.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'provider','ufname'=>'_provider','qname'=>'rct_candidate_provider','list'=>'provider','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'etat_oid','label'=>'etat_oid','type'=>'text','is_transient'=>true,'srcName'=>'etat_oid','ufname'=>'_etat_oid','qname'=>'rct_candidate_etat_oid','isProp'=>'val','isKey'=>'secondary','sqltype'=>'integer','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_training_summary','label'=>'last_training_summary','type'=>'expression','field'=>'last_training','control_html'=>'summary','srcName'=>'last_training_summary','ufname'=>'_last_training_summary','qname'=>'rct_candidate_last_training_summary','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_training_start_date','label'=>'last_training_start_date','type'=>'date','is_transient'=>true,'format'=>'%d/%m/%y','srcName'=>'last_training_start_date','ufname'=>'_last_training_start_date','qname'=>'rct_candidate_last_training_start_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_training_end_date','label'=>'last_training_end_date','type'=>'date','is_transient'=>true,'format'=>'%d/%m/%y','srcName'=>'last_training_end_date','ufname'=>'_last_training_end_date','qname'=>'rct_candidate_last_training_end_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'category_oid','label'=>'category_oid','type'=>'text','is_transient'=>true,'srcName'=>'category_oid','ufname'=>'_category_oid','qname'=>'rct_candidate_category_oid','prompt'=>'category_oid...','multiple'=>false,'control'=>'select','ds'=>'db:rct_candidate_category.list@recruitment','ds_link'=>'rct_candidate_category_assoc','ds_format'=>'{field:name}','ds_field_value'=>'oid','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'creation_date','label'=>'creation_date','type'=>'datetime','srcName'=>'creation_date','ufname'=>'_creation_date','qname'=>'rct_candidate_creation_date',),
array('name'=>'add_date','label'=>'add_date','type'=>'date','is_transient'=>true,'format'=>'%d/%m/%y','srcName'=>'add_date','ufname'=>'_add_date','qname'=>'rct_candidate_add_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'update_date','label'=>'update_date','type'=>'date','is_transient'=>true,'format'=>'%d/%m/%y','srcName'=>'update_date','ufname'=>'_update_date','qname'=>'rct_candidate_update_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'update_info_date','label'=>'update_info_date','type'=>'datetime','srcName'=>'update_info_date','ufname'=>'_update_info_date','qname'=>'rct_candidate_update_info_date',),
array('name'=>'hr_manager','label'=>'hr_manager','type'=>'text_choice','prompt'=>'hr_manager...','multiple'=>false,'control'=>'select','ds'=>'db:user.ds_list_recruiters@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'hr_manager','ufname'=>'_hr_manager','qname'=>'rct_candidate_hr_manager','list'=>'hr_manager','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'viewers','label'=>'viewers','type'=>'records','ds'=>'db:rct_candidate_read_state.by_candidate_oid','ds_record'=>'db:rct_candidate_read_state.by_candidate_oid','key'=>'oid','fkey'=>'candidate_oid','view'=>'recruitment.candidates.components.viewers','edit_view'=>'recruitment.candidates.components.viewers','srcName'=>'viewers','ufname'=>'_viewers','qname'=>'rct_candidate_viewers','is_transient'=>true,),
array('name'=>'comment','label'=>'comment','type'=>'records','ds'=>'db:rct_candidate_comment.by_candidate_oid','ds_record'=>'db:rct_candidate_comment.by_candidate_oid','key'=>'oid','fkey'=>'candidate_oid','view'=>'recruitment.candidates.components.comments','edit_view'=>'recruitment.candidates.components.comments','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_candidate_comment','is_transient'=>true,),
array('name'=>'etat_color','label'=>'color','type'=>'text','srcName'=>'etat_color','ufname'=>'_etat_color','qname'=>'rct_candidate_etat_color','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','studies_level'=>'studies_level','_studies_level'=>'studies_level','relevance_rate'=>'relevance_rate','_relevance_rate'=>'relevance_rate','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','age'=>'age','_age'=>'age','town_oid'=>'town_oid','_town_oid'=>'town_oid','town_name'=>'town_name','_town_name'=>'town_name','zip'=>'zip','_zip'=>'zip','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','vacancy_name'=>'vacancy_name','_vacancy_name'=>'vacancy_name','vacancy_code'=>'vacancy_code','_vacancy_code'=>'vacancy_code','diploma'=>'diploma','_diploma'=>'diploma','diploma_type'=>'diploma_type','_diploma_type'=>'diploma_type','institution'=>'institution','_institution'=>'institution','cv_path'=>'cv_path','_cv_path'=>'cv_path','years_of_practice'=>'years_of_practice','_years_of_practice'=>'years_of_practice','profile'=>'profile','_profile'=>'profile','summary_keywords'=>'summary_keywords','_summary_keywords'=>'summary_keywords','read_state'=>'read_state','_read_state'=>'read_state','user_read_state'=>'user_read_state','_user_read_state'=>'user_read_state','establishment'=>'establishment','_establishment'=>'establishment','relevance'=>'relevance','_relevance'=>'relevance','last_employment'=>'last_employment','_last_employment'=>'last_employment','last_employment_summary'=>'last_employment_summary','_last_employment_summary'=>'last_employment_summary','last_employment_start_date'=>'last_employment_start_date','_last_employment_start_date'=>'last_employment_start_date','last_employment_end_date'=>'last_employment_end_date','_last_employment_end_date'=>'last_employment_end_date','last_training'=>'last_training','_last_training'=>'last_training','provider'=>'provider','_provider'=>'provider','etat_oid'=>'etat_oid','_etat_oid'=>'etat_oid','val'=>'etat_oid','last_training_summary'=>'last_training_summary','_last_training_summary'=>'last_training_summary','last_training_start_date'=>'last_training_start_date','_last_training_start_date'=>'last_training_start_date','last_training_end_date'=>'last_training_end_date','_last_training_end_date'=>'last_training_end_date','category_oid'=>'category_oid','_category_oid'=>'category_oid','creation_date'=>'creation_date','_creation_date'=>'creation_date','add_date'=>'add_date','_add_date'=>'add_date','update_date'=>'update_date','_update_date'=>'update_date','update_info_date'=>'update_info_date','_update_info_date'=>'update_info_date','hr_manager'=>'hr_manager','_hr_manager'=>'hr_manager','viewers'=>'viewers','_viewers'=>'viewers','comment'=>'comment','_comment'=>'comment','etat_color'=>'etat_color','_etat_color'=>'etat_color',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'recruitment.candidates.list','handler'=>'lib.recruitment.candidates.records.list','table'=>'_rct_candidate');
 ?>