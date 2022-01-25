<?php $properties["fprops"]=array(
array('name'=>'interim','label'=>'Interim','size'=>'50','type'=>'text_choice','prompt'=>'Selectionner interim...','multiple'=>false,'control'=>'select','ds'=>'db:users.ds_list_all@user','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'interim','ufname'=>'_interim','qname'=>'user_interim','list'=>'interim','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('interim'=>'interim','_interim'=>'interim',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'user.get_interim','table'=>'_user');
 ?>