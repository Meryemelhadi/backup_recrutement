<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_email_sample_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_email_sample_name','csslayout'=>'normal-layout','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'type_email','label'=>'type_email','type'=>'text_choice','list'=>'recruitment.email_type.all@recruitment','control'=>'select','multiple'=>false,'sqltype'=>'varchar(5)','srcName'=>'type_email','ufname'=>'_type_email','qname'=>'rct_email_sample_type_email','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','type_email'=>'type_email','_type_email'=>'type_email',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email_sample.list','table'=>'_rct_email_sample');
 ?>