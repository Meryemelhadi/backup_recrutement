<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','cv_path'=>'cv_path','_cv_path'=>'cv_path',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.get_doublons_by_cv_pdf','table'=>'_rct_candidate');
 ?>