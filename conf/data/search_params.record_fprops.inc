<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_search_params_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_search_params_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'fields','label'=>'fields','type'=>'text_choice','list'=>'recruitment.search_fields@recruitment','control'=>'checkbox','multiple'=>true,'controlLayout'=>'table','columns'=>'4','srcName'=>'fields','ufname'=>'_fields','qname'=>'rct_search_params_fields','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'is_default','label'=>'is_default','type'=>'text_choice','list'=>'recruitment.boolean_list','control'=>'checkbox_boolean','controlLayout'=>'table','columns'=>'4','srcName'=>'is_default','ufname'=>'_is_default','qname'=>'rct_search_params_is_default','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','fields'=>'fields','_fields'=>'fields','is_default'=>'is_default','_is_default'=>'is_default',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'search_params.record','table'=>'_rct_search_params');
 ?>