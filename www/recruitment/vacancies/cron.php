<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod_beta/generis_2012/packages/recruitment/nxl/vacancies/all.nxl]. Do not edit it. */
		
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_vacancies_cron@recruitment');

		$page = $siteDesc->runLogic('recruitment.vacancies.cron_'.'@recruitment', array(
			'page.logic' => 'recruitment.vacancies.cron_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["SALESFORCE_SKIN"])?$GLOBALS["SALESFORCE_SKIN"]:"generis"),
			'page.strings' => 'recruitment_vacancies_cron@recruitment',
		));
?>