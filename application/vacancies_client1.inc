<?php

$app_desc = $this->ctxt->getProperty('application.desc');


$icons = array(
	'add'=>'si-add',
	'add_interview'=>'si-add',
	'edit'=>'si-page-white-edit',
	'delete'=>'si-delete',
	'save'=>'si-disk',
	'export_excel'=>'si-page-white-excel',
	'xls_export'=>'si-page-white-excel');

//$strings   = $this->ctxt->getProperty('page.strings',$strings);
$strings = 'recruitment_vacancies_directory_admin@recruitment';
$datasources   = array(
	'vacancies_ws'=>'handler:rct_vacancy.pub_web_site@recruitment',
	'vacancies_app_ws'=>'rct_vacancy.pub_app@recruitment',
	'vacancies_app_compagnie'=>'rct_vacancy.pub_app_compagnie@recruitment',
	'list_interviews' => 'rct_interview.ds_calendar_list_realised@recruitment',
	'excel_short_list' => 'recruitment.short_lists.candidates.excel@recruitment',
	'excel' => 'rct_vacancy.search',
	'search' => 'rct_vacancy.search@recruitment'
);

// $this->ctxt->getProperty('app.datasources');
$forms   = $this->ctxt->getProperty('app.forms',array());
$nxo = $this->ctxt->getProperty('nxo','nxo');

$defaultLogic = function($workflow,$user) {

	$ctxt = $workflow->ctxt;
	$logic = $ctxt->getProperty('page.logic');
	return $ctxt->runLogic($logic);
};

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
	@import url("/nx/skins/default/css/recruitment/helptip.css");
	.marge_green{
	    border-left-style:solid;
	    border-left-width:20px;
		border-left-color: rgba(0,128,0,0.31);
	}
	.marge_orange{
        border-left-style:solid;
	    border-left-width:20px;
		border-left-color: rgba(255,165,0,0.36);
	}
	.marge_gray{
	    border-left-style:solid;
	    border-left-width:20px;
		border-left-color: rgba(128,128,128,0.34);
	}

ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
	ajax_require('/nx/skins/default/js/recruitment/form_vacancy.js','recruitment');

EJS
);

$properties=array
(
	// ========================= CRUD APPLICATION ==================
	
	'application' => array
	(
		'editor' => array
		(
			'meta' => array
			(
				'name' => ('List title'),
				'description' => ('Edit items'),
				'strings' => $strings,

				// data descriptors
				'data'  => $datasources,
			
				// default display views 
				'views' => array(
					'list' => 'workflow.list_page@workflow',
					'record' => 'workflow.xedit_generic@workflow',
					'list_interviews' => 'recruitment.vacancies.components.list_interviews@recruitment',
					'list_interviews_vacancy' => 'recruitment.vacancies.components.list_interviews_vacancy@recruitment',
					'excel' => 'exports.excel.records'

				),

				'forms' => $forms,

				'icons'=>$icons,

				'list_operations' => array('edit'=>array('nxo'=>'edit'),'delete'=>array('nxo'=>'delete')),

				

				// default tasks executed for loading a state
				// 'state_loader'  => 'Workflow_StateLoader',
				'onload'  => array(),

				// tasks executed before executing an action : load submitted form
				'onBeforeAction'  => array(),

				// default tasks executed after executing an action
				// 'onAfterAction'  => array( 'tasks' => array('log')),
			),
			
			'operations' => array
			(
				'list' => array(
					'title'=>'',
					'tasks' => array(
						'vacancies_client_list'
					)
				),
			)
		)
	)
);

?>