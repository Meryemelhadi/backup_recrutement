<?php $properties["fprops"]=array(
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'subsidiary_oid','label'=>'subsidiary_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_subsidiary.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','prompt'=>'subsidiary_oid...','srcName'=>'subsidiary_oid','ufname'=>'_subsidiary_oid','qname'=>'rct_vacancy_subsidiary_oid','list'=>'subsidiary_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'current_step','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.vacancy_step','control'=>'select','sqltype'=>'integer','prompt'=>'current_step ...','value'=>(isset($_REQUEST["current_step"])?$_REQUEST["current_step"]:"0"),'srcName'=>'current_step','ufname'=>'_current_step','qname'=>'rct_vacancy_current_step','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'workflow_state','label'=>'workflow_state','type'=>'text_choice','list'=>'recruitment.workflow_state','control'=>'select','sqltype'=>'integer','srcName'=>'workflow_state','ufname'=>'_workflow_state','qname'=>'rct_vacancy_workflow_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'opening_date','label'=>'opening_date','type'=>'date','srcName'=>'opening_date','ufname'=>'_opening_date','qname'=>'rct_vacancy_opening_date','format'=>'%d %B %Y','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'service_oid','label'=>'service_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_service.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','prompt'=>'service_oid...','srcName'=>'service_oid','ufname'=>'_service_oid','qname'=>'rct_vacancy_service_oid','list'=>'service_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'closing_date','label'=>'closing_date','type'=>'date','format'=>'%d %B %Y','srcName'=>'closing_date','ufname'=>'_closing_date','qname'=>'rct_vacancy_closing_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'establishment','label'=>'establishment','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_vacancy_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'duty_station_oid','label'=>'duty_station_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_duty_station.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','prompt'=>'duty_station_oid...','srcName'=>'duty_station_oid','ufname'=>'_duty_station_oid','qname'=>'rct_vacancy_duty_station_oid','list'=>'duty_station_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'application_type','type'=>'text_choice','list'=>'recruitment.application_type','multiple'=>false,'control'=>'select','sqltype'=>'char(6)','label'=>'application_type','srcName'=>'application_type','ufname'=>'_application_type','qname'=>'rct_vacancy_application_type','default'=>'0','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'contract_type_oid','label'=>'contract_type_oid','type'=>'text_choice_table','control'=>'select','columns'=>'4','multiple'=>false,'ds'=>'db:rct_contract_type.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'contract_type_oid','ufname'=>'_contract_type_oid','qname'=>'rct_vacancy_contract_type_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'category_oid','label'=>'category_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy_category.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'category_oid','ufname'=>'_category_oid','qname'=>'rct_vacancy_category_oid','list'=>'category_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'archive_state','label'=>'archive_state','type'=>'text_choice','list'=>'recruitment.archive_state','control'=>'select','sqltype'=>'integer','value'=>(isset($_REQUEST["archive_state"])?$_REQUEST["archive_state"]:"0"),'srcName'=>'archive_state','ufname'=>'_archive_state','qname'=>'rct_vacancy_archive_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'vacancy_project','label'=>'vacancy_project','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:vacancy_project.list@recruitment','ds_format'=>'{field:name}','default'=>'0','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'vacancy_project','ufname'=>'_vacancy_project','qname'=>'rct_vacancy_vacancy_project','list'=>'vacancy_project','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'app_connected','label'=>'app_connected','type'=>'text_choice','ds'=>'db:app_connected.list@recruitment','control'=>'select','multiple'=>false,'ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'app_connected','ufname'=>'_app_connected','qname'=>'rct_vacancy_app_connected','list'=>'app_connected','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('name'=>'name','_name'=>'name','subsidiary_oid'=>'subsidiary_oid','_subsidiary_oid'=>'subsidiary_oid','current_step'=>'current_step','_current_step'=>'current_step','workflow_state'=>'workflow_state','_workflow_state'=>'workflow_state','opening_date'=>'opening_date','_opening_date'=>'opening_date','code'=>'code','_code'=>'code','service_oid'=>'service_oid','_service_oid'=>'service_oid','progress_level'=>'progress_level','_progress_level'=>'progress_level','closing_date'=>'closing_date','_closing_date'=>'closing_date','establishment'=>'establishment','_establishment'=>'establishment','duty_station_oid'=>'duty_station_oid','_duty_station_oid'=>'duty_station_oid','application_type'=>'application_type','_application_type'=>'application_type','contract_type_oid'=>'contract_type_oid','_contract_type_oid'=>'contract_type_oid','category_oid'=>'category_oid','_category_oid'=>'category_oid','archive_state'=>'archive_state','_archive_state'=>'archive_state','vacancy_project'=>'vacancy_project','_vacancy_project'=>'vacancy_project','app_connected'=>'app_connected','_app_connected'=>'app_connected',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.search','table'=>'_rct_vacancy');
 ?>