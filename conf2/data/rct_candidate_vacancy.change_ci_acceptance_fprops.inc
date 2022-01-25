<?php $properties["fprops"]=array(
array('name'=>'ci_acceptance_state','type'=>'text','value'=>$props->getProperty("acceptance_status","",true),'label'=>'ci_acceptance_state','srcName'=>'ci_acceptance_state','ufname'=>'_ci_acceptance_state','qname'=>'rct_candidate_vacancy_ci_acceptance_state','list'=>'recruitment.acceptance_list','control'=>'select','sqltype'=>'integer','multiple'=>false,'default'=>'0','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'ci_acceptance_date','type'=>'datetime','value'=>'now','label'=>'ci_acceptance_date','srcName'=>'ci_acceptance_date','ufname'=>'_ci_acceptance_date','qname'=>'rct_candidate_vacancy_ci_acceptance_date',),);
$properties["falias"]=array('ci_acceptance_state'=>'ci_acceptance_state','_ci_acceptance_state'=>'ci_acceptance_state','ci_acceptance_date'=>'ci_acceptance_date','_ci_acceptance_date'=>'ci_acceptance_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.change_ci_acceptance','table'=>'_rct_candidate_vacancy');
 ?>