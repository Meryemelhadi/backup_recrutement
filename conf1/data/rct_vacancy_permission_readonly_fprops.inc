<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_permission_readonly_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vacancy_oid','type'=>'text','label'=>'vacancy_oid','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_vacancy_permission_readonly_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_oid','type'=>'text','label'=>'user_oid','srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_vacancy_permission_readonly_user_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','user_oid'=>'user_oid','_user_oid'=>'user_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_permission_readonly','table'=>'_rct_vacancy_permission_readonly');
 ?>