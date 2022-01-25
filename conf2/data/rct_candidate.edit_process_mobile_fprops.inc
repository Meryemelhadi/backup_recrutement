<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'mobile','label'=>'mobile','type'=>'text','srcName'=>'mobile','ufname'=>'_mobile','qname'=>'rct_candidate_mobile','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','mobile'=>'mobile','_mobile'=>'mobile',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_mobile','table'=>'_rct_candidate');
 ?>