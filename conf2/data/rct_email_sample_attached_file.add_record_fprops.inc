<?php $properties["fprops"]=array(
array('name'=>'email_oid','type'=>'text','value'=>$props->getProperty("object_oid","",true),'label'=>'email_oid','srcName'=>'email_oid','ufname'=>'_email_oid','qname'=>'rct_email_sample_attached_file_email_oid','isKey'=>'secondary','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'file_name','type'=>'text','value'=>$props->getProperty("file_name","",true),'label'=>'file_name','srcName'=>'file_name','ufname'=>'_file_name','qname'=>'rct_email_sample_attached_file_file_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('email_oid'=>'email_oid','_email_oid'=>'email_oid','file_name'=>'file_name','_file_name'=>'file_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email_sample_attached_file.add_record','table'=>'_rct_email_sample_attached_file');
 ?>