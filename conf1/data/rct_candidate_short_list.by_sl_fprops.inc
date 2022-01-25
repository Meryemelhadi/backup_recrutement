<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_short_list_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'short_list_oid','type'=>'text','sqltype'=>'integer','label'=>'short_list_oid','srcName'=>'short_list_oid','ufname'=>'_short_list_oid','qname'=>'rct_candidate_short_list_short_list_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','type'=>'text','sqltype'=>'integer','label'=>'candidate_oid','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_short_list_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','short_list_oid'=>'short_list_oid','_short_list_oid'=>'short_list_oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_short_list.by_sl','table'=>'_rct_candidate_short_list');
 ?>