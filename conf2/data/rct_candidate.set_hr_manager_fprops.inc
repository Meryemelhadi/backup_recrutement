<?php $properties["fprops"]=array(
array('name'=>'hr_manager','label'=>'hr_manager','type'=>'text_choice','prompt'=>'hr_manager...','multiple'=>false,'control'=>'select','ds'=>'db:user.ds_list_recruiters@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'hr_manager','ufname'=>'_hr_manager','qname'=>'rct_candidate_hr_manager','list'=>'hr_manager','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'establishment','label'=>'establishment','type'=>'text','srcName'=>'establishment','ufname'=>'_establishment','qname'=>'rct_candidate_establishment','multiLines'=>false,'multiple'=>false,'control'=>'select','ds'=>'entities.my_entities.ds_list@admin2','ds_format'=>'{field:entity_name}','ds_field_value'=>'oid','isKey'=>'secondary','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10',),);
$properties["falias"]=array('hr_manager'=>'hr_manager','_hr_manager'=>'hr_manager','establishment'=>'establishment','_establishment'=>'establishment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.set_hr_manager','table'=>'_rct_candidate');
 ?>