<?php $properties["fprops"]=array(
array('name'=>'etat_oid','label'=>'etat_oid','type'=>'text','value'=>$props->getProperty("etat_oid","",true),'srcName'=>'etat_oid','ufname'=>'_etat_oid','qname'=>'rct_candidate_etat_oid','isProp'=>'val','isKey'=>'secondary','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('etat_oid'=>'etat_oid','_etat_oid'=>'etat_oid','val'=>'etat_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_etat','table'=>'_rct_candidate');
 ?>