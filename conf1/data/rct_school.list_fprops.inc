<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_school_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_school_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'label','label'=>'label','type'=>'text','srcName'=>'label','ufname'=>'_label','qname'=>'rct_school_label','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','code'=>'code','_code'=>'code','label'=>'label','_label'=>'label',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_school.list','table'=>'_rct_school');
 ?>