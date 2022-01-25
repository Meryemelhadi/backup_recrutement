<?php $properties["fprops"]=array(
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_app_connected_name','isRequired'=>true,'multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'url','label'=>'url','type'=>'text','size'=>'200','srcName'=>'url','ufname'=>'_url','qname'=>'rct_app_connected_url','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'key','label'=>'key','type'=>'text','size'=>'200','srcName'=>'key','ufname'=>'_key','qname'=>'rct_app_connected_key','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('name'=>'name','_name'=>'name','url'=>'url','_url'=>'url','key'=>'key','_key'=>'key',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'app_connected.search','table'=>'_rct_app_connected');
 ?>