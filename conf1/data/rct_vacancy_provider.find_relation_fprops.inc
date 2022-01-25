<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_provider_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'provider_oid','label'=>'provider_oid','type'=>'text','srcName'=>'provider_oid','ufname'=>'_provider_oid','qname'=>'rct_vacancy_provider_provider_oid','control'=>'select','multiple'=>false,'ds'=>'db:rct_provider.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_vacancy_provider_vacancy_oid','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','provider_oid'=>'provider_oid','_provider_oid'=>'provider_oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_provider.find_relation','table'=>'_rct_vacancy_provider');
 ?>