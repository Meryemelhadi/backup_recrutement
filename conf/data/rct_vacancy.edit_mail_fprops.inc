<?php $properties["fprops"]=array(
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_vacancy_email','size'=>'100','multiLines'=>false,'onSubmitCheck'=>"checkReg('%3\$s',%1\$s.%2\$s,%4\$s,'^[0-9a-zA-Z_.-]+@[0-9a-zA-Z_.-]+\.[0-9a-zA-Z_.-]+','wrong email syntax')",),);
$properties["falias"]=array('email'=>'email','_email'=>'email',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.edit_mail','table'=>'_rct_vacancy');
 ?>