<?php $properties["fprops"]=array(
array('name'=>'reading_state','label'=>'reading_state','type'=>'text','value'=>$props->getProperty("reading_state","",true),'srcName'=>'reading_state','ufname'=>'_reading_state','qname'=>'rct_candidate_reading_state','list'=>'recruitment.read_state','control'=>'select','sqltype'=>'integer','multiple'=>false,'default'=>'1','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('reading_state'=>'reading_state','_reading_state'=>'reading_state',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.change_reading_state','table'=>'_rct_candidate');
 ?>