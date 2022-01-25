<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod_beta/generis_2012/packages/recruitment/nxl/vacancies/all.nxl]. Do not edit it. */
		
$loginPerm='?-rh|?-drh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment.dashboards.integrations_synthesis@recruitment');

		$page = $siteDesc->runLogic('recruitment.dashboards.integrations_synthesis_'.'@recruitment', array(
			'page.logic' => 'recruitment.dashboards.integrations_synthesis_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["SALESFORCE_SKIN"])?$GLOBALS["SALESFORCE_SKIN"]:"generis"),
			'page.strings' => 'recruitment.dashboards.integrations_synthesis@recruitment',
		));
?>