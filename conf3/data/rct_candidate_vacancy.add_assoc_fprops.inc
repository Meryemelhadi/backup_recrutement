<?php $properties["fprops"]=array(
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','value'=>$props->getProperty("candidate_oid","",true),'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_vacancy_candidate_oid','isProp'=>'key','isKey'=>'secondary','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','value'=>$props->getProperty("vacancy_oid","",true),'srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_candidate_vacancy_vacancy_oid','isProp'=>'val','isKey'=>'secondary','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'add_date','label'=>'add_date','type'=>'datetime','value'=>'now','srcName'=>'add_date','ufname'=>'_add_date','qname'=>'rct_candidate_vacancy_add_date',),);
$properties["falias"]=array('candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','key'=>'candidate_oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','val'=>'vacancy_oid','add_date'=>'add_date','_add_date'=>'add_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.add_assoc','table'=>'_rct_candidate_vacancy');
 ?>