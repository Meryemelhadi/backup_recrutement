<?php $properties["query"]="UPDATE _rct_entreprise_description_rekrute SET _oid=".$record->getFieldValue("oid","DB","NULL").",_name_description=".$record->getFieldValue("name_description","DB","NULL")." WHERE ".$this->getWhereClause("_name_description",$this->getFieldParam("name_description","null","|",$record,""),'LIKE','OR','%','%',true,false,'|','false'); ?>