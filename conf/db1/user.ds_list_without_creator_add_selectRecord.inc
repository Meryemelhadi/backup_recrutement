<?php $properties["query"]="SELECT _oid,_first_name,_last_name FROM _user WHERE _oid<>'".$GLOBALS["_NX_user"]->getProperty("oid","",true)."'"; ?>