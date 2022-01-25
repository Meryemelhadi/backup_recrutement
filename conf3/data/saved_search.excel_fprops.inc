<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'object_id','type'=>'text','isKey'=>'primary','show'=>false,'isEdit'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_saved_search_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_saved_search_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'url','label'=>'url','type'=>'text','srcName'=>'url','ufname'=>'_url','qname'=>'rct_saved_search_url','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','url'=>'url','_url'=>'url',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'saved_search.excel','table'=>'_rct_saved_search');
 ?>