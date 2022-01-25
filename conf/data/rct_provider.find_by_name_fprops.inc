<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_provider_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'provider_username','label'=>'provider_username','type'=>'text','srcName'=>'provider_username','ufname'=>'_provider_username','qname'=>'rct_provider_provider_username','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'provider_password','label'=>'provider_password','type'=>'text','srcName'=>'provider_password','ufname'=>'_provider_password','qname'=>'rct_provider_provider_password','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','provider_username'=>'provider_username','_provider_username'=>'provider_username','provider_password'=>'provider_password','_provider_password'=>'provider_password',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_provider.find_by_name','table'=>'_rct_provider');
 ?>