<?php $properties["query"]="UPDATE _rct_candidate SET _relevance='".$props->getProperty("relevance_oid","",true)."' WHERE ".$this->getWhereClause("_oid",$this->getFieldParam("oid","null","|",$record,""),'=','OR','','',true,false,'|','false'); ?>