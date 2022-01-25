<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'object_id','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_services_web_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_services_web_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'url','label'=>'url','type'=>'text','size'=>'200','srcName'=>'url','ufname'=>'_url','qname'=>'rct_services_web_url','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'key','label'=>'key','type'=>'text','size'=>'200','srcName'=>'key','ufname'=>'_key','qname'=>'rct_services_web_key','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'type','label'=>'type','type'=>'text','size'=>'200','srcName'=>'type','ufname'=>'_type','qname'=>'rct_services_web_type','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','url'=>'url','_url'=>'url','key'=>'key','_key'=>'key','type'=>'type','_type'=>'type',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'services_web.excel','table'=>'_rct_services_web');
 ?>