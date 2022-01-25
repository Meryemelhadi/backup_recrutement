<?php $properties["fprops"]=array(
array('name'=>'full_name','label'=>'full_name','type'=>'text','is_transient'=>true,'srcName'=>'full_name','ufname'=>'_full_name','qname'=>'rct_candidate_vacancy_full_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'proposal_acceptance_date','label'=>'proposal_acceptance_date','type'=>'date','format'=>'%d %B %Y','srcName'=>'proposal_acceptance_date','ufname'=>'_proposal_acceptance_date','qname'=>'rct_candidate_vacancy_proposal_acceptance_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),);
$properties["falias"]=array('full_name'=>'full_name','_full_name'=>'full_name','proposal_acceptance_date'=>'proposal_acceptance_date','_proposal_acceptance_date'=>'proposal_acceptance_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.accepted_proposals','table'=>'_rct_candidate_vacancy');
 ?>