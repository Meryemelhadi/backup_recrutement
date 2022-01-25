<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','is_transient'=>true,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_oid','isKey'=>'primary','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','is_transient'=>true,'srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.vlist','table'=>'_rct_vacancy');
 ?>