<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'object_id','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_channel_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_channel_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'to_email','label'=>'to_email','type'=>'text','size'=>'200','srcName'=>'to_email','ufname'=>'_to_email','qname'=>'rct_channel_to_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'establishment','label'=>'Etablissement','prompt'=>'Etablissement...','multiLines'=>false,'type'=>'text_choice','multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_channel_establishment','list'=>'establishment','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','to_email'=>'to_email','_to_email'=>'to_email','establishment'=>'establishment','_establishment'=>'establishment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_channel.excel','table'=>'_rct_channel');
 ?>