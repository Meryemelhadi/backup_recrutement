<?php $properties["query"]="
					SELECT _oid 
					FROM _rct_candidate 
					WHERE (LOWER(_first_name) LIKE LOWER('".$_REQUEST['first_name']."')) AND (LOWER(_last_name) LIKE LOWER('".$_REQUEST['last_name']."')) AND (LOWER(_email) LIKE LOWER('".$_REQUEST['email']."'))
				"; ?>