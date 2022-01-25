<?php $properties["fprops"]=array(
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_candidate_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'to','label'=>'to','type'=>'text','is_transient'=>true,'srcName'=>'to','ufname'=>'_to','qname'=>'rct_candidate_to','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'subject','label'=>'subject','type'=>'text','is_transient'=>true,'srcName'=>'subject','ufname'=>'_subject','qname'=>'rct_candidate_subject','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'body','label'=>'body','type'=>'text','is_transient'=>true,'srcName'=>'body','ufname'=>'_body','qname'=>'rct_candidate_body','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','email'=>'email','_email'=>'email','to'=>'to','_to'=>'to','subject'=>'subject','_subject'=>'subject','body'=>'body','_body'=>'body',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.email_notification','table'=>'_rct_candidate');
 ?>