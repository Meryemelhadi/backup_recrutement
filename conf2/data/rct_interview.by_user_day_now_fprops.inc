<?php $properties["fprops"]=array(
array('name'=>'time_start','label'=>'time_start','type'=>'datetime','control'=>'time','increment-mn'=>'10','format'=>'%H:%M','srcName'=>'time_start','ufname'=>'_time_start','qname'=>'rct_interview_time_start',),
array('name'=>'time_end','label'=>'time_end','type'=>'datetime','control'=>'time','increment-mn'=>'10','format'=>'%H:%M','srcName'=>'time_end','ufname'=>'_time_end','qname'=>'rct_interview_time_end',),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_candidate.ds_list@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_interview_candidate_oid','list'=>'candidate_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('time_start'=>'time_start','_time_start'=>'time_start','time_end'=>'time_end','_time_end'=>'time_end','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview.by_user_day_now','table'=>'_rct_interview');
 ?>