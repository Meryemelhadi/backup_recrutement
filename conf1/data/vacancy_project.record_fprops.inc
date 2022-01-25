<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_project_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'name','label'=>'name','type'=>'text','size'=>'200','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_project_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'description','label'=>'description','type'=>'text','multiLines'=>'auto','size'=>'255','srcName'=>'description','ufname'=>'_description','qname'=>'rct_vacancy_project_description','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','name'=>'name','_name'=>'name','description'=>'description','_description'=>'description',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'vacancy_project.record','table'=>'_rct_vacancy_project');
 ?>