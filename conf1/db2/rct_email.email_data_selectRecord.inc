<?php $properties["query"]="

					SELECT

						CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) AS _candidate_full_name,
						_rct_candidate._email AS _to,
						_rct_email._email_title AS _subject,
						_rct_email._email_content AS _body,
						_rct_email._email_docs AS _docs,
						_files._files AS _files

					FROM
						_rct_email					

					LEFT JOIN (

						SELECT 

							_email_oid, 
							GROUP_CONCAT(_file_name SEPARATOR '|||') as _files 

						FROM 
							_rct_email_attached_file 

						WHERE 
							_email_oid = '".$this->getProperty("email_oid")."' 

						GROUP BY 
							_email_oid) AS _files

						ON _files._email_oid = _rct_email._oid


					LEFT JOIN
						_rct_candidate ON _rct_candidate._oid = _rct_email._candidate_oid

					WHERE
						_rct_email._oid = '".$this->getProperty("email_oid")."'
				

				"; ?>