<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_email_docs_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_email_docs_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'file','label'=>'file','type'=>'file','srcName'=>'file','ufname'=>'_file','qname'=>'rct_email_docs_file','isFile'=>'true',),
array('name'=>'index','label'=>'index','type'=>'text','size'=>'200','srcName'=>'index','ufname'=>'_index','qname'=>'rct_email_docs_index','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'dest','label'=>'dest','type'=>'text_choice','list'=>'recruitment.candidate_action_sent_to','control'=>'radio','multiple'=>false,'sqltype'=>'varchar(5)','srcName'=>'dest','ufname'=>'_dest','qname'=>'rct_email_docs_dest','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','file'=>'file','_file'=>'file','index'=>'index','_index'=>'index','dest'=>'dest','_dest'=>'dest',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email_docs','table'=>'_rct_email_docs');
 ?>