<?php
/* file automatically generated from NXL source [/home/presencemedia/domains/intranet.presencemedia.ma/public_html/intranet/generis2011/packages/recruitment/nxl/candidates/directory.nxl]. Do not edit it. */
		
$loginPerm='?-rh';
$loginService='user';
define('NX_SKIN_SERVER',(isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"));
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');

		$siteDesc->setProperty('page.strings','recruitment_candidates_directory@recruitment');

		$page = $siteDesc->runLogic('recruitment.candidates.directory_'.'@recruitment', array(
			'page.logic' => 'recruitment.candidates.directory_'.'@recruitment',
			'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
			'page.strings' => 'recruitment_candidates_directory@recruitment',
		));
?>