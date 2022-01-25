<?php $properties["query"]="
					SELECT _oid, _first_name, _last_name , _cv_path , _etat_oid , _creation_date , _add_date , _update_date , _provider, _hr_manager 
					FROM _rct_candidate
					Where _first_name = '".$props->getProperty("first_name")."' and _last_name = '".$props->getProperty("last_name")."' and _email = '".$props->getProperty("email")."' 
					order by _oid DESC
				"; ?>