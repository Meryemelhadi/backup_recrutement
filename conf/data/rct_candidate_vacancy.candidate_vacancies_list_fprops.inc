<?php $properties["fprops"]=array(
array('name'=>'rct_candidate_vacancy_oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'rct_candidate_vacancy_oid','alias'=>'oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('table'=>'rct_vacancy_readonly','name'=>'rct_vacancy_readonly_key','type'=>'text','label'=>'key','srcName'=>'key','ufname'=>'rct_vacancy_readonly_key','alias'=>'key_readonly','qname'=>'rct_vacancy_readonly_key','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('table'=>'rct_vacancy_total_control','name'=>'rct_vacancy_total_control_key','type'=>'text','label'=>'key','srcName'=>'key','ufname'=>'rct_vacancy_total_control_key','alias'=>'key_total_control','qname'=>'rct_vacancy_total_control_key','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'rct_candidate_vacancy_manager_oid','label'=>'manager_oid','type'=>'text_choice','prompt'=>'manager_oid...','multiple'=>false,'control'=>'select','ds'=>'db:user.ds_list_all@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'manager_oid','ufname'=>'rct_candidate_vacancy_manager_oid','qname'=>'rct_candidate_vacancy_manager_oid','list'=>'manager_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'rct_candidate_vacancy_name','alias'=>'name','qname'=>'rct_candidate_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rct_candidate_vacancy_number','label'=>'number','type'=>'text','srcName'=>'number','ufname'=>'rct_candidate_vacancy_number','qname'=>'rct_candidate_vacancy_number','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'rct_candidate_vacancy_code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'rct_candidate_vacancy_code','qname'=>'rct_candidate_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rct_candidate_vacancy_category_oid','label'=>'category_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy_category.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'category_oid','ufname'=>'rct_candidate_vacancy_category_oid','qname'=>'rct_candidate_vacancy_category_oid','list'=>'category_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_contract_type_oid','label'=>'contract_type_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_contract_type.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'contract_type_oid','ufname'=>'rct_candidate_vacancy_contract_type_oid','qname'=>'rct_candidate_vacancy_contract_type_oid','list'=>'contract_type_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_subsidiary_oid','label'=>'subsidiary_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_subsidiary.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'subsidiary_oid','ufname'=>'rct_candidate_vacancy_subsidiary_oid','qname'=>'rct_candidate_vacancy_subsidiary_oid','list'=>'subsidiary_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_establishment','label'=>'establishment','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'rct_candidate_vacancy_establishment','qname'=>'rct_candidate_vacancy_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_service_oid','label'=>'service_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_service.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'service_oid','ufname'=>'rct_candidate_vacancy_service_oid','qname'=>'rct_candidate_vacancy_service_oid','list'=>'service_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_duty_station_oid','label'=>'duty_station_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_duty_station.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'duty_station_oid','ufname'=>'rct_candidate_vacancy_duty_station_oid','qname'=>'rct_candidate_vacancy_duty_station_oid','list'=>'duty_station_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_current_step','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.vacancy_step','control'=>'select','sqltype'=>'integer','srcName'=>'current_step','ufname'=>'rct_candidate_vacancy_current_step','qname'=>'rct_candidate_vacancy_current_step','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'rct_candidate_vacancy_progress_level','qname'=>'rct_candidate_vacancy_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_progress_level_meta','label'=>'progress_level_meta','type'=>'expression','field'=>'progress_level','key'=>'oid','control_html'=>'progress_level','srcName'=>'progress_level_meta','ufname'=>'rct_candidate_vacancy_progress_level_meta','qname'=>'rct_candidate_vacancy_progress_level_meta','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rct_candidate_vacancy_application_type','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.application_type','control'=>'checkbox','sqltype'=>'char(6)','multiple'=>true,'srcName'=>'application_type','ufname'=>'rct_candidate_vacancy_application_type','qname'=>'rct_candidate_vacancy_application_type','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_candidate_vacancy_candidates_count','label'=>'candidates_count','type'=>'text','is_transient'=>true,'srcName'=>'candidates_count','ufname'=>'rct_candidate_vacancy_candidates_count','qname'=>'rct_candidate_vacancy_candidates_count','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'rct_candidate_vacancy_opening_date','label'=>'opening_date','type'=>'datetime','format'=>'%d %B %Y','srcName'=>'opening_date','ufname'=>'rct_candidate_vacancy_opening_date','qname'=>'rct_candidate_vacancy_opening_date',),
array('name'=>'rct_candidate_vacancy_closing_date','label'=>'closing_date','type'=>'datetime','format'=>'%d %B %Y','srcName'=>'closing_date','ufname'=>'rct_candidate_vacancy_closing_date','qname'=>'rct_candidate_vacancy_closing_date',),
array('name'=>'rct_candidate_vacancy_creator','label'=>'creator','type'=>'text','sqltype'=>'integer','srcName'=>'creator','ufname'=>'rct_candidate_vacancy_creator','qname'=>'rct_candidate_vacancy_creator','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'rct_candidate_vacancy_oid','oid'=>'rct_candidate_vacancy_oid','_oid'=>'rct_candidate_vacancy_oid','oid'=>'rct_candidate_vacancy_oid','key'=>'rct_vacancy_readonly_key','key'=>'rct_vacancy_readonly_key','_key'=>'rct_vacancy_readonly_key','key_readonly'=>'rct_vacancy_readonly_key','key'=>'rct_vacancy_total_control_key','key'=>'rct_vacancy_total_control_key','_key'=>'rct_vacancy_total_control_key','key_total_control'=>'rct_vacancy_total_control_key','manager_oid'=>'rct_candidate_vacancy_manager_oid','manager_oid'=>'rct_candidate_vacancy_manager_oid','_manager_oid'=>'rct_candidate_vacancy_manager_oid','name'=>'rct_candidate_vacancy_name','name'=>'rct_candidate_vacancy_name','_name'=>'rct_candidate_vacancy_name','name'=>'rct_candidate_vacancy_name','number'=>'rct_candidate_vacancy_number','number'=>'rct_candidate_vacancy_number','_number'=>'rct_candidate_vacancy_number','code'=>'rct_candidate_vacancy_code','code'=>'rct_candidate_vacancy_code','_code'=>'rct_candidate_vacancy_code','category_oid'=>'rct_candidate_vacancy_category_oid','category_oid'=>'rct_candidate_vacancy_category_oid','_category_oid'=>'rct_candidate_vacancy_category_oid','contract_type_oid'=>'rct_candidate_vacancy_contract_type_oid','contract_type_oid'=>'rct_candidate_vacancy_contract_type_oid','_contract_type_oid'=>'rct_candidate_vacancy_contract_type_oid','subsidiary_oid'=>'rct_candidate_vacancy_subsidiary_oid','subsidiary_oid'=>'rct_candidate_vacancy_subsidiary_oid','_subsidiary_oid'=>'rct_candidate_vacancy_subsidiary_oid','establishment'=>'rct_candidate_vacancy_establishment','establishment'=>'rct_candidate_vacancy_establishment','_establishment'=>'rct_candidate_vacancy_establishment','service_oid'=>'rct_candidate_vacancy_service_oid','service_oid'=>'rct_candidate_vacancy_service_oid','_service_oid'=>'rct_candidate_vacancy_service_oid','duty_station_oid'=>'rct_candidate_vacancy_duty_station_oid','duty_station_oid'=>'rct_candidate_vacancy_duty_station_oid','_duty_station_oid'=>'rct_candidate_vacancy_duty_station_oid','current_step'=>'rct_candidate_vacancy_current_step','current_step'=>'rct_candidate_vacancy_current_step','_current_step'=>'rct_candidate_vacancy_current_step','progress_level'=>'rct_candidate_vacancy_progress_level','progress_level'=>'rct_candidate_vacancy_progress_level','_progress_level'=>'rct_candidate_vacancy_progress_level','progress_level_meta'=>'rct_candidate_vacancy_progress_level_meta','progress_level_meta'=>'rct_candidate_vacancy_progress_level_meta','_progress_level_meta'=>'rct_candidate_vacancy_progress_level_meta','application_type'=>'rct_candidate_vacancy_application_type','application_type'=>'rct_candidate_vacancy_application_type','_application_type'=>'rct_candidate_vacancy_application_type','candidates_count'=>'rct_candidate_vacancy_candidates_count','candidates_count'=>'rct_candidate_vacancy_candidates_count','_candidates_count'=>'rct_candidate_vacancy_candidates_count','opening_date'=>'rct_candidate_vacancy_opening_date','opening_date'=>'rct_candidate_vacancy_opening_date','_opening_date'=>'rct_candidate_vacancy_opening_date','closing_date'=>'rct_candidate_vacancy_closing_date','closing_date'=>'rct_candidate_vacancy_closing_date','_closing_date'=>'rct_candidate_vacancy_closing_date','creator'=>'rct_candidate_vacancy_creator','creator'=>'rct_candidate_vacancy_creator','_creator'=>'rct_candidate_vacancy_creator',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.candidate_vacancies_list','table'=>'_rct_candidate_vacancy');
 ?>