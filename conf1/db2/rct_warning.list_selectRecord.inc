<?php $properties["query"]="

					SELECT

						_rct_warning._oid as _oid,

						_rct_warning._vacancy_oid as _vacancy_oid,

						CONCAT_WS(' ',_user2._first_name, _user2._last_name) as _scheduled_by,

						_rct_warning._scheduled_on as _scheduled_on,

						_rct_warning._date as _date,

						_rct_warning._subject as _subject,

						_rct_warning._notification_content as _notification_content,

						GROUP_CONCAT(CONCAT_WS(' ',_user._first_name, _user._last_name) SEPARATOR ', ') as _concerned_people

					FROM

						_rct_warning

					LEFT JOIN

						_rct_warning_concerned_people ON _rct_warning._oid = _rct_warning_concerned_people._key

					LEFT JOIN

						_user ON _rct_warning_concerned_people._val = _user._oid

					LEFT JOIN _user as _user2 ON _user2._oid = _rct_warning._scheduled_by

					WHERE

						_rct_warning._vacancy_oid = '".$_REQUEST['oid']."'

					GROUP BY

						_rct_warning._oid

				"; ?>