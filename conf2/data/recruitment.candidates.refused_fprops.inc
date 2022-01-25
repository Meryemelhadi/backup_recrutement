<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'expression','value'=>'{field.object:oid}','isKey'=>'secondary','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_candidate_oid','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'assoc_oid','type'=>'text','isKey'=>'secondary','label'=>'assoc_oid','srcName'=>'assoc_oid','ufname'=>'_assoc_oid','qname'=>'rct_candidate_assoc_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'age','label'=>'age','type'=>'text','is_transient'=>true,'srcName'=>'age','ufname'=>'_age','qname'=>'rct_candidate_age','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'town_name','label'=>'town_name','type'=>'text','is_transient'=>true,'srcName'=>'town_name','ufname'=>'_town_name','qname'=>'rct_candidate_town_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'diploma_type','label'=>'diploma_type','type'=>'text','is_transient'=>true,'srcName'=>'diploma_type','ufname'=>'_diploma_type','qname'=>'rct_candidate_diploma_type','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'institution','label'=>'institution','type'=>'text','is_transient'=>true,'srcName'=>'institution','ufname'=>'_institution','qname'=>'rct_candidate_institution','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'cv_path','label'=>'cv_path','type'=>'text','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'years_of_practice','label'=>'years_of_practice','type'=>'text','srcName'=>'years_of_practice','ufname'=>'_years_of_practice','qname'=>'rct_candidate_years_of_practice','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'keywords','label'=>'keywords','type'=>'text','multiLines'=>'auto','show'=>false,'srcName'=>'keywords','ufname'=>'_keywords','qname'=>'rct_candidate_keywords','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'summary_keywords','label'=>'summary_keywords','type'=>'expression','field'=>'profile','control_html'=>'summary','srcName'=>'summary_keywords','ufname'=>'_summary_keywords','qname'=>'rct_candidate_summary_keywords','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rating','label'=>'rating','type'=>'text','srcName'=>'rating','ufname'=>'_rating','qname'=>'rct_candidate_rating','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'status','label'=>'status','type'=>'text_choice','list'=>'recruitment.candidate_vacancy_action','control'=>'select','sqltype'=>'integer','srcName'=>'status','ufname'=>'_status','qname'=>'rct_candidate_status','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'is_visible','label'=>'is_visible','type'=>'text_choice','list'=>'recruitment.boolean_list','control'=>'checkbox','sqltype'=>'integer','multiple'=>false,'default'=>'0','isKey'=>'secondary','srcName'=>'is_visible','ufname'=>'_is_visible','qname'=>'rct_candidate_is_visible','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'read_state','label'=>'read_state','type'=>'text','srcName'=>'read_state','ufname'=>'_read_state','qname'=>'rct_candidate_read_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_read_state','label'=>'user_read_state','type'=>'text','srcName'=>'user_read_state','ufname'=>'_user_read_state','qname'=>'rct_candidate_user_read_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'add_date','label'=>'add_date','type'=>'datetime','srcName'=>'add_date','ufname'=>'_add_date','qname'=>'rct_candidate_add_date',),
array('name'=>'studies_level','label'=>'studies_level','type'=>'text','srcName'=>'studies_level','ufname'=>'_studies_level','qname'=>'rct_candidate_studies_level','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'creation_date','label'=>'creation_date','type'=>'datetime','srcName'=>'creation_date','ufname'=>'_creation_date','qname'=>'rct_candidate_creation_date',),
array('name'=>'update_date','label'=>'update_date','type'=>'datetime','srcName'=>'update_date','ufname'=>'_update_date','qname'=>'rct_candidate_update_date',),
array('name'=>'last_employment_summary','label'=>'last_employment_summary','type'=>'expression','field'=>'last_employment','control_html'=>'summary','srcName'=>'last_employment_summary','ufname'=>'_last_employment_summary','qname'=>'rct_candidate_last_employment_summary','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_employment_start_date','label'=>'last_employment_start_date','type'=>'date','srcName'=>'last_employment_start_date','ufname'=>'_last_employment_start_date','qname'=>'rct_candidate_last_employment_start_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_employment_end_date','label'=>'last_employment_end_date','type'=>'date','srcName'=>'last_employment_end_date','ufname'=>'_last_employment_end_date','qname'=>'rct_candidate_last_employment_end_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_employment','label'=>'last_employment','type'=>'text','srcName'=>'last_employment','ufname'=>'_last_employment','qname'=>'rct_candidate_last_employment','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_training_start_date','label'=>'last_training_start_date','type'=>'date','srcName'=>'last_training_start_date','ufname'=>'_last_training_start_date','qname'=>'rct_candidate_last_training_start_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_training_end_date','label'=>'last_training_end_date','type'=>'date','srcName'=>'last_training_end_date','ufname'=>'_last_training_end_date','qname'=>'rct_candidate_last_training_end_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'last_training_summary','label'=>'last_training_summary','type'=>'expression','field'=>'last_training','control_html'=>'summary','srcName'=>'last_training_summary','ufname'=>'_last_training_summary','qname'=>'rct_candidate_last_training_summary','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_training','label'=>'last_training','type'=>'text','srcName'=>'last_training','ufname'=>'_last_training','qname'=>'rct_candidate_last_training','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'relevance','label'=>'relevance','type'=>'text_choice','list'=>'recruitment.relevance','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'relevance','ufname'=>'_relevance','qname'=>'rct_candidate_relevance','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'etat_oid','label'=>'etat_oid','type'=>'text','is_transient'=>true,'srcName'=>'etat_oid','ufname'=>'_etat_oid','qname'=>'rct_candidate_etat_oid','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'etat_color','label'=>'etat_color','type'=>'text','is_transient'=>true,'srcName'=>'etat_color','ufname'=>'_etat_color','qname'=>'rct_candidate_etat_color','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'provider','label'=>'provider','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_provider.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'provider','ufname'=>'_provider','qname'=>'rct_candidate_provider','list'=>'provider','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'profile','prompt'=>'profile ...','label'=>'profile','type'=>'text_choice','control'=>'facebook_list','multiple'=>true,'ds'=>'db:rct_keyword.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'key','csv_sep'=>',','srcName'=>'profile','ufname'=>'_profile','qname'=>'rct_candidate_profile','list'=>'profile','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'viewers','label'=>'viewers','type'=>'records','ds'=>'db:rct_candidate_read_state.by_candidate_oid','ds_record'=>'db:rct_candidate_read_state.by_candidate_oid','key'=>'oid','fkey'=>'candidate_oid','view'=>'recruitment.candidates.components.viewers','edit_view'=>'recruitment.candidates.components.viewers','srcName'=>'viewers','ufname'=>'_viewers','qname'=>'rct_candidate_viewers','is_transient'=>true,),
array('name'=>'comment','label'=>'comment','type'=>'records','ds'=>'db:rct_candidate_comment.by_candidate_oid','ds_record'=>'db:rct_candidate_comment.by_candidate_oid','key'=>'oid','fkey'=>'candidate_oid','view'=>'recruitment.candidates.components.comments','edit_view'=>'recruitment.candidates.components.comments','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_candidate_comment','is_transient'=>true,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','assoc_oid'=>'assoc_oid','_assoc_oid'=>'assoc_oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','age'=>'age','_age'=>'age','town_name'=>'town_name','_town_name'=>'town_name','diploma_type'=>'diploma_type','_diploma_type'=>'diploma_type','institution'=>'institution','_institution'=>'institution','cv_path'=>'cv_path','_cv_path'=>'cv_path','years_of_practice'=>'years_of_practice','_years_of_practice'=>'years_of_practice','keywords'=>'keywords','_keywords'=>'keywords','summary_keywords'=>'summary_keywords','_summary_keywords'=>'summary_keywords','rating'=>'rating','_rating'=>'rating','status'=>'status','_status'=>'status','is_visible'=>'is_visible','_is_visible'=>'is_visible','read_state'=>'read_state','_read_state'=>'read_state','user_read_state'=>'user_read_state','_user_read_state'=>'user_read_state','add_date'=>'add_date','_add_date'=>'add_date','studies_level'=>'studies_level','_studies_level'=>'studies_level','creation_date'=>'creation_date','_creation_date'=>'creation_date','update_date'=>'update_date','_update_date'=>'update_date','last_employment_summary'=>'last_employment_summary','_last_employment_summary'=>'last_employment_summary','last_employment_start_date'=>'last_employment_start_date','_last_employment_start_date'=>'last_employment_start_date','last_employment_end_date'=>'last_employment_end_date','_last_employment_end_date'=>'last_employment_end_date','last_employment'=>'last_employment','_last_employment'=>'last_employment','last_training_start_date'=>'last_training_start_date','_last_training_start_date'=>'last_training_start_date','last_training_end_date'=>'last_training_end_date','_last_training_end_date'=>'last_training_end_date','last_training_summary'=>'last_training_summary','_last_training_summary'=>'last_training_summary','last_training'=>'last_training','_last_training'=>'last_training','relevance'=>'relevance','_relevance'=>'relevance','etat_oid'=>'etat_oid','_etat_oid'=>'etat_oid','etat_color'=>'etat_color','_etat_color'=>'etat_color','provider'=>'provider','_provider'=>'provider','profile'=>'profile','_profile'=>'profile','viewers'=>'viewers','_viewers'=>'viewers','comment'=>'comment','_comment'=>'comment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'recruitment.candidates.refused','handler'=>'lib.recruitment.vacancies.records.candidates.refused_list','table'=>'_rct_candidate');
 ?>