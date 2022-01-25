<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_entreprise_description_rekrute_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name_description','label'=>'name_description','type'=>'text','srcName'=>'name_description','ufname'=>'_name_description','qname'=>'rct_entreprise_description_rekrute_name_description','csslayout'=>'normal-layout','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name_description'=>'name_description','_name_description'=>'name_description',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_entreprise_description_rekrute.list','table'=>'_rct_entreprise_description_rekrute');
 ?>