<?php $properties["fprops"]=array(
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text_choice','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_candidate_vacancy_vacancy_oid','isProp'=>'val','isKey'=>'secondary','sqltype'=>'integer','list'=>'vacancy_oid','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','val'=>'vacancy_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.get_last_vacancy_for_candidate','table'=>'_rct_candidate_vacancy');
 ?>