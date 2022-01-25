<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod_beta/generis_2012/packages/recruitment/nxl/vacancies/all.nxl]. Do not edit it. */
		
$loginPerm='?-rhmanager';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_vacancies_directory_client@recruitment');

		$page = $siteDesc->runLogic('recruitment.vacancies.client.directory_'.'@recruitment', array(
			'page.logic' => 'recruitment.vacancies.client.directory_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_vacancies_directory_client@recruitment',
		));
?>