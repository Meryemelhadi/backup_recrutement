<?php $properties["fprops"]=array(
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_readonly_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_vacancy_readonly_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'current_step','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.vacancy_step','control'=>'select','sqltype'=>'integer','srcName'=>'current_step','ufname'=>'_current_step','qname'=>'rct_vacancy_readonly_current_step','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('name'=>'name','_name'=>'name','code'=>'code','_code'=>'code','current_step'=>'current_step','_current_step'=>'current_step',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_readonly.vacancy_title','table'=>'_rct_vacancy_readonly');
 ?>