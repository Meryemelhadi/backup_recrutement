<?php $properties["fprops"]=array(
array('name'=>'vacancy_oid','type'=>'text','value'=>(isset($_REQUEST["oid"])?$_REQUEST["oid"]:""),'label'=>'vacancy_oid','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_vacancy_comment_vacancy_oid','isKey'=>'secondary','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'user_oid','type'=>'text','value'=>$GLOBALS["_NX_user"]->getProperty("oid","",true),'label'=>'user_oid','srcName'=>'user_oid','ufname'=>'_user_oid','qname'=>'rct_vacancy_comment_user_oid','control'=>'select','multiple'=>false,'ds'=>'db:user.ds_list_all@recruitment','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date','type'=>'datetime','value'=>'now','label'=>'date','srcName'=>'date','ufname'=>'_date','qname'=>'rct_vacancy_comment_date','format'=>'Le %d %B %Y &agrave; %H:%M',),
array('name'=>'comment','type'=>'text','label'=>'comment','srcName'=>'comment','ufname'=>'_comment','qname'=>'rct_vacancy_comment_comment','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','user_oid'=>'user_oid','_user_oid'=>'user_oid','date'=>'date','_date'=>'date','comment'=>'comment','_comment'=>'comment',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_comment.add','table'=>'_rct_vacancy_comment');
 ?>