<?php $properties["query"]="UPDATE _rct_vacancy SET _name=".$record->getFieldValue("name","DB","NULL").",_code=".$record->getFieldValue("code","DB","NULL").",_current_step=".$record->getFieldValue("current_step","DB","NULL")." WHERE _oid='".$this->getParamValue("vacancy_oid","","request",",")."'"; ?>