<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_attached_file_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_vacancy_attached_file_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'file_name','label'=>'file_name','type'=>'file','srcName'=>'file_name','ufname'=>'_file_name','qname'=>'rct_vacancy_attached_file_file_name','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','file_name'=>'file_name','_file_name'=>'file_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_attached_file.by_vacancy','table'=>'_rct_vacancy_attached_file');
 ?>