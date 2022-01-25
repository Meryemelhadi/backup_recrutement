<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_interview_synthesis_criterias_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'interview_synthesis_oid','label'=>'interview_synthesis_oid','type'=>'text','isKey'=>'secondary','show'=>false,'srcName'=>'interview_synthesis_oid','ufname'=>'_interview_synthesis_oid','qname'=>'rct_interview_synthesis_criterias_interview_synthesis_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_interview_synthesis_criterias_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'level','label'=>'level','type'=>'text_choice','list'=>'recruitment.interview_criteria_value','control'=>'grid_radio','sqltype'=>'integer','srcName'=>'level','ufname'=>'_level','qname'=>'rct_interview_synthesis_criterias_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','interview_synthesis_oid'=>'interview_synthesis_oid','_interview_synthesis_oid'=>'interview_synthesis_oid','name'=>'name','_name'=>'name','level'=>'level','_level'=>'level',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview_synthesis_criterias.record','table'=>'_rct_interview_synthesis_criterias');
 ?>