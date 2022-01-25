<?php $properties["fprops"]=array(
array('name'=>'progress_level','type'=>'text','value'=>$props->getProperty("progress_level","",true),'label'=>'progress_level','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_progress_level','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('progress_level'=>'progress_level','_progress_level'=>'progress_level',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.change_progress_level','table'=>'_rct_vacancy');
 ?>