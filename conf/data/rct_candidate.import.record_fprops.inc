<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_candidate_name','show'=>false,'multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'civility','label'=>'civility','type'=>'text_choice','list'=>'recruitment.civility@recruitment','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'civility','ufname'=>'_civility','qname'=>'rct_candidate_civility','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'gender','label'=>'gender','type'=>'text_choice','list'=>'recruitment.gender','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'gender','ufname'=>'_gender','qname'=>'rct_candidate_gender','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'available_vacancies','label'=>'available_vacancies','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy.available_vacancies@recruitment','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','is_transient'=>true,'srcName'=>'available_vacancies','ufname'=>'_available_vacancies','qname'=>'rct_candidate_available_vacancies','list'=>'available_vacancies','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'date_of_birth','label'=>'date_of_birth','type'=>'date','srcName'=>'date_of_birth','ufname'=>'_date_of_birth','qname'=>'rct_candidate_date_of_birth','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'nationality','label'=>'nationality','type'=>'text','srcName'=>'nationality','ufname'=>'_nationality','qname'=>'rct_candidate_nationality','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_candidate_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'phone_1','label'=>'phone_1','type'=>'text','srcName'=>'phone_1','ufname'=>'_phone_1','qname'=>'rct_candidate_phone_1','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'phone_2','label'=>'phone_2','type'=>'text','srcName'=>'phone_2','ufname'=>'_phone_2','qname'=>'rct_candidate_phone_2','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'mobile','label'=>'mobile','type'=>'text','srcName'=>'mobile','ufname'=>'_mobile','qname'=>'rct_candidate_mobile','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'address','label'=>'address','type'=>'text','multiLines'=>'auto','size'=>'255','srcName'=>'address','ufname'=>'_address','qname'=>'rct_candidate_address','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'zip','label'=>'zip','type'=>'text','srcName'=>'zip','ufname'=>'_zip','qname'=>'rct_candidate_zip','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'country_oid','label'=>'country_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:directory_country.ds_list','ds_format'=>'{field:country_name}','ds_field_value'=>'oid','srcName'=>'country_oid','ufname'=>'_country_oid','qname'=>'rct_candidate_country_oid','sqltype'=>'integer','list'=>'country_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'town_oid','label'=>'town_oid','type'=>'text','srcName'=>'town_oid','ufname'=>'_town_oid','qname'=>'rct_candidate_town_oid','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'mobility_town_oid','label'=>'mobility_town_oid','type'=>'text','srcName'=>'mobility_town_oid','ufname'=>'_mobility_town_oid','qname'=>'rct_candidate_mobility_town_oid','prompt'=>'mobility_town_oid ...','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'category_oid','label'=>'category_oid','type'=>'text_choice_table','prompt'=>'category_oid...','multiple'=>false,'control'=>'select','ds'=>'db:rct_candidate_category.list@recruitment','ds_link'=>'rct_candidate_category_assoc@recruitment','ds_format'=>'{field:name}','ds_field_value'=>'oid','srcName'=>'category_oid','ufname'=>'_category_oid','qname'=>'rct_candidate_category_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'years_of_practice','label'=>'years_of_practice','type'=>'text','srcName'=>'years_of_practice','ufname'=>'_years_of_practice','qname'=>'rct_candidate_years_of_practice','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'application_type','label'=>'application_type','type'=>'text_choice','list'=>'recruitment.application_type@recruitment','control'=>'checkbox','sqltype'=>'integer','multiple'=>false,'srcName'=>'application_type','ufname'=>'_application_type','qname'=>'rct_candidate_application_type','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'keywords','label'=>'keywords','type'=>'text','multiLines'=>'auto','srcName'=>'keywords','ufname'=>'_keywords','qname'=>'rct_candidate_keywords','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'profile','label'=>'profile','type'=>'text','multiLines'=>'auto','size'=>'255','srcName'=>'profile','ufname'=>'_profile','qname'=>'rct_candidate_profile','prompt'=>'category_oid...','multiple'=>false,'control'=>'select','ds'=>'db:rct_candidate_category.list@recruitment','ds_link'=>'rct_candidate_category_assoc','ds_format'=>'{field:name}','ds_field_value'=>'key','csv_sep'=>',','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'tag','label'=>'tag','type'=>'text','multiLines'=>'auto','size'=>'255','srcName'=>'tag','ufname'=>'_tag','qname'=>'rct_candidate_tag','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'src_text','label'=>'src_text','type'=>'text','show'=>false,'sqltype'=>'text','srcName'=>'src_text','ufname'=>'_src_text','qname'=>'rct_candidate_src_text','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'studies_level','label'=>'studies_level','type'=>'text','srcName'=>'studies_level','ufname'=>'_studies_level','qname'=>'rct_candidate_studies_level','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'bachelor_title','label'=>'bachelor_title','type'=>'text','srcName'=>'bachelor_title','ufname'=>'_bachelor_title','qname'=>'rct_candidate_bachelor_title','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'bachelor_school','label'=>'bachelor_school','type'=>'text','srcName'=>'bachelor_school','ufname'=>'_bachelor_school','qname'=>'rct_candidate_bachelor_school','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'bachelor_year','label'=>'bachelor_year','type'=>'date','control'=>'date_Y','onSubmitCheck'=>"",'srcName'=>'bachelor_year','ufname'=>'_bachelor_year','qname'=>'rct_candidate_bachelor_year',),
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','isFile'=>'true',),
array('name'=>'cl_path','label'=>'cl_path','type'=>'file','srcName'=>'cl_path','ufname'=>'_cl_path','qname'=>'rct_candidate_cl_path','isFile'=>'true',),
array('name'=>'add_date','label'=>'add_date','type'=>'datetime','default'=>'now','srcName'=>'add_date','ufname'=>'_add_date','qname'=>'rct_candidate_add_date',),
array('name'=>'update_date','label'=>'update_date','type'=>'datetime','default'=>'now','srcName'=>'update_date','ufname'=>'_update_date','qname'=>'rct_candidate_update_date',),
array('name'=>'update_info_date','label'=>'update_info_date','type'=>'datetime','default'=>'now','srcName'=>'update_info_date','ufname'=>'_update_info_date','qname'=>'rct_candidate_update_info_date',),
array('name'=>'archive_state','label'=>'archive_state','type'=>'text_choice','list'=>'recruitment.archive_state@recruitment','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'archive_state','ufname'=>'_archive_state','qname'=>'rct_candidate_archive_state','default'=>'0','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'relevance','label'=>'relevance','type'=>'text_choice','list'=>'recruitment.relevance@recruitment','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'relevance','ufname'=>'_relevance','qname'=>'rct_candidate_relevance','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'cand_channel','label'=>'cand_channel','type'=>'text_choice','prompt'=>'cand_channel...','multiple'=>false,'control'=>'select','ds'=>'db:rct_channel.ds_list@recruitment','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'cand_channel','ufname'=>'_cand_channel','qname'=>'rct_candidate_cand_channel','list'=>'cand_channel','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'establishment','label'=>'establishment','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_candidate_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'md5_cv_ori','label'=>'md5_cv_ori','type'=>'text','size'=>'40','sqltype'=>'varchar(40)','srcName'=>'md5_cv_ori','ufname'=>'_md5_cv_ori','qname'=>'rct_candidate_md5_cv_ori','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'md5_cv_pdf','label'=>'md5_cv_pdf','type'=>'text','size'=>'40','sqltype'=>'varchar(40)','srcName'=>'md5_cv_pdf','ufname'=>'_md5_cv_pdf','qname'=>'rct_candidate_md5_cv_pdf','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'diploma','label'=>'diploma','type'=>'text','srcName'=>'diploma','ufname'=>'_diploma','qname'=>'rct_candidate_diploma','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'salary_min','label'=>'salary_min','type'=>'text','size'=>'15','prompt'=>'Min','srcName'=>'salary_min','ufname'=>'_salary_min','qname'=>'rct_candidate_salary_min','sqltype'=>'varchar(20)','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'salary_current','label'=>'income','type'=>'text','size'=>'20','sqltype'=>'varchar(20)','srcName'=>'salary_current','ufname'=>'_salary_current','qname'=>'rct_candidate_salary_current','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'available_delai','type'=>'text_choice','control'=>'select','list'=>'available_delai','label'=>'available_delai','srcName'=>'available_delai','ufname'=>'_available_delai','qname'=>'rct_candidate_available_delai','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','name'=>'name','_name'=>'name','civility'=>'civility','_civility'=>'civility','gender'=>'gender','_gender'=>'gender','available_vacancies'=>'available_vacancies','_available_vacancies'=>'available_vacancies','date_of_birth'=>'date_of_birth','_date_of_birth'=>'date_of_birth','nationality'=>'nationality','_nationality'=>'nationality','email'=>'email','_email'=>'email','phone_1'=>'phone_1','_phone_1'=>'phone_1','phone_2'=>'phone_2','_phone_2'=>'phone_2','mobile'=>'mobile','_mobile'=>'mobile','address'=>'address','_address'=>'address','zip'=>'zip','_zip'=>'zip','country_oid'=>'country_oid','_country_oid'=>'country_oid','town_oid'=>'town_oid','_town_oid'=>'town_oid','mobility_town_oid'=>'mobility_town_oid','_mobility_town_oid'=>'mobility_town_oid','category_oid'=>'category_oid','_category_oid'=>'category_oid','years_of_practice'=>'years_of_practice','_years_of_practice'=>'years_of_practice','application_type'=>'application_type','_application_type'=>'application_type','keywords'=>'keywords','_keywords'=>'keywords','profile'=>'profile','_profile'=>'profile','tag'=>'tag','_tag'=>'tag','src_text'=>'src_text','_src_text'=>'src_text','studies_level'=>'studies_level','_studies_level'=>'studies_level','bachelor_title'=>'bachelor_title','_bachelor_title'=>'bachelor_title','bachelor_school'=>'bachelor_school','_bachelor_school'=>'bachelor_school','bachelor_year'=>'bachelor_year','_bachelor_year'=>'bachelor_year','cv_path'=>'cv_path','_cv_path'=>'cv_path','cl_path'=>'cl_path','_cl_path'=>'cl_path','add_date'=>'add_date','_add_date'=>'add_date','update_date'=>'update_date','_update_date'=>'update_date','update_info_date'=>'update_info_date','_update_info_date'=>'update_info_date','archive_state'=>'archive_state','_archive_state'=>'archive_state','relevance'=>'relevance','_relevance'=>'relevance','cand_channel'=>'cand_channel','_cand_channel'=>'cand_channel','establishment'=>'establishment','_establishment'=>'establishment','md5_cv_ori'=>'md5_cv_ori','_md5_cv_ori'=>'md5_cv_ori','md5_cv_pdf'=>'md5_cv_pdf','_md5_cv_pdf'=>'md5_cv_pdf','diploma'=>'diploma','_diploma'=>'diploma','salary_min'=>'salary_min','_salary_min'=>'salary_min','salary_current'=>'salary_current','_salary_current'=>'salary_current','available_delai'=>'available_delai','_available_delai'=>'available_delai',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.import.record','table'=>'_rct_candidate');
 ?>