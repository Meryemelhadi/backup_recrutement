<?php $properties["fprops"]=array(
array('name'=>'oid','label'=>'oid','type'=>'text','isKey'=>'primary','isEdit'=>false,'show'=>false,'srcName'=>'oid','ufname'=>'_oid','alias'=>'oid','qname'=>'rct_client_oid','onInput'=>"keypress_number(event)",'size'=>'8','maxLength'=>'10','multiLines'=>false,),
array('name'=>'nom_societe','label'=>'nom_societe','type'=>'text','srcName'=>'nom_societe','ufname'=>'_nom_societe','qname'=>'rct_client_nom_societe','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'tel','label'=>'tel','type'=>'text','srcName'=>'tel','ufname'=>'_tel','qname'=>'rct_client_tel','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'fax','label'=>'fax','type'=>'text','srcName'=>'fax','ufname'=>'_fax','qname'=>'rct_client_fax','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'email','label'=>'email','type'=>'text','srcName'=>'email','ufname'=>'_email','qname'=>'rct_client_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'adresse','label'=>'adresse','type'=>'text','srcName'=>'adresse','ufname'=>'_adresse','qname'=>'rct_client_adresse','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'ville','label'=>'ville','type'=>'text','srcName'=>'ville','ufname'=>'_ville','qname'=>'rct_client_ville','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'site_web','label'=>'site_web','type'=>'text','srcName'=>'site_web','ufname'=>'_site_web','qname'=>'rct_client_site_web','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_first_name','label'=>'rep_first_name','type'=>'text','srcName'=>'rep_first_name','ufname'=>'_rep_first_name','qname'=>'rct_client_rep_first_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_last_name','label'=>'rep_last_name','type'=>'text','srcName'=>'rep_last_name','ufname'=>'_rep_last_name','qname'=>'rct_client_rep_last_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_fonction','label'=>'rep_fonction','type'=>'text','srcName'=>'rep_fonction','ufname'=>'_rep_fonction','qname'=>'rct_client_rep_fonction','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_tel_fixe','label'=>'rep_tel_fixe','type'=>'text','srcName'=>'rep_tel_fixe','ufname'=>'_rep_tel_fixe','qname'=>'rct_client_rep_tel_fixe','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_tel_mobile','label'=>'rep_tel_mobile','type'=>'text','srcName'=>'rep_tel_mobile','ufname'=>'_rep_tel_mobile','qname'=>'rct_client_rep_tel_mobile','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_fax','label'=>'rep_fax','type'=>'text','srcName'=>'rep_fax','ufname'=>'_rep_fax','qname'=>'rct_client_rep_fax','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'rep_email','label'=>'rep_email','type'=>'text','srcName'=>'rep_email','ufname'=>'_rep_email','qname'=>'rct_client_rep_email','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'logo','label'=>'logo','type'=>'image','maxSize'=>'200000','imageSize'=>'100x120','imageSizes'=>'original,100x120,80x96','srcName'=>'logo','ufname'=>'_logo','qname'=>'rct_client_logo','isFile'=>'true','onDelete'=>'true',),);
$properties["falias"]=array('oid'=>'oid','_oid'=>'oid','nom_societe'=>'nom_societe','_nom_societe'=>'nom_societe','tel'=>'tel','_tel'=>'tel','fax'=>'fax','_fax'=>'fax','email'=>'email','_email'=>'email','adresse'=>'adresse','_adresse'=>'adresse','ville'=>'ville','_ville'=>'ville','site_web'=>'site_web','_site_web'=>'site_web','rep_first_name'=>'rep_first_name','_rep_first_name'=>'rep_first_name','rep_last_name'=>'rep_last_name','_rep_last_name'=>'rep_last_name','rep_fonction'=>'rep_fonction','_rep_fonction'=>'rep_fonction','rep_tel_fixe'=>'rep_tel_fixe','_rep_tel_fixe'=>'rep_tel_fixe','rep_tel_mobile'=>'rep_tel_mobile','_rep_tel_mobile'=>'rep_tel_mobile','rep_fax'=>'rep_fax','_rep_fax'=>'rep_fax','rep_email'=>'rep_email','_rep_email'=>'rep_email','logo'=>'logo','_logo'=>'logo',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'rct_client.edit','table'=>'_rct_client');
 ?>