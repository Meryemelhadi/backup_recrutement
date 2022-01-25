<?php $properties["fprops"]=array(
array('name'=>'candidate_oid','label'=>'vacancy_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_comment_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_comment.get_all_candidates','table'=>'_rct_candidate_comment');
 ?>