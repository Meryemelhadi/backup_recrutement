<?php $properties["query"]="

					SELECT
						_rct_vacancy_provider._oid,
						_rct_vacancy_provider._vacancy_oid,
						_rct_vacancy_provider._provider_oid

					FROM 
						_rct_vacancy_provider

					LEFT JOIN _rct_vacancy ON _rct_vacancy_provider._vacancy_oid = _rct_vacancy._oid
					LEFT JOIN _rct_provider ON _rct_vacancy_provider._provider_oid = _rct_provider._oid

					WHERE
						(
							_rct_vacancy._code = '".$this->getProperty("vacancy_code")."' OR
							_rct_vacancy._name = '".$this->getProperty("vacancy_code")."' OR
							_rct_vacancy_provider._ref = '".$this->getProperty("vacancy_code")."'
						)

					AND
						_rct_provider._code = '".$this->getProperty("provider_code")."'

				"; ?>