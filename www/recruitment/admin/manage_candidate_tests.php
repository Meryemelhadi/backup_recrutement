<?php
/* file automatically generated from NXL source [d:/webs/access/generis_2011/packages/recruitment/nxl/admin/manage_candidate_tests.nxl]. Do not edit it. */
		
$loginPerm='?-rh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_manage_candidate_tests@recruitment');

		$page = $siteDesc->runLogic('recruitment.admin.manage_candidate_tests_'.'@recruitment', array(
			'page.logic' => 'recruitment.admin.manage_candidate_tests_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_manage_candidate_tests@recruitment',
		));
?>