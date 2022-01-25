<?php $properties["fprops"]=array(
array('name'=>'ref','label'=>'ref','type'=>'text','srcName'=>'ref','ufname'=>'_ref','qname'=>'rct_vacancy_provider_ref','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'provider_oid','label'=>'provider_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_provider.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'provider_oid','ufname'=>'_provider_oid','qname'=>'rct_vacancy_provider_provider_oid','list'=>'provider_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('ref'=>'ref','_ref'=>'ref','provider_oid'=>'provider_oid','_provider_oid'=>'provider_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_prestataire_vacancy.search','table'=>'_rct_vacancy_provider');
 ?>