<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'civility','label'=>'civility','type'=>'text_choice','list'=>'recruitment.civility','control'=>'select','sqltype'=>'integer','multiple'=>false,'srcName'=>'civility','ufname'=>'_civility','qname'=>'rct_candidate_civility','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','civility'=>'civility','_civility'=>'civility',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_civility','table'=>'_rct_candidate');
 ?>