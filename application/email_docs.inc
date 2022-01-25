<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'email_docs.record@recruitment', // state header

	// ADD
	'new'	   => 'email_docs.add@recruitment',    // new record form
	'add_process'   => 'email_docs.record@recruitment',  // save new form

	// EDIT
	'record'   => 'email_docs.record@recruitment',       // default record form
	'edit_process'   => 'email_docs.record@recruitment', // save edited form

	// LIST
	'search'   => 'email_docs.search@recruitment', // search form
	'excel'    => 'email_docs.excel@recruitment',  // excel list export
	'list'	   => 'email_docs.list@recruitment',   // list
);

// strings name
$strings = 'email_docs@recruitment';

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