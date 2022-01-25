<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_provider_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'ref','label'=>'ref','type'=>'text','srcName'=>'ref','ufname'=>'_ref','qname'=>'rct_vacancy_provider_ref','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'provider_oid','label'=>'provider_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_provider.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'provider_oid','ufname'=>'_provider_oid','qname'=>'rct_vacancy_provider_provider_oid','list'=>'provider_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'from_email','type'=>'text','label'=>'from_email','srcName'=>'from_email','ufname'=>'_from_email','qname'=>'rct_vacancy_provider_from_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'to_email','type'=>'text','label'=>'to_email','srcName'=>'to_email','ufname'=>'_to_email','qname'=>'rct_vacancy_provider_to_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','ref'=>'ref','_ref'=>'ref','provider_oid'=>'provider_oid','_provider_oid'=>'provider_oid','from_email'=>'from_email','_from_email'=>'from_email','to_email'=>'to_email','_to_email'=>'to_email',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_prestataire_vacancy.list','table'=>'_rct_vacancy_provider');
 ?>