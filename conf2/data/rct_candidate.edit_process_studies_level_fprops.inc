<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'studies_level','label'=>'studies_level','type'=>'text','srcName'=>'studies_level','ufname'=>'_studies_level','qname'=>'rct_candidate_studies_level','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','studies_level'=>'studies_level','_studies_level'=>'studies_level',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_studies_level','table'=>'_rct_candidate');
 ?>