<?php $properties["query"]="DELETE FROM _rct_services_web WHERE ".$this->getWhereClause("_name",$this->getFieldParam("name","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_url",$this->getFieldParam("url","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_key",$this->getFieldParam("key","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false'); ?>