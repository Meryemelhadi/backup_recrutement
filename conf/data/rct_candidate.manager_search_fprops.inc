<?php $properties["fprops"]=array(
array('name'=>'full_text_search','label'=>'full_text_search','type'=>'text','is_transient'=>true,'srcName'=>'full_text_search','ufname'=>'_full_text_search','qname'=>'rct_candidate_full_text_search','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'first_name','label'=>'first_name','type'=>'text','size'=>'200','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'vacancy','label'=>'vacancy','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_vacancy.client_list_search','ds_format'=>'{field:name} (N {field:code})','ds_field_value'=>'oid','is_transient'=>true,'srcName'=>'vacancy','ufname'=>'_vacancy','qname'=>'rct_candidate_vacancy','list'=>'vacancy','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('full_text_search'=>'full_text_search','_full_text_search'=>'full_text_search','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','vacancy'=>'vacancy','_vacancy'=>'vacancy',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.manager_search','table'=>'_rct_candidate');
 ?>