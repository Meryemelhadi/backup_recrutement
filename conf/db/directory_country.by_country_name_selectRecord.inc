<?php $properties["query"]="SELECT _oid,_country_name FROM _directory_country WHERE ".$this->getWhereClause("_country_name","'".$props->getProperty("country_name","",true)."'",'LIKE','OR','%','%',true,false,'|','false')." GROUP BY _country_name  ORDER BY _country_name ASC "; ?>