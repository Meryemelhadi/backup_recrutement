<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_read_state_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_read_state_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_oid','label'=>'user_oid','type'=>'text','srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_candidate_read_state_user_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'read_time','label'=>'read_time','type'=>'datetime','value'=>'now','format'=>'%d %B %Y &agrave; %H:%M','srcName'=>'read_time','ufname'=>'_read_time','qname'=>'rct_candidate_read_state_read_time',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','user_oid'=>'user_oid','_user_oid'=>'user_oid','read_time'=>'read_time','_read_time'=>'read_time',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_read_state.by_candidate','table'=>'_rct_candidate_read_state');
 ?>