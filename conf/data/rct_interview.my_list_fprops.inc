<?php $properties["fprops"]=array(
array('name'=>'rct_interview_oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'rct_interview_oid','qname'=>'rct_interview_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'rct_interview_vacancy_oid','label'=>'vacancy_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy.ds_list','ds_format'=>'{field:name} ({field:code})','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'vacancy_oid','ufname'=>'rct_interview_vacancy_oid','qname'=>'rct_interview_vacancy_oid','list'=>'vacancy_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_interview_candidate_oid','label'=>'candidate_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_candidate.ds_list','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'candidate_oid','ufname'=>'rct_interview_candidate_oid','qname'=>'rct_interview_candidate_oid','list'=>'candidate_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_interview_created_by','label'=>'created_by','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','prompt'=>'select a user...','isEdit'=>false,'srcName'=>'created_by','ufname'=>'rct_interview_created_by','qname'=>'rct_interview_created_by','list'=>'created_by','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'rct_interview_date','label'=>'date','type'=>'date','srcName'=>'date','ufname'=>'rct_interview_date','qname'=>'rct_interview_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'rct_interview_time_start','label'=>'time_start','type'=>'datetime','control'=>'time','increment-mn'=>'10','format'=>'%H:%M','srcName'=>'time_start','ufname'=>'rct_interview_time_start','qname'=>'rct_interview_time_start',),
array('name'=>'rct_interview_time_end','label'=>'time_end','type'=>'datetime','control'=>'time','increment-mn'=>'10','format'=>'%H:%M','srcName'=>'time_end','ufname'=>'rct_interview_time_end','qname'=>'rct_interview_time_end',),
array('name'=>'rct_interview_validation_state','label'=>'validation_state','type'=>'text_choice','list'=>'recruitment.validation_state','control'=>'select','sqltype'=>'integer','show'=>false,'srcName'=>'validation_state','ufname'=>'rct_interview_validation_state','qname'=>'rct_interview_validation_state','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'rct_interview_oid','oid'=>'rct_interview_oid','_oid'=>'rct_interview_oid','vacancy_oid'=>'rct_interview_vacancy_oid','vacancy_oid'=>'rct_interview_vacancy_oid','_vacancy_oid'=>'rct_interview_vacancy_oid','candidate_oid'=>'rct_interview_candidate_oid','candidate_oid'=>'rct_interview_candidate_oid','_candidate_oid'=>'rct_interview_candidate_oid','created_by'=>'rct_interview_created_by','created_by'=>'rct_interview_created_by','_created_by'=>'rct_interview_created_by','date'=>'rct_interview_date','date'=>'rct_interview_date','_date'=>'rct_interview_date','time_start'=>'rct_interview_time_start','time_start'=>'rct_interview_time_start','_time_start'=>'rct_interview_time_start','time_end'=>'rct_interview_time_end','time_end'=>'rct_interview_time_end','_time_end'=>'rct_interview_time_end','validation_state'=>'rct_interview_validation_state','validation_state'=>'rct_interview_validation_state','_validation_state'=>'rct_interview_validation_state',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview.my_list','table'=>'_rct_interview');
 ?>