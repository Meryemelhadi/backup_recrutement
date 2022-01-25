<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'integration_plan','label'=>'integration_plan','type'=>'text_choice','list'=>'recruitment.boolean_list','control'=>'select','sqltype'=>'integer','multiple'=>false,'default'=>'0','prompt'=>'select integration_plan...','srcName'=>'integration_plan','ufname'=>'_integration_plan','qname'=>'rct_candidate_vacancy_integration_plan','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','integration_plan'=>'integration_plan','_integration_plan'=>'integration_plan',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.change_integration_plan','table'=>'_rct_candidate_vacancy');
 ?>