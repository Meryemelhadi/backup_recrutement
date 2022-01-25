<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_lydec_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'budget_O_N','label'=>'budget_O_N','type'=>'text_choice','list'=>'recruitment.budget','control'=>'radio','sqltype'=>'integer','srcName'=>'budget_O_N','ufname'=>'_budget_O_N','qname'=>'rct_vacancy_lydec_budget_O_N','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'budget','label'=>'budget','type'=>'text','srcName'=>'budget','ufname'=>'_budget','qname'=>'rct_vacancy_lydec_budget','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'csp','label'=>'csp','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:directory_csp@admin','ds_format'=>'{field:csp_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'csp','ufname'=>'_csp','qname'=>'rct_vacancy_lydec_csp','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'cc','label'=>'cc','type'=>'text','srcName'=>'cc','ufname'=>'_cc','qname'=>'rct_vacancy_lydec_cc','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'version','label'=>'version','type'=>'text','srcName'=>'version','ufname'=>'_version','qname'=>'rct_vacancy_lydec_version','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'Cout','label'=>'cout','type'=>'text','srcName'=>'Cout','ufname'=>'_Cout','qname'=>'rct_vacancy_lydec_Cout','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','budget_O_N'=>'budget_O_N','_budget_O_N'=>'budget_O_N','budget'=>'budget','_budget'=>'budget','csp'=>'csp','_csp'=>'csp','cc'=>'cc','_cc'=>'cc','version'=>'version','_version'=>'version','Cout'=>'Cout','_Cout'=>'Cout',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_lydec','table'=>'_rct_vacancy_lydec');
 ?>