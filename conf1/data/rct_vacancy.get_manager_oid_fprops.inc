<?php $properties["fprops"]=array(
array('name'=>'manager_oid','type'=>'text','label'=>'manager_oid','srcName'=>'manager_oid','ufname'=>'_manager_oid','qname'=>'rct_vacancy_manager_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'establishment','label'=>'establishment','type'=>'text','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_vacancy_establishment','multiLines'=>false,'multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10',),);
$properties["falias"]=array('manager_oid'=>'manager_oid','_manager_oid'=>'manager_oid','establishment'=>'establishment','_establishment'=>'establishment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.get_manager_oid','table'=>'_rct_vacancy');
 ?>