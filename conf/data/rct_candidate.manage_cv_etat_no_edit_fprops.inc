<?php $properties["fprops"]=array(
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','isFile'=>'true',),
array('name'=>'etat_oid','label'=>'etat_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_candidate_etat.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','isEdit'=>false,'srcName'=>'etat_oid','ufname'=>'_etat_oid','qname'=>'rct_candidate_etat_oid','isProp'=>'val','list'=>'etat_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('cv_path'=>'cv_path','_cv_path'=>'cv_path','etat_oid'=>'etat_oid','_etat_oid'=>'etat_oid','val'=>'etat_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.manage_cv_etat_no_edit','table'=>'_rct_candidate');
 ?>