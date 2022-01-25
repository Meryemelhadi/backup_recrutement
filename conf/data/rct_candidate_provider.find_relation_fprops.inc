<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_provider_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','isKey'=>'secondary','show'=>false,'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_provider_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'provider','label'=>'provider','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_provider.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'provider','ufname'=>'_provider','qname'=>'rct_candidate_provider_provider','list'=>'provider','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','provider'=>'provider','_provider'=>'provider',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_provider.find_relation','table'=>'_rct_candidate_provider');
 ?>