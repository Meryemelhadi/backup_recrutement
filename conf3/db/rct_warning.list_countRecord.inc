<?php $properties["query"]="SELECT COUNT(*) as nbrecords FROM _rct_warning WHERE _vacancy_oid='".$this->getParamValue("oid","","request",",")."'"; ?>