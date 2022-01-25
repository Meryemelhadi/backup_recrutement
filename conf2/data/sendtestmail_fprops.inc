<?php $properties["fprops"]=array(
array('name'=>'email_one','label'=>'email_one','type'=>'text','is_transient'=>true,'srcName'=>'email_one','ufname'=>'_email_one','qname'=>'test_email_one','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email_two','label'=>'email_two','type'=>'text','is_transient'=>true,'srcName'=>'email_two','ufname'=>'_email_two','qname'=>'test_email_two','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email_one_log','label'=>'email_one_log','type'=>'text','is_transient'=>true,'srcName'=>'email_one_log','ufname'=>'_email_one_log','qname'=>'test_email_one_log','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email_two_log','label'=>'email_two_log','type'=>'text','is_transient'=>true,'srcName'=>'email_two_log','ufname'=>'_email_two_log','qname'=>'test_email_two_log','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('email_one'=>'email_one','_email_one'=>'email_one','email_two'=>'email_two','_email_two'=>'email_two','email_one_log'=>'email_one_log','_email_one_log'=>'email_one_log','email_two_log'=>'email_two_log','_email_two_log'=>'email_two_log',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'sendtestmail','table'=>'_test');
 ?>