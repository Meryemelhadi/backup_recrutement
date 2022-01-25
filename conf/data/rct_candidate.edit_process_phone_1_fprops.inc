<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'phone_1','label'=>'phone_1','type'=>'text','srcName'=>'phone_1','ufname'=>'_phone_1','qname'=>'rct_candidate_phone_1','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','phone_1'=>'phone_1','_phone_1'=>'phone_1',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_phone_1','table'=>'_rct_candidate');
 ?>