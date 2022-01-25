<?php $properties["query"]="

					SELECT
						CONCAT_WS(' ',_rct_candidate._first_name, _rct_candidate._last_name) AS _candidate_full_name,
						_rct_candidate._email AS _to,

						CONCAT_WS(' ',_user._first_name, _user._last_name) AS _user_full_name,
						_user._email AS _user_email,
						_user._oid AS _user_oid,
						
						_rct_interview._oid AS _oid,

						_rct_interview._ical_uid,
						_rct_interview._ical_seq,

						_rct_interview._email_title AS _subject,
						_rct_interview._email_content AS _body,
						_rct_interview._email_docs AS _docs,
						_rct_interview._user_email_title AS _user_subject,
						_rct_interview._user_email_content AS _user_body,
						_rct_interview._user_email_docs AS _user_docs,
						_rct_interview._candidate_email_not AS _candidate_email_not,
						_rct_interview._interviewer_email_not AS _interviewer_email_not,
						_files._files AS _files

					FROM
						_rct_interview

					LEFT JOIN 
					(
						SELECT 
							_interview_oid, 
							GROUP_CONCAT(_file_name SEPARATOR '|||') as _files 
						FROM 
							_rct_interview_attached_file 
						WHERE 
							_interview_oid = '".$props->getProperty("interview_oid")."' 
						GROUP BY 
							_interview_oid

					) AS _files	ON _files._interview_oid = _rct_interview._oid

					LEFT JOIN _rct_candidate ON _rct_candidate._oid = _rct_interview._candidate_oid
					LEFT JOIN _rct_interview_by ON _rct_interview_by._key = _rct_interview._oid
					LEFT JOIN _user ON _user._oid = _rct_interview_by._val

					WHERE
						_rct_interview._oid = '".$props->getProperty("interview_oid")."'	

				"; ?>