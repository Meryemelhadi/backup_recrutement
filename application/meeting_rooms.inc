<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'meeting_rooms.record@recruitment', // state header

	// ADD
	'new'	   => 'meeting_rooms.add@recruitment',    // new record form
	'add_process'   => 'meeting_rooms.record@recruitment',  // save new form

	// EDIT
	'record'   => 'meeting_rooms.record@recruitment',       // default record form
	'edit_process'   => 'meeting_rooms.record@recruitment', // save edited form

	// LIST
	'search'   => 'meeting_rooms.search@recruitment', // search form
	'excel'    => 'meeting_rooms.excel@recruitment',  // excel list export
	'list'	   => 'meeting_rooms.list@recruitment',   // list
);

// strings name
$strings = 'meeting_rooms@recruitment';

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