<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_vacancy_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'vp_oid','label'=>'vp_oid','type'=>'text','sqltype'=>'integer','show'=>false,'srcName'=>'vp_oid','ufname'=>'_vp_oid','qname'=>'rct_vacancy_vp_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_vacancy_email','size'=>'100','multiLines'=>false,'onSubmitCheck'=>"checkReg('%3\$s',%1\$s.%2\$s,%4\$s,'^[0-9a-zA-Z_.-]+@[0-9a-zA-Z_.-]+\.[0-9a-zA-Z_.-]+','wrong email syntax')",),
array('name'=>'code','label'=>'code','type'=>'text','srcName'=>'code','ufname'=>'_code','qname'=>'rct_vacancy_code','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'name','label'=>'name','type'=>'text','srcName'=>'name','ufname'=>'_name','qname'=>'rct_vacancy_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'ref','label'=>'ref','type'=>'text','srcName'=>'ref','ufname'=>'_ref','qname'=>'rct_vacancy_ref','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'id_index','label'=>'id_index','type'=>'text','size'=>'200','show'=>false,'srcName'=>'id_index','ufname'=>'_id_index','qname'=>'rct_vacancy_id_index','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'index','label'=>'index','type'=>'text','show'=>false,'srcName'=>'index','ufname'=>'_index','qname'=>'rct_vacancy_index','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'offer_name','label'=>'offer_name','type'=>'text','srcName'=>'offer_name','ufname'=>'_offer_name','qname'=>'rct_vacancy_offer_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','vp_oid'=>'vp_oid','_vp_oid'=>'vp_oid','email'=>'email','_email'=>'email','code'=>'code','_code'=>'code','name'=>'name','_name'=>'name','ref'=>'ref','_ref'=>'ref','id_index'=>'id_index','_id_index'=>'id_index','index'=>'index','_index'=>'index','offer_name'=>'offer_name','_offer_name'=>'offer_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy.get_vacancies_by_provider','table'=>'_rct_vacancy');
 ?>