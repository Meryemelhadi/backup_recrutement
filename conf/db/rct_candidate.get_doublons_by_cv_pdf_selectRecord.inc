<?php $properties["query"]="
					SELECT _oid, _first_name, _last_name , _cv_path
					FROM _rct_candidate
					Where `_md5_cv_pdf` = '".$props->getProperty("cv_pdf")."' 
					order by _oid DESC
				"; ?>