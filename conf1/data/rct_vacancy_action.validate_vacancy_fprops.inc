<?php $properties["fprops"]=array(
array('name'=>'workflow_state','label'=>'workflow_state','type'=>'text','value'=>(isset($_REQUEST["validation_key"])?$_REQUEST["validation_key"]:""),'srcName'=>'workflow_state','ufname'=>'_workflow_state','qname'=>'rct_vacancy_action_workflow_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'opening_date','label'=>'opening_date','type'=>'datetime','value'=>'now','srcName'=>'opening_date','ufname'=>'_opening_date','qname'=>'rct_vacancy_action_opening_date',),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text','value'=>'0','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_action_progress_level','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'current_step','label'=>'current_step','type'=>'text','value'=>'0','srcName'=>'current_step','ufname'=>'_current_step','qname'=>'rct_vacancy_action_current_step','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('workflow_state'=>'workflow_state','_workflow_state'=>'workflow_state','opening_date'=>'opening_date','_opening_date'=>'opening_date','progress_level'=>'progress_level','_progress_level'=>'progress_level','current_step'=>'current_step','_current_step'=>'current_step',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_action.validate_vacancy','table'=>'_rct_vacancy_action');
 ?>