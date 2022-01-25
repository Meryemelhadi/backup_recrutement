<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_interview_attached_file_candidate_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'interview_oid','label'=>'interview_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'interview_oid','ufname'=>'_interview_oid','qname'=>'rct_interview_attached_file_candidate_interview_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'file_name','label'=>'file_name','type'=>'text','show'=>false,'srcName'=>'file_name','ufname'=>'_file_name','qname'=>'rct_interview_attached_file_candidate_file_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'file','label'=>'file','type'=>'file','control'=>'file_no_update','srcName'=>'file','ufname'=>'_file','qname'=>'rct_interview_attached_file_candidate_file','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','interview_oid'=>'interview_oid','_interview_oid'=>'interview_oid','file_name'=>'file_name','_file_name'=>'file_name','file'=>'file','_file'=>'file',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview_attached_file_candidate.get_record','table'=>'_rct_interview_attached_file_candidate');
 ?>