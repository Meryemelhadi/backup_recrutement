<?php $properties["query"]="

					SELECT

						CONCAT_WS(' ',_cl._first_name, _cl._last_name) AS _full_name,

						CONCAT_WS(' ',_us._first_name, _us._last_name) AS _scheduler_full_name,

						_cl._email AS _to,

						_rct_vacancy._name AS _vacancy_name

					FROM

						_rct_instant_feedback AS _fb

					LEFT JOIN _user _cl ON _cl._oid = _fb._filled_by

					LEFT JOIN _user _us ON _us._oid = _fb._scheduled_by

					LEFT JOIN _rct_vacancy ON _rct_vacancy._oid = _fb._vacancy_oid

					WHERE 

						_fb._oid = '".$this->getProperty("record_oid")."'

				"; ?>