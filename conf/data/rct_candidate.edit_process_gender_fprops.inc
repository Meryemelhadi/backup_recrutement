<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'gender','label'=>'gender','type'=>'text_choice','list'=>'recruitment.gender','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'gender','ufname'=>'_gender','qname'=>'rct_candidate_gender','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','gender'=>'gender','_gender'=>'gender',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_gender','table'=>'_rct_candidate');
 ?>