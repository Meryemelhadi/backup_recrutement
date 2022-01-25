<?php $properties["fprops"]=array(
array('name'=>'rct_vacancy_readonly_oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'rct_vacancy_readonly_oid','qname'=>'rct_vacancy_readonly_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'rct_vacancy_readonly_code','label'=>'code','type'=>'text','direction'=>'asc','srcName'=>'code','ufname'=>'rct_vacancy_readonly_code','qname'=>'rct_vacancy_readonly_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rct_vacancy_readonly_name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'rct_vacancy_readonly_name','qname'=>'rct_vacancy_readonly_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rct_vacancy_readonly_number','label'=>'number','type'=>'text','srcName'=>'number','ufname'=>'rct_vacancy_readonly_number','qname'=>'rct_vacancy_readonly_number','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'rct_vacancy_readonly_progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'rct_vacancy_readonly_progress_level','qname'=>'rct_vacancy_readonly_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_vacancy_readonly_workflow_state','label'=>'workflow_state','type'=>'text_choice','list'=>'recruitment.workflow_state','control'=>'select','sqltype'=>'integer','srcName'=>'workflow_state','ufname'=>'rct_vacancy_readonly_workflow_state','qname'=>'rct_vacancy_readonly_workflow_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_vacancy_readonly_request_date','label'=>'request_date','type'=>'datetime','format'=>'%d %B %Y &agrave; %H:%M','srcName'=>'request_date','ufname'=>'rct_vacancy_readonly_request_date','qname'=>'rct_vacancy_readonly_request_date',),
array('name'=>'rct_vacancy_readonly_requested_by','label'=>'requested_by','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'requested_by','ufname'=>'rct_vacancy_readonly_requested_by','qname'=>'rct_vacancy_readonly_requested_by','list'=>'requested_by','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_vacancy_readonly_manager_oid','label'=>'manager_oid','type'=>'text_choice','prompt'=>'manager_oid...','multiple'=>false,'control'=>'select','ds'=>'db:user.ds_list_all@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'manager_oid','ufname'=>'rct_vacancy_readonly_manager_oid','qname'=>'rct_vacancy_readonly_manager_oid','list'=>'manager_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'rct_vacancy_readonly_oid','oid'=>'rct_vacancy_readonly_oid','_oid'=>'rct_vacancy_readonly_oid','code'=>'rct_vacancy_readonly_code','code'=>'rct_vacancy_readonly_code','_code'=>'rct_vacancy_readonly_code','name'=>'rct_vacancy_readonly_name','name'=>'rct_vacancy_readonly_name','_name'=>'rct_vacancy_readonly_name','number'=>'rct_vacancy_readonly_number','number'=>'rct_vacancy_readonly_number','_number'=>'rct_vacancy_readonly_number','progress_level'=>'rct_vacancy_readonly_progress_level','progress_level'=>'rct_vacancy_readonly_progress_level','_progress_level'=>'rct_vacancy_readonly_progress_level','workflow_state'=>'rct_vacancy_readonly_workflow_state','workflow_state'=>'rct_vacancy_readonly_workflow_state','_workflow_state'=>'rct_vacancy_readonly_workflow_state','request_date'=>'rct_vacancy_readonly_request_date','request_date'=>'rct_vacancy_readonly_request_date','_request_date'=>'rct_vacancy_readonly_request_date','requested_by'=>'rct_vacancy_readonly_requested_by','requested_by'=>'rct_vacancy_readonly_requested_by','_requested_by'=>'rct_vacancy_readonly_requested_by','manager_oid'=>'rct_vacancy_readonly_manager_oid','manager_oid'=>'rct_vacancy_readonly_manager_oid','_manager_oid'=>'rct_vacancy_readonly_manager_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_readonly.pending_list','table'=>'_rct_vacancy_readonly');
 ?>