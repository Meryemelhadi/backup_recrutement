<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_files_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_files_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'file','label'=>'file','type'=>'file','srcName'=>'file','ufname'=>'_file','qname'=>'rct_candidate_files_file','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','file'=>'file','_file'=>'file',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_files','table'=>'_rct_candidate_files');
 ?>