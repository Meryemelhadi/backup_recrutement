<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_interview_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'time_start','label'=>'time_start','type'=>'datetime','control'=>'time','increment-mn'=>'10','format'=>'%H:%M','srcName'=>'time_start','ufname'=>'_time_start','qname'=>'rct_interview_time_start',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','time_start'=>'time_start','_time_start'=>'time_start',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview.todays_interviews','table'=>'_rct_interview');
 ?>