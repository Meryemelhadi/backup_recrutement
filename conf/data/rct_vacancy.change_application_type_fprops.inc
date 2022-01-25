<?php $properties["fprops"]=array(
array('name'=>'application_type','type'=>'text_choice','value'=>$props->getProperty("application_type","",true),'label'=>'application_type','srcName'=>'application_type','ufname'=>'_application_type','qname'=>'rct_vacancy_application_type','list'=>'recruitment.application_type','control'=>'checkbox','sqltype'=>'char(6)','multiple'=>true,'default'=>'0','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('application_type'=>'application_type','_application_type'=>'application_type',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.change_application_type','table'=>'_rct_vacancy');
 ?>