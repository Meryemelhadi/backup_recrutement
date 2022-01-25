<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','isFile'=>'true',),
array('name'=>'cl_path','label'=>'cl_path','type'=>'file','srcName'=>'cl_path','ufname'=>'_cl_path','qname'=>'rct_candidate_cl_path','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','cv_path'=>'cv_path','_cv_path'=>'cv_path','cl_path'=>'cl_path','_cl_path'=>'cl_path',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.query_cv_path','table'=>'_rct_candidate');
 ?>