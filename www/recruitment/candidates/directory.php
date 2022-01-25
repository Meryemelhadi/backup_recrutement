<?php
/* file automatically generated from NXL source [/home/home/webmaster/presencerecrute/recrute.preprod_beta/generis_2012/packages/recruitment/nxl/candidates/directory.nxl]. Do not edit it. */
		
$loginPerm='?-rh|?-drh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../nx/NxSite.inc');


	include_once GENERIS_PACKAGES."workflow/lib/workflow/ExecuteApp.inc";
	$forms = array();
	$datasources = array();
	$views = array();

	/* call the application */
	$page=new ExecuteApp(
		array(
			'app.id' => 'candidates@recruitment',
			'app.defaultOperation' => 'list',
			'app.role' => 'editor',
			'app.forms' => $forms,
			'app.datasources' => $datasources,
			'app.views' => $views,
			'application.dir'=>'application',

			'page.logic' => 'recruitment.candidates.directory_'.'@recruitment',
			// 'nxo'=>'nxo',

			'nx.package' => 'recruitment',
			'page.skin' => (isset($GLOBALS["DIRECTORY_APP_SKIN"])?$GLOBALS["DIRECTORY_APP_SKIN"]:"generis"),
			'page.strings' => 'recruitment_candidates_directory@recruitment',
		),
		$siteDesc);

	$page->run();

			?>