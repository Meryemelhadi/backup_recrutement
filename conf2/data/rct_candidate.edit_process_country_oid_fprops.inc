<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'country_oid','label'=>'country_oid','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:directory_country.ds_list','ds_format'=>'{field:country_name}','ds_field_value'=>'oid','srcName'=>'country_oid','ufname'=>'_country_oid','qname'=>'rct_candidate_country_oid','sqltype'=>'integer','list'=>'country_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','country_oid'=>'country_oid','_country_oid'=>'country_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate.edit_process_country_oid','table'=>'_rct_candidate');
 ?>