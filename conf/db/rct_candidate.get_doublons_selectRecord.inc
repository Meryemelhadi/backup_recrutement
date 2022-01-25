<?php $properties["query"]="
					SELECT c, _oid, _first_name, _last_name , _email , `_phone_1` , `_md5_cv_pdf`
					FROM (

					SELECT COUNT( * ) AS c, _oid, _first_name, _last_name ,`_phone_1`, _email , `_md5_cv_pdf`
					FROM  `_rct_candidate` 
					
					GROUP BY  _first_name, _last_name , _email
					) AS s
					WHERE c >1
				"; ?>