<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_etat_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_candidate_etat_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_etat.available_etat','table'=>'_rct_candidate_etat');
 ?>