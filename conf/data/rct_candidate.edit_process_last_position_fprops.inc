<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'last_position','label'=>'last_position','type'=>'text','srcName'=>'last_position','ufname'=>'_last_position','qname'=>'rct_candidate_last_position','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','last_position'=>'last_position','_last_position'=>'last_position',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_last_position','table'=>'_rct_candidate');
 ?>