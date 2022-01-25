<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','srcName'=>'oid','ufname'=>'_oid','qname'=>'rct_email_oid','show'=>false,'isEdit'=>false,'onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'candidate_oid','label'=>'candidate_oid','type'=>'text_choice','control'=>'checkbox','multiple'=>true,'ds'=>'db:rct_candidate.ds_list','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'candidate_oid','ufname'=>'_candidate_oid','qname'=>'rct_email_candidate_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'vacancy_oid','label'=>'vacancy_oid','type'=>'text_choice','control'=>'checkbox','multiple'=>true,'ds'=>'db:rct_vacancy.ds_list','ds_format'=>'{field:name} ({field:code})','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'vacancy_oid','ufname'=>'_vacancy_oid','qname'=>'rct_email_vacancy_oid','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'created_by','label'=>'created_by','type'=>'text_choice','control'=>'checkbox','multiple'=>true,'ds'=>'db:user.ds_list','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','sqltype'=>'integer','srcName'=>'created_by','ufname'=>'_created_by','qname'=>'rct_email_created_by','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'creation_date','label'=>'creation_date','type'=>'datetime','srcName'=>'creation_date','ufname'=>'_creation_date','qname'=>'rct_email_creation_date',),
array('name'=>'user_cc','label'=>'user_cc','type'=>'text_choice_table','list'=>'product_range','prompt'=>'user_cc...','multiple'=>true,'control'=>'facebook_list','ds'=>'db:user.ds_list_all@recruitment','ds_link'=>'rct_candidate_email_cc','ds_format'=>'{field:first_name} {field:last_name}','ds_field_value'=>'oid','srcName'=>'user_cc','ufname'=>'_user_cc','qname'=>'rct_email_user_cc','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'email_type','label'=>'email_type','type'=>'text_choice','list'=>'recruitment.email_type.all','control'=>'select','sqltype'=>'integer','prompt'=>'Sélectionnez email type ...','default'=>'1','srcName'=>'email_type','ufname'=>'_email_type','qname'=>'rct_email_email_type','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'email_title','label'=>'email_title','size'=>'500','type'=>'text','csslayout'=>'normal-layout','srcName'=>'email_title','ufname'=>'_email_title','qname'=>'rct_email_email_title','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email_content','label'=>'email_content','type'=>'rich_text','csslayout'=>'normal-layout','srcName'=>'email_content','ufname'=>'_email_content','qname'=>'rct_email_email_content','control'=>'rich_text','onSubmitCheck'=>"checkRichText('%3\$s','%2\$s',%4\$s,%1\$s.%2\$s)",),
array('name'=>'docs','label'=>'docs','type'=>'text_choice','control'=>'checkbox','multiple'=>true,'columns'=>'2','controlLayout'=>'table','ds'=>'db:email_docs.ds_list','ds_format'=>'{field:name}','ds_field_value'=>'oid','sqltype'=>'varchar(255)','srcName'=>'docs','ufname'=>'_docs','qname'=>'rct_email_docs','onSubmitCheck'=>"checkSelect('%3\$s',(%1\$s.%2\$s||%1\$s['%2\$s[]']),%4\$s)",),
array('name'=>'attached_files','type'=>'records','ds'=>'rct_email_attached_file.by_email@recruitment','ds_record'=>'rct_email_attached_file.record@recruitment','key'=>'oid','fkey'=>'email_oid','edit_view_list'=>'workflow.subforms.sf_attachedfiles@workflow','edit_view'=>'workflow.subforms.sf_attachedfiles@workflow','insert_new'=>'bottom','label'=>'attached_files','srcName'=>'attached_files','ufname'=>'_attached_files','qname'=>'rct_email_attached_files','is_transient'=>true,),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','candidate_oid'=>'candidate_oid','_candidate_oid'=>'candidate_oid','vacancy_oid'=>'vacancy_oid','_vacancy_oid'=>'vacancy_oid','created_by'=>'created_by','_created_by'=>'created_by','creation_date'=>'creation_date','_creation_date'=>'creation_date','user_cc'=>'user_cc','_user_cc'=>'user_cc','email_type'=>'email_type','_email_type'=>'email_type','email_title'=>'email_title','_email_title'=>'email_title','email_content'=>'email_content','_email_content'=>'email_content','docs'=>'docs','_docs'=>'docs','attached_files'=>'attached_files','_attached_files'=>'attached_files',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_email','table'=>'_rct_email');
 ?>