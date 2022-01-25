<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'directory_country_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'country_name','label'=>'country_name','type'=>'text','srcName'=>'country_name','ufname'=>'_country_name','qname'=>'directory_country_country_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','country_name'=>'country_name','_country_name'=>'country_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'directory_country.list','table'=>'_directory_country');
 ?>