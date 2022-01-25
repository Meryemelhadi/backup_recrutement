<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'dashboard_interviews.record@recruitment', // state header

	// ADD
	'new'	   => 'dashboard_interviews.add@recruitment',    // new record form
	'add_process'   => 'dashboard_interviews.record@recruitment',  // save new form

	// EDIT
	'record'   => 'dashboard_interviews.record@recruitment',       // default record form
	'edit_process'   => 'dashboard_interviews.record@recruitment', // save edited form

	// LIST
	'search'   => 'dashboard_interviews.search@recruitment', // search form
	'excel'    => 'handler:dashboard_interviews.excel@recruitment',  // excel list export
	'list'	   => 'dashboard_interviews.list@recruitment',   // list

	'dashboard'	   => 'handler:dashboard_interviews.dashboard@recruitment',   // dashboard
);

// strings name
$strings = 'dashboard_interviews@recruitment';

// permissions foir the application
$permissions='default';

// same role as in www .php file
$main_role='default';

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
EJS
);

// form definition
$forms = array(
	'record' => array(
		'tabs' => array(
			'Informations' => array(
				'title' => 'Informations', 
				'fields' => array('*')
			),
		)
	)
);

// optional views 
$views = array
(
	'dashboard' => 'dashboard.list@workflow',
	'excel' => 'exports.excel.records',
);

// set property for use by the workflow model
$this->ctxt->setProperty('workflow.views',$views);

// icons
$icons = array(
	'add'=>'si-add',
	'edit'=>'si-page-white-edit',
	'Supprimer'=>'si-delete',
	'delete'=>'si-delete',
	'submit'=>'si-disk',
	'save'=>'si-disk',
	'save_continue'=>'si-disk',
	'export_excel'=>'si-page-white-excel'
);
$this->ctxt->setProperty('workflow.icons', $icons);

// id de la classe dashboard à appeller
$dashboard_task_id = 'dashboard_interviews';

// base application
include GENERIS_PACKAGES.'workflow/application/base_application_dashboard.inc';
?>