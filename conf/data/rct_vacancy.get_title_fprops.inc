<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'current_step','label'=>'current_step','type'=>'text_choice','list'=>'recruitment.vacancy_step@recruitment','control'=>'select','sqltype'=>'integer','srcName'=>'current_step','ufname'=>'_current_step','qname'=>'rct_vacancy_current_step','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level@recruitment','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','code'=>'code','_code'=>'code','current_step'=>'current_step','_current_step'=>'current_step','progress_level'=>'progress_level','_progress_level'=>'progress_level',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.get_title','table'=>'_rct_vacancy');
 ?>