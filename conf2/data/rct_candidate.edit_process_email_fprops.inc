<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_candidate_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','email'=>'email','_email'=>'email',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_email','table'=>'_rct_candidate');
 ?>