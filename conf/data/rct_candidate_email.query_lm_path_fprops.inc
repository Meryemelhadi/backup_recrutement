<?php $properties["fprops"]=array(
array('name'=>'candidate_oid','label'=>'candidate','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_email_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_email_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'lm','label'=>'lm','type'=>'file','srcName'=>'lm','ufname'=>'_lm','qname'=>'rct_candidate_email_lm','isFile'=>'true',),);
$properties["falias"]=array('candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','oid'=>'oid','_oid'=>'oid','lm'=>'lm','_lm'=>'lm',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_email.query_lm_path','table'=>'_rct_candidate_email');
 ?>