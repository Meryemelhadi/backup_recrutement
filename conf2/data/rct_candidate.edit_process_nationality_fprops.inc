<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'nationality','label'=>'nationality','type'=>'text','srcName'=>'nationality','ufname'=>'_nationality','qname'=>'rct_candidate_nationality','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','nationality'=>'nationality','_nationality'=>'nationality',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_nationality','table'=>'_rct_candidate');
 ?>