<?php $properties["query"]="SELECT _oid,_vacancy_oid,_provider_oid,_ref,_from_email,_to_email FROM _rct_vacancy_provider WHERE (_from_email='".$props->getProperty("email","",true)."' OR _to_email='".$props->getProperty("email","",true)."') "; ?>