<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_read_state_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_oid','label'=>'user_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:get_allUsers','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_candidate_read_state_user_oid','list'=>'user_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'read_time','label'=>'read_time','type'=>'datetime','value'=>'now','format'=>'%d %B %Y &agrave; %H:%M','srcName'=>'read_time','ufname'=>'_read_time','qname'=>'rct_candidate_read_state_read_time',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','user_oid'=>'user_oid','_user_oid'=>'user_oid','read_time'=>'read_time','_read_time'=>'read_time',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_read_state.by_user','table'=>'_rct_candidate_read_state');
 ?>