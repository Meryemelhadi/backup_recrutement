<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_education_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text','isKey'=>'secondary','show'=>false,'srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_education_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date','label'=>'date','type'=>'date','control'=>'date_Y','onSubmitCheck'=>"",'srcName'=>'date','ufname'=>'_date','qname'=>'rct_education_date',),
array('name'=>'institution','prompt'=>'institution...','label'=>'institution','type'=>'text_choice','control'=>'select','multiple'=>false,'ds'=>'db:rct_school.ds_list','ds_format'=>'{field:label}','ds_field_value'=>'code','srcName'=>'institution','ufname'=>'_institution','qname'=>'rct_education_institution','list'=>'institution','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'description','label'=>'description','type'=>'text','multiLines'=>'auto','size'=>'255','srcName'=>'description','ufname'=>'_description','qname'=>'rct_education_description','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','date'=>'date','_date'=>'date','institution'=>'institution','_institution'=>'institution','description'=>'description','_description'=>'description',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_education_2','table'=>'_rct_education');
 ?>