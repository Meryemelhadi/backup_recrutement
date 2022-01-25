<?php $properties["fprops"]=array(
array('name'=>'hr_manager','label'=>'hr_manager','type'=>'text_choice','prompt'=>'hr_manager...','multiple'=>false,'control'=>'select','ds'=>'db:user.ds_list_recruiters@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'hr_manager','ufname'=>'_hr_manager','qname'=>'rct_candidate_hr_manager','list'=>'hr_manager','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('hr_manager'=>'hr_manager','_hr_manager'=>'hr_manager',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_hr_manager','table'=>'_rct_candidate');
 ?>