<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'directory_group_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'group_name','label'=>'group_name','type'=>'text','srcName'=>'group_name','ufname'=>'_group_name','qname'=>'directory_group_group_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','group_name'=>'group_name','_group_name'=>'group_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'poles','table'=>'_directory_group');
 ?>