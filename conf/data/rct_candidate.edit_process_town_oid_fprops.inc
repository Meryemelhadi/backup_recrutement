<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'town_oid','label'=>'town_oid','type'=>'text','srcName'=>'town_oid','ufname'=>'_town_oid','qname'=>'rct_candidate_town_oid','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','town_oid'=>'town_oid','_town_oid'=>'town_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_town_oid','table'=>'_rct_candidate');
 ?>