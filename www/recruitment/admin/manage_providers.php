<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod_beta/generis_2012/packages/recruitment/nxl/admin/manage_providers.nxl]. Do not edit it. */
		
$loginPerm='?-rh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_manage_providers@recruitment');

		$page = $siteDesc->runLogic('recruitment.admin.manage_providers_'.'@recruitment', array(
			'page.logic' => 'recruitment.admin.manage_providers_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_manage_providers@recruitment',
		));
?>