<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_comment_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'vacancy_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_comment_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_oid','label'=>'user_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list_all@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_candidate_comment_user_oid','list'=>'user_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'date','label'=>'date','type'=>'datetime','format'=>'Le %d %B %Y &agrave; %H:%M','srcName'=>'date','ufname'=>'_date','qname'=>'rct_candidate_comment_date',),
array('name'=>'comment','label'=>'comment','type'=>'text','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_candidate_comment_comment','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','user_oid'=>'user_oid','_user_oid'=>'user_oid','date'=>'date','_date'=>'date','comment'=>'comment','_comment'=>'comment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_comment.by_candidate','table'=>'_rct_candidate_comment');
 ?>