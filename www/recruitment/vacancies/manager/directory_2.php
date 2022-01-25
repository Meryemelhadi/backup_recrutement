<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod7/generis_2012/packages/recruitment/nxl/vacancies/manager/directory.nxl]. Do not edit it. */
		
$loginPerm='?-rhmanager';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../../nx/NxSite.inc');



	include_once GENERIS_PACKAGES."workflow/lib/workflow/ExecuteApp.inc";

	$page=new ExecuteApp(
		array(
		'app.role' => 'editor',	
		'app.id' => 'vacancies@recruitment',	
		'nx.package' => 'recruitment',
		'application.dir'=>'application',

		'page.logic' => 'recruitment.vacancies.manager.directory_'.'@recruitment',
		'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
		'page.strings' => 'recruitment_vacancies_directory_admin@recruitment',
		),
		$siteDesc);

	$page->run();

			?>