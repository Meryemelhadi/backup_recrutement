<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_saved_search_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_saved_search_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'url','label'=>'url','type'=>'text','srcName'=>'url','ufname'=>'_url','qname'=>'rct_saved_search_url','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'user_oid','label'=>'user_oid','type'=>'text','isKey'=>'secondary','sqltype'=>'integer','show'=>false,'value'=>$GLOBALS["_NX_user"]->getProperty("oid","",true),'srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_saved_search_user_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','url'=>'url','_url'=>'url','user_oid'=>'user_oid','_user_oid'=>'user_oid',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'saved_search.record','table'=>'_rct_saved_search');
 ?>