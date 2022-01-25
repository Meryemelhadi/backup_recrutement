<?php $properties["fprops"]=array(
array('name'=>'saved_search','label'=>'saved_search','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:saved_search.by_user','ds_format'=>'{field:name}','ds_field_value'=>'oid','prompt'=>'search...','onchange'=>'loadSearch(this);','default'=>(isset($_REQUEST["search_oid"])?$_REQUEST["search_oid"]:""),'srcName'=>'saved_search','ufname'=>'_saved_search','qname'=>'_saved_search','list'=>'saved_search','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('saved_search'=>'saved_search','_saved_search'=>'saved_search',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.saved_search','table'=>'_');
 ?>