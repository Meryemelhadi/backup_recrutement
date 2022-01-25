<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'attached_files.record@recruitment', // state header

	// ADD
	'new'	   => 'attached_files.add@recruitment',    // new record form
	'add_process'   => 'attached_files.record@recruitment',  // save new form

	// EDIT
	'record'   => 'attached_files.record@recruitment',       // default record form
	'edit_process'   => 'attached_files.record@recruitment', // save edited form

	// LIST
	'search'   => 'attached_files.search@recruitment', // search form
	'excel'    => 'attached_files.excel@recruitment',  // excel list export
	'list'	   => 'attached_files.list@recruitment',   // list
);

// strings name
$strings = 'attached_files@recruitment';

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