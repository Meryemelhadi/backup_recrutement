<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date_of_birth','label'=>'date_of_birth','type'=>'date','srcName'=>'date_of_birth','ufname'=>'_date_of_birth','qname'=>'rct_candidate_date_of_birth','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','date_of_birth'=>'date_of_birth','_date_of_birth'=>'date_of_birth',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_date_of_birth','table'=>'_rct_candidate');
 ?>