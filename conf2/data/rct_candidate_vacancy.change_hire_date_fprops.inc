<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'hire_date','label'=>'hire_date','type'=>'date','srcName'=>'hire_date','ufname'=>'_hire_date','qname'=>'rct_candidate_vacancy_hire_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','hire_date'=>'hire_date','_hire_date'=>'hire_date',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_vacancy.change_hire_date','table'=>'_rct_candidate_vacancy');
 ?>