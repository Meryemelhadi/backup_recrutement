<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_history_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date','label'=>'date','type'=>'datetime','default'=>'now','srcName'=>'date','ufname'=>'_date','qname'=>'rct_vacancy_history_date',),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_vacancy_history_vacancy_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level@recruitment','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_history_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level_meta','label'=>'progress_level_meta','type'=>'text','srcName'=>'progress_level_meta','ufname'=>'_progress_level_meta','qname'=>'rct_vacancy_history_progress_level_meta','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','date'=>'date','_date'=>'date','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','progress_level'=>'progress_level','_progress_level'=>'progress_level','progress_level_meta'=>'progress_level_meta','_progress_level_meta'=>'progress_level_meta',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_history.by_vacancy_resume','table'=>'_rct_vacancy_history');
 ?>