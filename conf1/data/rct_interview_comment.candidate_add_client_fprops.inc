<?php $properties["fprops"]=array(
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_candidate.vacancy_candidates','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','isEdit'=>false,'value'=>(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_interview_comment_candidate_oid','list'=>'candidate_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','show'=>false,'value'=>$props->getProperty("vacancy_oid","",true),'srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_interview_comment_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'created_by','label'=>'created_by','type'=>'text','show'=>false,'value'=>$GLOBALS["_NX_user"]->getProperty("oid","",true),'srcName'=>'created_by','ufname'=>'_created_by','qname'=>'rct_interview_comment_created_by','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'interview_by_oid','label'=>'interview_by_oid','type'=>'text_choice_table','list'=>'product_range','prompt'=>'interview_by_oid...','multiple'=>true,'control'=>'facebook_list','ds'=>'db:user.ds_list_all@recruitment','ds_link'=>'rct_interview_by','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','default'=>$GLOBALS["_NX_user"]->getProperty("oid","",true),'srcName'=>'interview_by_oid','ufname'=>'_interview_by_oid','qname'=>'rct_interview_comment_interview_by_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'creation_date','label'=>'creation_date','type'=>'datetime','value'=>'now','show'=>false,'srcName'=>'creation_date','ufname'=>'_creation_date','qname'=>'rct_interview_comment_creation_date',),
array('name'=>'date','label'=>'date','type'=>'date','srcName'=>'date','ufname'=>'_date','qname'=>'rct_interview_comment_date','format'=>'Le %d %B %Y &agrave; %H:%M','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'time_start','label'=>'time_start','type'=>'datetime','control'=>'time','format'=>'%H:%M','increment-mn'=>'10','default'=>'now','srcName'=>'time_start','ufname'=>'_time_start','qname'=>'rct_interview_comment_time_start',),
array('name'=>'time_end','label'=>'time_end','type'=>'datetime','control'=>'time','format'=>'%H:%M','increment-mn'=>'10','default'=>'now+10','srcName'=>'time_end','ufname'=>'_time_end','qname'=>'rct_interview_comment_time_end',),
array('name'=>'validation_state','label'=>'validation_state','type'=>'text','value'=>'0','show'=>false,'srcName'=>'validation_state','ufname'=>'_validation_state','qname'=>'rct_interview_comment_validation_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'ical_uid','label'=>'ical_uid','type'=>'text','size'=>'255','show'=>false,'srcName'=>'ical_uid','ufname'=>'_ical_uid','qname'=>'rct_interview_comment_ical_uid','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'ical_seq','label'=>'ical_seq','type'=>'text','size'=>'11','show'=>false,'default'=>'0','srcName'=>'ical_seq','ufname'=>'_ical_seq','qname'=>'rct_interview_comment_ical_seq','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','created_by'=>'created_by','_created_by'=>'created_by','interview_by_oid'=>'interview_by_oid','_interview_by_oid'=>'interview_by_oid','creation_date'=>'creation_date','_creation_date'=>'creation_date','date'=>'date','_date'=>'date','time_start'=>'time_start','_time_start'=>'time_start','time_end'=>'time_end','_time_end'=>'time_end','validation_state'=>'validation_state','_validation_state'=>'validation_state','ical_uid'=>'ical_uid','_ical_uid'=>'ical_uid','ical_seq'=>'ical_seq','_ical_seq'=>'ical_seq',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview_comment.candidate_add_client','table'=>'_rct_interview_comment');
 ?>