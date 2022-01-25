<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'expression','value'=>'{field.object:oid}','isKey'=>'secondary','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_candidate_oid','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'candidate_log','label'=>'candidate_log','type'=>'records','ds'=>'handler:recruitment.candidates.log.candidate_log','ds_record'=>'handler:recruitment.candidates.log.candidate_log','key'=>'oid','fkey'=>'candidate_oid','view'=>'recruitment.vacancies.components.candidate_log','edit_view'=>'recruitment.vacancies.components.candidate_log','srcName'=>'candidate_log','ufname'=>'_candidate_log','qname'=>'rct_candidate_candidate_log','is_transient'=>true,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','candidate_log'=>'candidate_log','_candidate_log'=>'candidate_log',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'recruitment.candidates.associated.log','table'=>'_rct_candidate');
 ?>