<?php $properties["fprops"]=array(
array('name'=>'is_visible','type'=>'text','value'=>$props->getProperty("visibility","",true),'label'=>'is_visible','srcName'=>'is_visible','ufname'=>'_is_visible','qname'=>'rct_short_list_is_visible','list'=>'recruitment.boolean_list','control'=>'select','sqltype'=>'integer','multiple'=>false,'default'=>'0','isKey'=>'secondary','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('is_visible'=>'is_visible','_is_visible'=>'is_visible',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_short_list.send_to_ic','table'=>'_rct_short_list');
 ?>