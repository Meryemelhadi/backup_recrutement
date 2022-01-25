<?php $properties["fprops"]=array(
array('name'=>'sender','label'=>'sender','type'=>'text','is_transient'=>true,'srcName'=>'sender','ufname'=>'_sender','qname'=>'rct_candidate_client_sender','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'sender_email','label'=>'sender_email','type'=>'text','is_transient'=>true,'srcName'=>'sender_email','ufname'=>'_sender_email','qname'=>'rct_candidate_client_sender_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'candidate','label'=>'candidate','type'=>'text','is_transient'=>true,'srcName'=>'candidate','ufname'=>'_candidate','qname'=>'rct_candidate_client_candidate','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'cv_path','label'=>'cv_path','type'=>'file','is_transient'=>true,'srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_client_cv_path','isFile'=>'true',),
array('name'=>'comment','label'=>'comment','type'=>'text','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_candidate_client_comment','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'proposed_to','label'=>'proposed_to','type'=>'text_choice','multiple'=>true,'ds'=>'db:users.ds_list','ds_format'=>'{field:email}','isProp'=>'to','srcName'=>'proposed_to','ufname'=>'_proposed_to','qname'=>'rct_candidate_client_proposed_to','control'=>'facebook_list','ds_field_value'=>'candidate_oid','ds_link'=>'rct_candidate_proposed_to','list'=>'proposed_to','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_client_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'subject','label'=>'subject','type'=>'text','is_transient'=>true,'srcName'=>'subject','ufname'=>'_subject','qname'=>'rct_candidate_client_subject','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'body','label'=>'body','type'=>'text','is_transient'=>true,'srcName'=>'body','ufname'=>'_body','qname'=>'rct_candidate_client_body','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'files','label'=>'files','type'=>'text','is_transient'=>true,'srcName'=>'files','ufname'=>'_files','qname'=>'rct_candidate_client_files','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('sender'=>'sender','_sender'=>'sender','sender_email'=>'sender_email','_sender_email'=>'sender_email','candidate'=>'candidate','_candidate'=>'candidate','cv_path'=>'cv_path','_cv_path'=>'cv_path','comment'=>'comment','_comment'=>'comment','proposed_to'=>'proposed_to','to'=>'proposed_to','_proposed_to'=>'proposed_to','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','subject'=>'subject','_subject'=>'subject','body'=>'body','_body'=>'body','files'=>'files','_files'=>'files',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_client.send_to_many_clients','table'=>'_rct_candidate_client');
 ?>