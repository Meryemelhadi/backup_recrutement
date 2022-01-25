<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_interview_synthesis_oid','isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'criterias_entries','label'=>'criterias_entries','type'=>'records','ds'=>'rct_interview_synthesis_criterias.list','ds_record'=>'rct_interview_synthesis_criterias.record','key'=>'oid','fkey'=>'interview_synthesis_oid','view'=>'recruitment.vacancies.subforms.record_sf','edit_view'=>'recruitment.vacancies.subforms.record_sf_form','srcName'=>'criterias_entries','ufname'=>'_criterias_entries','qname'=>'rct_interview_synthesis_criterias_entries','is_transient'=>true,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','criterias_entries'=>'criterias_entries','_criterias_entries'=>'criterias_entries',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_interview_synthesis.delete','table'=>'_rct_interview_synthesis');
 ?>