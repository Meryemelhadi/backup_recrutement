<?php $properties["fprops"]=array(
array('name'=>'candidate_full_name','label'=>'candidate_full_name','type'=>'text','is_transient'=>true,'srcName'=>'candidate_full_name','ufname'=>'_candidate_full_name','qname'=>'rct_email_candidate_full_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'to','label'=>'to','type'=>'text','is_transient'=>true,'srcName'=>'to','ufname'=>'_to','qname'=>'rct_email_to','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'subject','label'=>'subject','type'=>'text','is_transient'=>true,'srcName'=>'subject','ufname'=>'_subject','qname'=>'rct_email_subject','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'body','label'=>'body','type'=>'text','is_transient'=>true,'srcName'=>'body','ufname'=>'_body','qname'=>'rct_email_body','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'files','label'=>'files','type'=>'text','is_transient'=>true,'srcName'=>'files','ufname'=>'_files','qname'=>'rct_email_files','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'docs','label'=>'email_docs','type'=>'text_choice','control'=>'checkbox','multiple'=>true,'ds'=>'db:email_docs.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'varchar(255)','srcName'=>'docs','ufname'=>'_docs','qname'=>'rct_email_docs','list'=>'docs','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('candidate_full_name'=>'candidate_full_name','_candidate_full_name'=>'candidate_full_name','to'=>'to','_to'=>'to','subject'=>'subject','_subject'=>'subject','body'=>'body','_body'=>'body','files'=>'files','_files'=>'files','docs'=>'docs','_docs'=>'docs',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email.email_data','table'=>'_rct_email');
 ?>