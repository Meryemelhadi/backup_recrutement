<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'directory_town_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'town_name','label'=>'town_name','type'=>'text','srcName'=>'town_name','ufname'=>'_town_name','qname'=>'directory_town_town_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'country_oid','label'=>'country_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:directory_country.ds_list','ds_format'=>'{field:country_name}','ds_field_value'=>'oid','srcName'=>'country_oid','ufname'=>'_country_oid','qname'=>'directory_town_country_oid','list'=>'country_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'cp','label'=>'cp','type'=>'text','srcName'=>'cp','ufname'=>'_cp','qname'=>'directory_town_cp','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','town_name'=>'town_name','_town_name'=>'town_name','country_oid'=>'country_oid','_country_oid'=>'country_oid','cp'=>'cp','_cp'=>'cp',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'directory_town.record','table'=>'_directory_town');
 ?>