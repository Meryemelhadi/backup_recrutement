<?php $properties["query"]="
				SELECT * FROM _rct_actions_candidate_etat
				where _etat_candidate like '%|".$_REQUEST['etat_oid']."|%' and _actif = 1
			"; ?>