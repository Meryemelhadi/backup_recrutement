<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'rct_channel.record@recruitment', // state header

	// ADD
	'new'	   => 'rct_channel.add@recruitment',    // new record form
	'add_process'   => 'rct_channel.record@recruitment',  // save new form

	// EDIT
	'record'   => 'rct_channel.record@recruitment',       // default record form
	'edit_process'   => 'rct_channel.record@recruitment', // save edited form

	// LIST
	'search'   => 'rct_channel.search@recruitment', // search form
	'excel'    => 'rct_channel.excel@recruitment',  // excel list export
	'list'	   => 'rct_channel.list@recruitment',   // list
);

// strings name
$strings = 'recruitment_channel@recruitment';

// permissions foir the application
$permissions='default';

// same role as in www .php file
$main_role='editor';

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
	'list' => 'workflow.list_page@workflow',
	'record' => 'workflow.xedit_generic_attachments3@workflow',
	'excel' => 'exports.excel.records',
);

// base application
include GENERIS_PACKAGES.'workflow/application/base_application_crud.inc';
?>