<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_vacancy_provider WHERE ".$this->getWhereClause("_ref",$this->getFieldParam("ref","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false')." AND ".$this->getWhereClause("_provider_oid",$this->getFieldParam("provider_oid","null","|",$record,""),'=','OR','','',true,false,'|','false')." AND _vacancy_oid='".$props->getProperty("vacancy_oid","",true)."'"; ?>