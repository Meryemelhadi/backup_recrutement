<?php
/* file automatically generated from NXL source [/home/webmaster/presencerecrute/recrute.preprod_beta/generis_2012/packages/recruitment/nxl/vacancies/admin/directory.nxl]. Do not edit it. */
		
$loginPerm='?-rh|?-drh';
$loginService='user';
global $NX_MIME;
$NX_MIME='text/html';
require_once('../../../../nx/NxSite.inc');


if(isset($_REQUEST['nxo']) && ($op = $_REQUEST['nxo']))
	if($op=='candidates')
//		$_REQUEST['nxo']='vacancy_shortlists@recruitment:list_by_state';
		$_REQUEST['nxo']='associated_candidate';

	include_once GENERIS_PACKAGES."workflow/lib/workflow/ExecuteApp.inc";

	$page=new ExecuteApp(
		array(
		'app.role' => 'editor',	
		'app.id' => 'vacancies@recruitment',	
		'nx.package' => 'recruitment',
		'application.dir'=>'application',

		'page.logic' => 'recruitment.vacancies.admin.directory_'.'@recruitment',
		'page.skin' => (isset($GLOBALS["RECRUITMENT_SKIN"])?$GLOBALS["RECRUITMENT_SKIN"]:"generis"),
		'page.strings' => 'recruitment_vacancies_directory_admin@recruitment',
		),
		$siteDesc);

	$page->run();

			?>