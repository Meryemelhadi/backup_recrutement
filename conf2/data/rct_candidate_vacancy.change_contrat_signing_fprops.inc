<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'contrat_signing','label'=>'contrat_signing','type'=>'text_choice','list'=>'recruitment.boolean_list','control'=>'select','sqltype'=>'integer','multiple'=>false,'default'=>'0','prompt'=>'select contrat_signing...','srcName'=>'contrat_signing','ufname'=>'_contrat_signing','qname'=>'rct_candidate_vacancy_contrat_signing','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','contrat_signing'=>'contrat_signing','_contrat_signing'=>'contrat_signing',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.change_contrat_signing','table'=>'_rct_candidate_vacancy');
 ?>