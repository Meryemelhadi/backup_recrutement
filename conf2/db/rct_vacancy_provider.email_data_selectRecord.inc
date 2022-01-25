<?php $properties["query"]="

					SELECT

						_rct_provider._email AS _to,
						_rct_vacancy_provider._email_title AS _subject,
						_rct_vacancy_provider._email_content AS _body,
						_files._files AS _files

					FROM
						_rct_vacancy_provider				

					LEFT JOIN (

						SELECT 

							_vacancy_provider_oid, 
							GROUP_CONCAT(_file_name SEPARATOR '|||') as _files 

						FROM 
							_rct_vacancy_provider_attached_file 

						WHERE 
							_vacancy_provider_oid = '".$this->getProperty("vacancy_provider_oid")."'

						GROUP BY 
							_vacancy_provider_oid) AS _files

						ON _files._vacancy_provider_oid = _rct_vacancy_provider._oid

					LEFT JOIN
						_rct_provider ON _rct_provider._oid = _rct_vacancy_provider._provider_oid

					WHERE
						_rct_vacancy_provider._oid = '".$this->getProperty("vacancy_provider_oid")."'
				"; ?>