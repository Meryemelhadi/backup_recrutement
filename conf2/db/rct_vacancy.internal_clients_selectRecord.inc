<?php $properties["query"]="

					SELECT 
						_oid,
						_first_name,
						_last_name 
					FROM 
						_user
					WHERE 
						_oid IN (SELECT _val FROM _rct_vacancy_client WHERE _key = '".$this->getProperty("vacancy_oid")."')

				"; ?>