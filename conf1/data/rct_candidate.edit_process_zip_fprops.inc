<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'zip','label'=>'zip','type'=>'text','srcName'=>'zip','ufname'=>'_zip','qname'=>'rct_candidate_zip','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','zip'=>'zip','_zip'=>'zip',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_zip','table'=>'_rct_candidate');
 ?>