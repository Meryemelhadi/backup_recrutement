<?php $properties["fprops"]=array(
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_channel_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'establishment','label'=>'Etablissement','prompt'=>'Etablissement...','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_channel_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('name'=>'name','_name'=>'name','establishment'=>'establishment','_establishment'=>'establishment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_channel.search','table'=>'_rct_channel');
 ?>