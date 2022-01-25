<?php $properties["fprops"]=array(
array('name'=>'interview_oid','label'=>'rct_interview_oid','type'=>'text','isKey'=>'secondary','srcName'=>'interview_oid','ufname'=>'_interview_oid','qname'=>'rct_vacancy_comment_interview_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date','label'=>'date','type'=>'date','format'=>'%d/%m/%Y','srcName'=>'date','ufname'=>'_date','qname'=>'rct_vacancy_comment_date','onSubmitCheck'=>"checkDate('%3\$s',%1\$s.%2\$s_day,%1\$s.%2\$s_month,%1\$s.%2\$s_year,%4\$s)",),
array('name'=>'synthesis_oid','label'=>'synthesis_oid','type'=>'text','isKey'=>'secondary','srcName'=>'synthesis_oid','ufname'=>'_synthesis_oid','qname'=>'rct_vacancy_comment_synthesis_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'date_eval','label'=>'date_effectiv','type'=>'datetime','srcName'=>'date_eval','ufname'=>'_date_eval','qname'=>'rct_vacancy_comment_date_eval',),);
$properties["falias"]=array('interview_oid'=>'interview_oid','_interview_oid'=>'interview_oid','date'=>'date','_date'=>'date','synthesis_oid'=>'synthesis_oid','_synthesis_oid'=>'synthesis_oid','date_eval'=>'date_eval','_date_eval'=>'date_eval',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_vacancy_comment.list_by_candidate','table'=>'_rct_vacancy_comment');
 ?>