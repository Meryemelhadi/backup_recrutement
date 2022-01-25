<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'size'=>'200','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','isEdit'=>false,'alias'=>'oid','onInput'=>"keypress_number(event)",'maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'full_name','label'=>'last_name','type'=>'text','is_transient'=>true,'srcName'=>'full_name','ufname'=>'_full_name','qname'=>'rct_candidate_full_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_candidate_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','full_name'=>'full_name','_full_name'=>'full_name','email'=>'email','_email'=>'email',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.get_emails','table'=>'_rct_candidate');
 ?>