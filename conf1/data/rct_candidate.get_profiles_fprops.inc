<?php $properties["fprops"]=array(
array('name'=>'profile','prompt'=>'profile ...','label'=>'profile','type'=>'text_choice','controlx'=>'facebook_list','control'=>'select','multiple'=>false,'ds'=>'db:rct_keyword.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'name','csv_sep'=>',','srcName'=>'profile','ufname'=>'_profile','qname'=>'rct_candidate_profile','list'=>'profile','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('profile'=>'profile','_profile'=>'profile',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.get_profiles','table'=>'_rct_candidate');
 ?>