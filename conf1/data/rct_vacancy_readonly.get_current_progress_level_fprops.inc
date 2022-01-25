<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_readonly_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'progress_level','label'=>'progress_level','type'=>'text_choice','list'=>'recruitment.vacancy_progress_level','control'=>'select','sqltype'=>'integer','srcName'=>'progress_level','ufname'=>'_progress_level','qname'=>'rct_vacancy_readonly_progress_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'progress_level_meta','label'=>'progress_level_meta','type'=>'expression','field'=>'progress_level','key'=>'oid','control_html'=>'progress_level','srcName'=>'progress_level_meta','ufname'=>'_progress_level_meta','qname'=>'rct_vacancy_readonly_progress_level_meta','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','progress_level'=>'progress_level','_progress_level'=>'progress_level','progress_level_meta'=>'progress_level_meta','_progress_level_meta'=>'progress_level_meta',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_readonly.get_current_progress_level','table'=>'_rct_vacancy_readonly');
 ?>