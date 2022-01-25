<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','isEdit'=>false,'show'=>false,'alias'=>'oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'full_name','label'=>'full_name','type'=>'text','srcName'=>'full_name','ufname'=>'_full_name','qname'=>'rct_candidate_full_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','full_name'=>'full_name','_full_name'=>'full_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.ds_candidate_autocomplete_list','table'=>'_rct_candidate');
 ?>