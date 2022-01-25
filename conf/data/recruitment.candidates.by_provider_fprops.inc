<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_candidate_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'expression','value'=>'{field.object:oid}','isKey'=>'secondary','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_candidate_candidate_oid','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'assoc_oid','type'=>'text','isKey'=>'secondary','label'=>'assoc_oid','srcName'=>'assoc_oid','ufname'=>'_assoc_oid','qname'=>'rct_candidate_assoc_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'first_name','label'=>'first_name','type'=>'text','srcName'=>'first_name','ufname'=>'_first_name','qname'=>'rct_candidate_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'last_name','label'=>'last_name','type'=>'text','srcName'=>'last_name','ufname'=>'_last_name','qname'=>'rct_candidate_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'age','label'=>'age','type'=>'text','is_transient'=>true,'srcName'=>'age','ufname'=>'_age','qname'=>'rct_candidate_age','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'town_name','label'=>'town_name','type'=>'text','is_transient'=>true,'srcName'=>'town_name','ufname'=>'_town_name','qname'=>'rct_candidate_town_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'diploma_type','label'=>'diploma_type','type'=>'text','is_transient'=>true,'srcName'=>'diploma_type','ufname'=>'_diploma_type','qname'=>'rct_candidate_diploma_type','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'institution','label'=>'institution','type'=>'text','is_transient'=>true,'srcName'=>'institution','ufname'=>'_institution','qname'=>'rct_candidate_institution','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'cv_path','label'=>'cv_path','type'=>'text','srcName'=>'cv_path','ufname'=>'_cv_path','qname'=>'rct_candidate_cv_path','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'years_of_practice','label'=>'years_of_practice','type'=>'text','srcName'=>'years_of_practice','ufname'=>'_years_of_practice','qname'=>'rct_candidate_years_of_practice','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'keywords','label'=>'keywords','type'=>'text','multiLines'=>'auto','show'=>false,'srcName'=>'keywords','ufname'=>'_keywords','qname'=>'rct_candidate_keywords','onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'summary_keywords','label'=>'summary_keywords','type'=>'expression','field'=>'keywords','control_html'=>'summary','srcName'=>'summary_keywords','ufname'=>'_summary_keywords','qname'=>'rct_candidate_summary_keywords','is_transient'=>true,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rating','label'=>'rating','type'=>'text','srcName'=>'rating','ufname'=>'_rating','qname'=>'rct_candidate_rating','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'status','label'=>'status','type'=>'text_choice','list'=>'recruitment.candidate_vacancy_action','control'=>'select','sqltype'=>'integer','srcName'=>'status','ufname'=>'_status','qname'=>'rct_candidate_status','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'is_visible','label'=>'is_visible','type'=>'text_choice','list'=>'recruitment.boolean_list','control'=>'checkbox','multiple'=>false,'default'=>'0','sqltype'=>'integer','isKey'=>'secondary','srcName'=>'is_visible','ufname'=>'_is_visible','qname'=>'rct_candidate_is_visible','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','assoc_oid'=>'assoc_oid','_assoc_oid'=>'assoc_oid','first_name'=>'first_name','_first_name'=>'first_name','last_name'=>'last_name','_last_name'=>'last_name','age'=>'age','_age'=>'age','town_name'=>'town_name','_town_name'=>'town_name','diploma_type'=>'diploma_type','_diploma_type'=>'diploma_type','institution'=>'institution','_institution'=>'institution','cv_path'=>'cv_path','_cv_path'=>'cv_path','years_of_practice'=>'years_of_practice','_years_of_practice'=>'years_of_practice','keywords'=>'keywords','_keywords'=>'keywords','summary_keywords'=>'summary_keywords','_summary_keywords'=>'summary_keywords','rating'=>'rating','_rating'=>'rating','status'=>'status','_status'=>'status','is_visible'=>'is_visible','_is_visible'=>'is_visible',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'recruitment.candidates.by_provider','handler'=>'lib.recruitment.vacancies.records.candidates.providers.list','table'=>'_rct_candidate');
 ?>