<?php
/* file automatically generated from NXL source [D:/webs/access/generis_2012/packages/recruitment/nxl/admin/manage_schools.nxl]. Do not edit it. */
		
$loginPerm='?-rh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_manage_schools@recruitment');

		$page = $siteDesc->runLogic('recruitment.admin.manage_schools_'.'@recruitment', array(
			'page.logic' => 'recruitment.admin.manage_schools_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_manage_schools@recruitment',
		));
?>