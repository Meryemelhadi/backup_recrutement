<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'object_id','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_email_docs_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_email_docs_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'file','label'=>'file','type'=>'file','srcName'=>'file','ufname'=>'_file','qname'=>'rct_email_docs_file','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','file'=>'file','_file'=>'file',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'email_docs.ds_list','table'=>'_rct_email_docs');
 ?>