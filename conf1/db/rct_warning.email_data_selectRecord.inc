<?php $properties["query"]="

					SELECT

						_vc._name AS vacancy_name,

						_w._subject AS _notification_subject,

						_w._notification_content AS _notification_content,

						_w._concerned_people AS _concerned_people

					FROM _rct_warning _w

					LEFT JOIN _rct_vacancy _vc ON _vc._oid = _w._vacancy_oid

					WHERE

						_w._notification_state = '0'

					AND

						_w._date <= NOW()

				"; ?>