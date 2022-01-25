<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'rct_profiling_rules.record@recruitment', // state header

	// ADD
	'new'	   => 'rct_profiling_rules.add@recruitment',    // new record form
	'add_process'   => 'rct_profiling_rules.record@recruitment',  // save new form

	// EDIT
	'record'   => 'rct_profiling_rules.record@recruitment',       // default record form
	'edit_process'   => 'rct_profiling_rules.record@recruitment', // save edited form

	// LIST
	'search'   => 'rct_profiling_rules.search@recruitment', // search form
	'excel'    => 'rct_profiling_rules.excel@recruitment',  // excel list export
	'list'	   => 'rct_profiling_rules.list@recruitment',   // list
);

// strings name
$strings = 'profiling_rules@recruitment';

// permissions foir the application
$permissions='default';

// same role as in www .php file
$main_role='editor';

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* activate javascript on form */
	window.onloadForm1 = function() 
	{
		window.formObj = new window.Generis.Recruitment.Profiling_rules(window.form1_handler);
	};


	if(typeof window.Generis.Recruitment.Profiling_rules == "undefined")
	{
		window.ajax_load('/nx/skins/default/js/recruitment/profiling_rules.js','profiling_rules_js');
		window.ajax_onload(window.onloadForm1,'profiling_rules_js');
	}
	else
		window.onloadForm1();

EJS
);

// form definition
$forms = array(
	'record' => array(
		'tabs' => array(
			'Informations' => array(
				'title' => 'Informations', 
				'columns'=>array
				(
					array
					(
						'groups'=>array
						(
							array
							(
								'title' => 'Régle', 
								'fields' => array('name','index')
							),
							array
							(
								'title' => 'Type règle : ', 
								'fields' => array('profiling_on','form_field')
							),
							array
							(
								'title' => 'Valeurs recherchées : ', 
								'fields' => array('keywords','not_keywords')
							)
						)
					),
					array
					(
						'groups'=>array
						(
							array
							(
								'title' => 'Application sur : ', 
								'fields' => array('vacancy','cand_channel','category_oid','profile','provider','establishment')
							)
						)
					),
				)
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