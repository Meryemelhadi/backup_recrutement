<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'etat_oid','label'=>'etat_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_candidate_etat.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'integer','isKey'=>'','srcName'=>'etat_oid','ufname'=>'_etat_oid','qname'=>'rct_candidate_vacancy_etat_oid','list'=>'etat_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','etat_oid'=>'etat_oid','_etat_oid'=>'etat_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.edit_state_reader','table'=>'_rct_candidate_vacancy');
 ?>