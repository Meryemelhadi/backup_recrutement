<?php $properties["fprops"]=array(
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_search_params_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'is_default','label'=>'is_default','type'=>'text_choice','control'=>'select','list'=>'recruitment.boolean_list','prompt'=>'choisir...','srcName'=>'is_default','ufname'=>'_is_default','qname'=>'rct_search_params_is_default','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('name'=>'name','_name'=>'name','is_default'=>'is_default','_is_default'=>'is_default',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'search_params.search','table'=>'_rct_search_params');
 ?>