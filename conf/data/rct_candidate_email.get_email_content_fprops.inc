<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_email_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'email_content','label'=>'email_content','type'=>'rich_text','csslayout'=>'normal-layout','srcName'=>'email_content','ufname'=>'_email_content','qname'=>'rct_candidate_email_email_content','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','email_content'=>'email_content','_email_content'=>'email_content',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_email.get_email_content','table'=>'_rct_candidate_email');
 ?>