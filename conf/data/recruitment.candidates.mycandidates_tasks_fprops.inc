<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'secondary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','isEdit'=>false,'show'=>false,'alias'=>'oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'etat_oid','label'=>'etat_oid','type'=>'text','is_transient'=>true,'srcName'=>'etat_oid','ufname'=>'_etat_oid','qname'=>'rct_candidate_etat_oid','isProp'=>'val','sqltype'=>'integer','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'update_date','label'=>'update_date','type'=>'datetime','default'=>'now','srcName'=>'update_date','ufname'=>'_update_date','qname'=>'rct_candidate_update_date',),
array('name'=>'update_info_date','label'=>'update_info_date','type'=>'datetime','srcName'=>'update_info_date','ufname'=>'_update_info_date','qname'=>'rct_candidate_update_info_date',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','etat_oid'=>'etat_oid','_etat_oid'=>'etat_oid','val'=>'etat_oid','update_date'=>'update_date','_update_date'=>'update_date','update_info_date'=>'update_info_date','_update_info_date'=>'update_info_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'recruitment.candidates.mycandidates_tasks','handler'=>'lib.recruitment.vacancies.records.candidates.mycandidates_tasks','table'=>'_rct_candidate');
 ?>