<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_client_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text_choice','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_vacancy_client_candidate_oid','list'=>'candidate_oid','control'=>'select','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_candidate_vacancy_client_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'proposed_by','label'=>'proposed_by','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'proposed_by','ufname'=>'_proposed_by','qname'=>'rct_candidate_vacancy_client_proposed_by','list'=>'proposed_by','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'proposal_date','label'=>'cvc_proposal_date','type'=>'datetime','format'=>'%d %B %Y &agrave; %H:%M','srcName'=>'proposal_date','ufname'=>'_proposal_date','qname'=>'rct_candidate_vacancy_client_proposal_date',),
array('name'=>'comment','label'=>'cvc_comment','type'=>'text','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_candidate_vacancy_client_comment','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'candidates_list','label'=>'candidates_list','type'=>'records','ds'=>'handler:recruitment.candidates_client.proposed','ds_record'=>'handler:recruitment.candidates_client.proposed','key'=>'oid','fkey'=>'candidate_oid','view'=>'recruitment.vacancies_client.components.candidates_short_list','edit_view'=>'recruitment.vacancies_client.components.candidates_short_list','srcName'=>'candidates_list','ufname'=>'_candidates_list','qname'=>'rct_candidate_vacancy_client_candidates_list','is_transient'=>true,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','proposed_by'=>'proposed_by','_proposed_by'=>'proposed_by','proposal_date'=>'proposal_date','_proposal_date'=>'proposal_date','comment'=>'comment','_comment'=>'comment','candidates_list'=>'candidates_list','_candidates_list'=>'candidates_list',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy_client.by_vacancy','table'=>'_rct_candidate_vacancy_client');
 ?>