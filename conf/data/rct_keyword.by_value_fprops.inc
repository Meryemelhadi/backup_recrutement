<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_keyword_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','isRequired'=>true,'srcName'=>'name','ufname'=>'_name','qname'=>'rct_keyword_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'key','label'=>'key','type'=>'text','isRequired'=>true,'srcName'=>'key','ufname'=>'_key','qname'=>'rct_keyword_key','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','key'=>'key','_key'=>'key',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_keyword.by_value','table'=>'_rct_keyword');
 ?>