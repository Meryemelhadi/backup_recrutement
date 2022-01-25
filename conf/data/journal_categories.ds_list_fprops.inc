<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'object id','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'journal_categories_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'category_label','label'=>'category label','type'=>'text','srcName'=>'category_label','ufname'=>'_category_label','qname'=>'journal_categories_category_label','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'category_description','label'=>'category description','type'=>'text','size'=>'255','srcName'=>'category_description','ufname'=>'_category_description','qname'=>'journal_categories_category_description','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','category_label'=>'category_label','_category_label'=>'category_label','category_description'=>'category_description','_category_description'=>'category_description',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'journal_categories.ds_list','table'=>'_journal_categories');
 ?>