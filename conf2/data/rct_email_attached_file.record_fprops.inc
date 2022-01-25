<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_email_attached_file_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'email_oid','label'=>'email_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'email_oid','ufname'=>'_email_oid','qname'=>'rct_email_attached_file_email_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'file','label'=>'file','type'=>'file','control'=>'file_no_update','srcName'=>'file','ufname'=>'_file','qname'=>'rct_email_attached_file_file','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','email_oid'=>'email_oid','_email_oid'=>'email_oid','file'=>'file','_file'=>'file',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email_attached_file.record','table'=>'_rct_email_attached_file');
 ?>