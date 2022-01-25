<?php $properties["fprops"]=array(
array('name'=>'cv_source_oid','label'=>'cv_source_oid','type'=>'text','value'=>$props->getProperty("provider_oid","",true),'srcName'=>'cv_source_oid','ufname'=>'_cv_source_oid','qname'=>'rct_candidate_vacancy_cv_source_oid','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('cv_source_oid'=>'cv_source_oid','_cv_source_oid'=>'cv_source_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.update_provider','table'=>'_rct_candidate_vacancy');
 ?>