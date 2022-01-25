<?php $properties["query"]="

					SELECT

						_fb._oid AS _feedback_oid,

						CONCAT_WS(' ',_cd._first_name, _cd._last_name) AS _candidate_name,

						CONCAT_WS(' ',_user._first_name, _user._last_name) AS _full_name,

						_vc._name AS _vacancy_name,

						_user._email AS _to

					FROM _rct_delayed_feedback _fb

					LEFT JOIN _user ON _user._oid = _fb._filled_by

					LEFT JOIN _rct_candidate _cd ON _fb._candidate_oid = _cd._oid

					LEFT JOIN _rct_vacancy _vc ON _vc._oid = _fb._vacancy_oid

					WHERE

						_fb._notification_state = '0'

					AND

						_fb._launch_date <= NOW()

				"; ?>