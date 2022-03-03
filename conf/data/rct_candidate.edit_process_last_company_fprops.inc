<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'last_company','label'=>'last_company','type'=>'text','srcName'=>'last_company','ufname'=>'_last_company','qname'=>'rct_candidate_last_company','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','last_company'=>'last_company','_last_company'=>'last_company',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_last_company','table'=>'_rct_candidate');
 ?>