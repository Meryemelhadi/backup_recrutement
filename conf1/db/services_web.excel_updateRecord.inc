<?php $properties["query"]="UPDATE _rct_services_web SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name=".$record->getFieldValue("name","DB","NULL").",_url=".$record->getFieldValue("url","DB","NULL").",_key=".$record->getFieldValue("key","DB","NULL").",_type=".$record->getFieldValue("type","DB","NULL")." WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_url",$this->getFieldParam("url","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_key",$this->getFieldParam("key","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false'); ?>