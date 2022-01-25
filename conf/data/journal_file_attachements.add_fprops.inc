<?php $properties["fprops"]=array(
array('name'=>'article_id','type'=>'text','value'=>$props->getProperty("object_oid","",true),'label'=>'article_id','srcName'=>'article_id','ufname'=>'_article_id','qname'=>'journal_file_attachements_article_id','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),
array('name'=>'file_name','type'=>'text','value'=>$props->getProperty("file_name","",true),'label'=>'file_name','srcName'=>'file_name','ufname'=>'_file_name','qname'=>'journal_file_attachements_file_name','multiLines'=>false,'onSubmitCheck'=>"checkText('%3\$s',%1\$s.%2\$s,%4\$s)",),);
$properties["falias"]=array('article_id'=>'article_id','_article_id'=>'article_id','file_name'=>'file_name','_file_name'=>'file_name',);
$properties['frole']=array();
$properties['rprops']=array('name'=>'journal_file_attachements.add','table'=>'_journal_file_attachements');
 ?>