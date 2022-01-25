<?php $properties["fprops"]=array(
array('name'=>'id_index','label'=>'id_index','type'=>'text','size'=>'200','show'=>false,'srcName'=>'id_index','ufname'=>'_id_index','qname'=>'rct_vacancy_provider_id_index','default'=>'0','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'index','label'=>'index','type'=>'text','show'=>false,'srcName'=>'index','ufname'=>'_index','qname'=>'rct_vacancy_provider_index','default'=>'0','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),);
$properties["falias"]=array('id_index'=>'id_index','_id_index'=>'id_index','index'=>'index','_index'=>'index',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_provider.get_id','table'=>'_rct_vacancy_provider');
 ?>