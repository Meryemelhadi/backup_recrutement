<?php $properties["query"]="
					SELECT distinct _rct_vacancy._oid , _rct_vacancy._name,
						_rct_vacancy._code FROM _rct_vacancy 
						LEFT JOIN _rct_vacancy_total_control AS T_CTRL ON T_CTRL._key = _rct_vacancy._oid 
						LEFT JOIN _rct_vacancy_readonly		 AS R_CTRL ON R_CTRL._key = _rct_vacancy._oid
						where _rct_vacancy._current_step = 0 AND (
							_rct_vacancy._creator='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							T_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							R_CTRL._val='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							_rct_vacancy._manager_oid='".$GLOBALS["_NX_user"]->getProperty("user.oid","",true)."' OR 
							_rct_vacancy._creator in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							T_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							R_CTRL._val in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') OR 
							_rct_vacancy._manager_oid in (select _oid from _user where `_interim` = '".$GLOBALS["_NX_user"]->getProperty("oid","")."') )
				"; ?>