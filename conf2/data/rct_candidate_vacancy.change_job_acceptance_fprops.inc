<?php $properties["fprops"]=array(
array('name'=>'job_acceptance_state','type'=>'text','value'=>$props->getProperty("acceptance_status","",true),'label'=>'job_acceptance_state','srcName'=>'job_acceptance_state','ufname'=>'_job_acceptance_state','qname'=>'rct_candidate_vacancy_job_acceptance_state','list'=>'recruitment.acceptance_list','control'=>'select','sqltype'=>'integer','multiple'=>false,'default'=>'0','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'job_acceptance_date','type'=>'datetime','value'=>'now','label'=>'job_acceptance_date','srcName'=>'job_acceptance_date','ufname'=>'_job_acceptance_date','qname'=>'rct_candidate_vacancy_job_acceptance_date',),);
$properties["falias"]=array('job_acceptance_state'=>'job_acceptance_state','_job_acceptance_state'=>'job_acceptance_state','job_acceptance_date'=>'job_acceptance_date','_job_acceptance_date'=>'job_acceptance_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.change_job_acceptance','table'=>'_rct_candidate_vacancy');
 ?>