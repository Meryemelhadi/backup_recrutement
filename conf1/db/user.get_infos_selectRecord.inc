<?php $properties["query"]="SELECT _oid,_civility,_first_name,_last_name,_email,_role,_mobile_phone,_direct_phone,_local_phone,_personal_phone,_group,_photo FROM _user WHERE _oid in('".$props->getProperty("oid","",true)."')"; ?>