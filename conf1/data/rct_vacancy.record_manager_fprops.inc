<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'manager_oid','label'=>'manager_oid','type'=>'text_choice','prompt'=>'manager_oid...','multiple'=>false,'control'=>'select','ds'=>'db:user.ds_list_all@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'manager_oid','ufname'=>'_manager_oid','qname'=>'rct_vacancy_manager_oid','list'=>'manager_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'creator','label'=>'creator','type'=>'text','sqltype'=>'integer','srcName'=>'creator','ufname'=>'_creator','qname'=>'rct_vacancy_creator','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','manager_oid'=>'manager_oid','_manager_oid'=>'manager_oid','creator'=>'creator','_creator'=>'creator',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.record_manager','table'=>'_rct_vacancy');
 ?>