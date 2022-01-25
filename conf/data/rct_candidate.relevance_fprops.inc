<?php $properties["fprops"]=array(
array('name'=>'relevance','type'=>'text','value'=>$props->getProperty("relevance_oid","",true),'label'=>'relevance','srcName'=>'relevance','ufname'=>'_relevance','qname'=>'rct_candidate_relevance','list'=>'recruitment.relevance','control'=>'select','sqltype'=>'integer','multiple'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('relevance'=>'relevance','_relevance'=>'relevance',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.relevance','table'=>'_rct_candidate');
 ?>