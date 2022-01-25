<?php $properties["fprops"]=array(
array('name'=>'status','type'=>'text','value'=>$props->getProperty("status_value","",true),'label'=>'status','srcName'=>'status','ufname'=>'_status','qname'=>'rct_candidate_vacancy_status','list'=>'recruitment.candidate_vacancy_action','control'=>'select','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('status'=>'status','_status'=>'status',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.change_status','table'=>'_rct_candidate_vacancy');
 ?>