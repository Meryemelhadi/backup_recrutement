<?php $properties["fprops"]=array(
array('name'=>'rating','type'=>'text','value'=>$props->getProperty("rating_value","",true),'label'=>'rating','srcName'=>'rating','ufname'=>'_rating','qname'=>'rct_candidate_vacancy_rating','list'=>'recruitment.rating','control'=>'select','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('rating'=>'rating','_rating'=>'rating',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.rate','table'=>'_rct_candidate_vacancy');
 ?>