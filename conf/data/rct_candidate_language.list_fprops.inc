<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_language_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','isKey'=>'secondary','show'=>false,'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_language_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'lang','label'=>'language','type'=>'text_choice','control'=>'select','multiple'=>false,'list'=>'recruitment.lang','srcName'=>'lang','ufname'=>'_lang','qname'=>'rct_candidate_language_lang','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'language_level','label'=>'language_level','type'=>'text_choice','list'=>'recruitment.language_level','control'=>'select','sqltype'=>'integer','srcName'=>'language_level','ufname'=>'_language_level','qname'=>'rct_candidate_language_language_level','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','lang'=>'lang','_lang'=>'lang','language_level'=>'language_level','_language_level'=>'language_level',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_candidate_language.list','table'=>'_rct_candidate_language');
 ?>