<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_proposed_to_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'key','type'=>'text','label'=>'key','srcName'=>'key','ufname'=>'_key','qname'=>'rct_candidate_proposed_to_key','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'val','type'=>'text','label'=>'val','srcName'=>'val','ufname'=>'_val','qname'=>'rct_candidate_proposed_to_val','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','key'=>'key','_key'=>'key','val'=>'val','_val'=>'val',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_proposed_to.by_key','table'=>'_rct_candidate_proposed_to');
 ?>