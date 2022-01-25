<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text_choice','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_vacancy_candidate_oid','isProp'=>'key','isKey'=>'secondary','sqltype'=>'integer','list'=>'candidate_oid','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','key'=>'candidate_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.vacancy_candidates_not_null','table'=>'_rct_candidate_vacancy');
 ?>