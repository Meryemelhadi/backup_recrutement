<?php
/* file automatically generated from NXL source [d:/webs/access/generis_2011/packages/recruitment/nxl/admin/manage_diplomas.nxl]. Do not edit it. */
		
$loginPerm='?-rh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_manage_diplomas@recruitment');

		$page = $siteDesc->runLogic('recruitment.admin.manage_diplomas_'.'@recruitment', array(
			'page.logic' => 'recruitment.admin.manage_diplomas_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_manage_diplomas@recruitment',
		));
?>