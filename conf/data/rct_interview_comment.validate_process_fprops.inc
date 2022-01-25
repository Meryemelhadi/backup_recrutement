<?php $properties["fprops"]=array(
array('name'=>'validation_state','type'=>'text','value'=>$props->getProperty("validation_state","",true),'label'=>'validation_state','srcName'=>'validation_state','ufname'=>'_validation_state','qname'=>'rct_interview_comment_validation_state','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'validated_by','type'=>'text','value'=>$GLOBALS["_NX_user"]->getProperty("oid","",true),'label'=>'validated_by','srcName'=>'validated_by','ufname'=>'_validated_by','qname'=>'rct_interview_comment_validated_by','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('validation_state'=>'validation_state','_validation_state'=>'validation_state','validated_by'=>'validated_by','_validated_by'=>'validated_by',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview_comment.validate_process','table'=>'_rct_interview_comment');
 ?>