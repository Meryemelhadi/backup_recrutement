<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_email_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'creation_date','label'=>'creation_date','type'=>'datetime','format'=>'%d/%m/%Y &agrave; %H:%M','srcName'=>'creation_date','ufname'=>'_creation_date','qname'=>'rct_email_creation_date',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','creation_date'=>'creation_date','_creation_date'=>'creation_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email.candidate_emails','table'=>'_rct_email');
 ?>