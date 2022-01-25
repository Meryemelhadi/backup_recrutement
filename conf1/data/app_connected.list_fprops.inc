<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_app_connected_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','isRequired'=>true,'srcName'=>'name','ufname'=>'_name','qname'=>'rct_app_connected_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'url','label'=>'url','type'=>'text','size'=>'200','srcName'=>'url','ufname'=>'_url','qname'=>'rct_app_connected_url','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'key','label'=>'key','type'=>'text','size'=>'200','srcName'=>'key','ufname'=>'_key','qname'=>'rct_app_connected_key','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'comment','label'=>'comment','type'=>'text','size'=>'200','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_app_connected_comment','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','url'=>'url','_url'=>'url','key'=>'key','_key'=>'key','comment'=>'comment','_comment'=>'comment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'app_connected.list','table'=>'_rct_app_connected');
 ?>