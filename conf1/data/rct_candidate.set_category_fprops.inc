<?php $properties["fprops"]=array(
array('name'=>'category_oid','label'=>'category_oid','type'=>'text_choice_table','prompt'=>'category_oid...','multiple'=>false,'control'=>'select','ds'=>'db:rct_candidate_category.list@recruitment','ds_link'=>'rct_candidate_category_assoc@recruitment','ds_format'=>'{field:name}','ds_field_value'=>'oid','srcName'=>'category_oid','ufname'=>'_category_oid','qname'=>'rct_candidate_category_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('category_oid'=>'category_oid','_category_oid'=>'category_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.set_category','table'=>'_rct_candidate');
 ?>