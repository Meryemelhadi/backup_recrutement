<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','alias'=>'oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_candidate_email','size'=>'100','multiLines'=>false,'onSubmitCheck'=>"checkReg('%3\$s',%1\$s.%2\$s,%4\$s,'^[0-9a-zA-Z_.-]+@[0-9a-zA-Z_.-]+\.[0-9a-zA-Z_.-]+','wrong email syntax')",),
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','isFile'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','email'=>'email','_email'=>'email','cv_path'=>'cv_path','_cv_path'=>'cv_path',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'candidates.ds_list','table'=>'_rct_candidate');
 ?>