<?php $properties["query"]="DELETE FROM _rct_vacancy_action WHERE ".$this->getWhereClause("_code","'".$props->getProperty("vacancy_code","",true)."'",'LIKE','OR','%','%',true,false,'|'); ?>