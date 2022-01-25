<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod8/generis_2012/packages/recruitment/nxl/candidates/directory_client.nxl]. Do not edit it. */
		
$loginPerm='?-rhmanager';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_candidates_directory_client@recruitment');

		$page = $siteDesc->runLogic('recruitment.candidates.directory_client_'.'@recruitment', array(
			'page.logic' => 'recruitment.candidates.directory_client_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_candidates_directory_client@recruitment',
		));
?>