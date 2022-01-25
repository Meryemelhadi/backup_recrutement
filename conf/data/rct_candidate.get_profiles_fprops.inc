<?php $properties["fprops"]=array(
array('name'=>'profile','prompt'=>'profile ...','label'=>'profile','type'=>'text_choice_table','control'=>'facebook_list','multiple'=>true,'ds'=>'db:rct_keyword.ds_list@recruitment','ds_link'=>'rct_candidate_keyword_assoc','ds_format'=>'{field:name}','ds_field_value'=>'key','csv_sep'=>',','srcName'=>'profile','ufname'=>'_profile','qname'=>'rct_candidate_profile','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('profile'=>'profile','_profile'=>'profile',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.get_profiles','table'=>'_rct_candidate');
 ?>