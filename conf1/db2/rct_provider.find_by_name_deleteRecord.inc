<?php $properties["query"]="DELETE FROM _rct_provider WHERE ".$this->getWhereClause("_name","'".$props->getProperty("provider_name","",true)."'",'LIKE','OR','%','%',true,false,'|','false'); ?>