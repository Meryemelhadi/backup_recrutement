<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy.ds_list','ds_format'=>'{field:name} (N° {field:code})','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_candidate_vacancy_vacancy_oid','isProp'=>'val','isKey'=>'secondary','list'=>'vacancy_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','val'=>'vacancy_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.candidate_vacancies_c_oid','table'=>'_rct_candidate_vacancy');
 ?>