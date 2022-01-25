<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_client_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date','label'=>'date','type'=>'datetime','srcName'=>'date','ufname'=>'_date','qname'=>'rct_candidate_client_date',),
array('name'=>'proposed_by','label'=>'proposed_by','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'proposed_by','ufname'=>'_proposed_by','qname'=>'rct_candidate_client_proposed_by','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'proposed_to','label'=>'proposed_to','type'=>'text_choice_table','control'=>'facebook_list','multiple'=>true,'ds'=>'db:user.ds_list@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'candidate_oid','ds_link'=>'rct_candidate_proposed_to','srcName'=>'proposed_to','ufname'=>'_proposed_to','qname'=>'rct_candidate_client_proposed_to','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_client_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'comment','label'=>'comment','type'=>'text','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_candidate_client_comment','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','date'=>'date','_date'=>'date','proposed_by'=>'proposed_by','_proposed_by'=>'proposed_by','proposed_to'=>'proposed_to','_proposed_to'=>'proposed_to','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','comment'=>'comment','_comment'=>'comment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_client','table'=>'_rct_candidate_client');
 ?>