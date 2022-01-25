<?php $properties["fprops"]=array(
array('name'=>'interview_oid','type'=>'text','value'=>$props->getProperty("object_oid","",true),'label'=>'interview_oid','srcName'=>'interview_oid','ufname'=>'_interview_oid','qname'=>'rct_interview_attached_file_interviewer_interview_oid','isKey'=>'secondary','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'file_name','type'=>'text','value'=>$props->getProperty("file_name","",true),'label'=>'file_name','srcName'=>'file_name','ufname'=>'_file_name','qname'=>'rct_interview_attached_file_interviewer_file_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('interview_oid'=>'interview_oid','_interview_oid'=>'interview_oid','file_name'=>'file_name','_file_name'=>'file_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview_attached_file_interviewer.add_record','table'=>'_rct_interview_attached_file_interviewer');
 ?>