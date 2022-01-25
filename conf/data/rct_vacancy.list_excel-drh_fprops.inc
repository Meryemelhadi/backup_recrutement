<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','alias'=>'name','qname'=>'rct_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'number','label'=>'number','type'=>'text','default'=>'1','srcName'=>'number','ufname'=>'_number','qname'=>'rct_vacancy_number','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'category_oid','label'=>'category_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy_category.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'category_oid','ufname'=>'_category_oid','qname'=>'rct_vacancy_category_oid','list'=>'category_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'contract_type_oid','label'=>'contract_type_oid','type'=>'text_choice_table','control'=>'radio','columns'=>'4','multiple'=>false,'ds'=>'db:rct_contract_type.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'contract_type_oid','ufname'=>'_contract_type_oid','qname'=>'rct_vacancy_contract_type_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'subsidiary_oid','label'=>'subsidiary_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_subsidiary.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'subsidiary_oid','ufname'=>'_subsidiary_oid','qname'=>'rct_vacancy_subsidiary_oid','list'=>'subsidiary_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'establishment','label'=>'establishment','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_vacancy_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'service_oid','label'=>'service_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_service.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'service_oid','ufname'=>'_service_oid','qname'=>'rct_vacancy_service_oid','list'=>'service_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'duty_station_oid','label'=>'duty_station_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_duty_station.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'duty_station_oid','ufname'=>'_duty_station_oid','qname'=>'rct_vacancy_duty_station_oid','list'=>'duty_station_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'current_step','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.vacancy_step','control'=>'select','sqltype'=>'integer','srcName'=>'current_step','ufname'=>'_current_step','qname'=>'rct_vacancy_current_step','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level_meta','label'=>'progress_level_meta','type'=>'expression','field'=>'progress_level','key'=>'oid','control_html'=>'progress_level','srcName'=>'progress_level_meta','ufname'=>'_progress_level_meta','qname'=>'rct_vacancy_progress_level_meta','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'application_type','type'=>'text_choice','list'=>'recruitment.application_type','control'=>'checkbox','sqltype'=>'char(6)','multiple'=>true,'label'=>'application_type','srcName'=>'application_type','ufname'=>'_application_type','qname'=>'rct_vacancy_application_type','default'=>'0','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'candidates_count','label'=>'candidates_count','type'=>'text','is_transient'=>true,'show'=>false,'srcName'=>'candidates_count','ufname'=>'_candidates_count','qname'=>'rct_vacancy_candidates_count','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'opening_date','label'=>'opening_date','type'=>'datetime','format'=>'%d %B %Y','srcName'=>'opening_date','ufname'=>'_opening_date','qname'=>'rct_vacancy_opening_date',),
array('name'=>'closing_date','label'=>'closing_date','type'=>'datetime','format'=>'%d %B %Y','srcName'=>'closing_date','ufname'=>'_closing_date','qname'=>'rct_vacancy_closing_date',),
array('name'=>'creator','label'=>'creator','type'=>'text','sqltype'=>'integer','show'=>false,'srcName'=>'creator','ufname'=>'_creator','qname'=>'rct_vacancy_creator','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','number'=>'number','_number'=>'number','code'=>'code','_code'=>'code','category_oid'=>'category_oid','_category_oid'=>'category_oid','contract_type_oid'=>'contract_type_oid','_contract_type_oid'=>'contract_type_oid','subsidiary_oid'=>'subsidiary_oid','_subsidiary_oid'=>'subsidiary_oid','establishment'=>'establishment','_establishment'=>'establishment','service_oid'=>'service_oid','_service_oid'=>'service_oid','duty_station_oid'=>'duty_station_oid','_duty_station_oid'=>'duty_station_oid','current_step'=>'current_step','_current_step'=>'current_step','progress_level'=>'progress_level','_progress_level'=>'progress_level','progress_level_meta'=>'progress_level_meta','_progress_level_meta'=>'progress_level_meta','application_type'=>'application_type','_application_type'=>'application_type','candidates_count'=>'candidates_count','_candidates_count'=>'candidates_count','opening_date'=>'opening_date','_opening_date'=>'opening_date','closing_date'=>'closing_date','_closing_date'=>'closing_date','creator'=>'creator','_creator'=>'creator',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.list_excel-drh','table'=>'_rct_vacancy');
 ?>