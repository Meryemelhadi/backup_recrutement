<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_candidate_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'phone_1','label'=>'phone_1','type'=>'text','srcName'=>'phone_1','ufname'=>'_phone_1','qname'=>'rct_candidate_phone_1','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'md5_cv_pdf','label'=>'md5_cv_pdf','type'=>'text','size'=>'40','sqltype'=>'varchar(40)','srcName'=>'md5_cv_pdf','ufname'=>'_md5_cv_pdf','qname'=>'rct_candidate_md5_cv_pdf','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','email'=>'email','_email'=>'email','phone_1'=>'phone_1','_phone_1'=>'phone_1','md5_cv_pdf'=>'md5_cv_pdf','_md5_cv_pdf'=>'md5_cv_pdf',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.get_doublons','table'=>'_rct_candidate');
 ?>