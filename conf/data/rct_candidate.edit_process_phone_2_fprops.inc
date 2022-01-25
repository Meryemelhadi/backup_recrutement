<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'phone_2','label'=>'phone_2','type'=>'text','srcName'=>'phone_2','ufname'=>'_phone_2','qname'=>'rct_candidate_phone_2','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','phone_2'=>'phone_2','_phone_2'=>'phone_2',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_phone_2','table'=>'_rct_candidate');
 ?>