<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_comment_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'interview_oid','type'=>'text','isKey'=>'secondary','show'=>false,'label'=>'interview_oid','srcName'=>'interview_oid','ufname'=>'_interview_oid','qname'=>'rct_vacancy_comment_interview_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_oid','label'=>'user_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_vacancy_comment_user_oid','list'=>'user_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'date','label'=>'date','type'=>'datetime','format'=>'%d %B %Y &agrave; %H:%M','srcName'=>'date','ufname'=>'_date','qname'=>'rct_vacancy_comment_date',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','interview_oid'=>'interview_oid','_interview_oid'=>'interview_oid','user_oid'=>'user_oid','_user_oid'=>'user_oid','date'=>'date','_date'=>'date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_comment.by_interview_interviewer','table'=>'_rct_vacancy_comment');
 ?>