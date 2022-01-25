<?php

/* application */
class NxCV_StoreCV_evasol extends NxCV_StoreCV
{
	function associateWithVacancy($candidate_oid, $subject) {

		$ctxt = Framework::getContext();
		
		if( ! preg_match_all('/\[([^]]+)\]\s*\[([^]]+)\]/is', $subject, $matches) ) {
//		if( ! preg_match_all('/([a-z][a-z][0-9][0-9]?)([a-z][a-z])/i', $subject, $matches) ) {
			return false;
		}

		$vacancyCode = $matches[1][0];
		$providerCode = $matches[2][0];
		
		$ctxt->setProperty("provider_code",$providerCode);
		$ctxt->setProperty("vacancy_code",$vacancyCode);	
		
		// On recherche l'association dossier/fournisseur
		$relationRecord = $ctxt->getRecord('rct_vacancy_provider.find_relation@recruitment','page.record','db',false,null,null);
		
		// On crée la relation si elle n'existe pas
		if( ! $relationRecord ) {			
			// Récupération de l'oid du dossier
			$vacancyRecord = $ctxt->getRecord('rct_vacancy.find_by_code@recruitment','page.record','db',false,null,null);
			if( ! $vacancyRecord ) {
				return false;
			}
			$ctxt->setProperty("vacancy_oid",$vacancyRecord->oid->db);
			
			// récupération de l'oid du provider
			$providerRecord = $ctxt->getRecord('rct_provider.find_by_code@recruitment','page.record','db',false,null,null);
			if( ! $providerRecord ) {
				return false;
			}
			$ctxt->setProperty("provider_oid",$providerRecord->oid->db);
			// New relation record
			$relationRecord = new PersistentObject('rct_vacancy_provider.cron_add@recruitment','empty');
			$relationRecord->provider_oid = $providerRecord->oid->db;
			$relationRecord->store('rct_vacancy_provider.cron_add@recruitment','insert','db');
			
			
		} else {
			$ctxt->setProperty("vacancy_oid",$relationRecord->vacancy_oid->db);
			$ctxt->setProperty("provider_oid",$relationRecord->provider_oid->db);
		}
				
		// VÈrifie si le candidat n'est pas dÈj‡ associÈ au dossier
		$ctxt->setProperty("candidate_oid",$candidate_oid);

		
		// Tentative de récupération de l'association dossier/candidat
		$candidateVacancyRecord = $ctxt->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);
		// On crée l'association si elle n'existe pas
		if( ! $candidateVacancyRecord ) {
			$candidateVacancyRecord = new PersistentObject('rct_candidate_vacancy.add_assoc@recruitment','empty');	
			$candidateVacancyRecord->store('rct_candidate_vacancy.add_assoc@recruitment','insert','db');
		}
		
		// On met à jour l'association en indiquant la provenance du CV avec l'oid du fournisseur	
		$ctxt->putRecord($null=null,'rct_candidate_vacancy.update_provider@recruitment','update','db','Object',null);

		return true;
	}
}

?>