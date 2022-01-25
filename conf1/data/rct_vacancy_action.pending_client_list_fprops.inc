<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_action_oid','is_edit'=>'no','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_action_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'number','label'=>'number','type'=>'text','srcName'=>'number','ufname'=>'_number','qname'=>'rct_vacancy_action_number','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'workflow_state','label'=>'workflow_state','type'=>'text_choice','list'=>'recruitment.workflow_state','control'=>'select','sqltype'=>'integer','srcName'=>'workflow_state','ufname'=>'_workflow_state','qname'=>'rct_vacancy_action_workflow_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'request_date','label'=>'request_date','type'=>'datetime','format'=>'%d %B %Y &agrave; %H:%M','srcName'=>'request_date','ufname'=>'_request_date','qname'=>'rct_vacancy_action_request_date',),
array('name'=>'requested_by','label'=>'requested_by','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'requested_by','ufname'=>'_requested_by','qname'=>'rct_vacancy_action_requested_by','list'=>'requested_by','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','number'=>'number','_number'=>'number','workflow_state'=>'workflow_state','_workflow_state'=>'workflow_state','request_date'=>'request_date','_request_date'=>'request_date','requested_by'=>'requested_by','_requested_by'=>'requested_by',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_action.pending_client_list','table'=>'_rct_vacancy_action');
 ?>