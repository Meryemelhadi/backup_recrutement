<?php
// package
$package = 'recruitment';

// prefix for dml views .record, .list, .search.
$base_data = 'recruitment';

$backUrl = '?nxo=edit&oid='.$_GET['coid'].'&candidate_oid='.$_GET['coid'];

// data sources (optional)
$datasources = array(
	// WORKFLOW
	'header'   => 'rct_email_cand.record@recruitment', // state header

	// ADD
	'new'	   => 'rct_email_cand.add@recruitment',    // new record form
	'add_process'   => 'rct_email_cand.add_process@recruitment',  // save new form

	// EDIT
	'record'   => 'rct_email_cand.record@recruitment',       // default record form
	'edit_process'   => 'rct_email_cand.record@recruitment', // save edited form

	'record_by_oid'   => 'rct_email_cand.by_oid@recruitment',       // default record form

	// LIST
	'search'   => 'rct_email_cand.search@recruitment', // search form
	'excel'    => 'rct_email_cand.excel@recruitment',  // excel list export
	'list'	   => 'rct_email_cand.list@recruitment',   // list
);

// strings name
$strings = 'emails@recruitment';

// permissions foir the application
$permissions='default';

// same role as in www .php file
$main_role='editor';

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */

#email_content-control {
	border:solid 1px #ddd;
	border-radius:6px;
	padding:10px;
	min-width: 65%;
}

#email_content-control textarea{
   min-height: 300px;
   min-width: 500px;
}

#email_title-control-wrapper {
	min-width: 65%;
}

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
				'fields' => array('*')
			),
		)
	),
);

// optional views 
$views = array
(
	'list' => 'recruitment.candidates.list_emails',
	// 'list' => 'workflow.list_page@workflow',
	'record' => 'recruitment.candidates.display_email',
	'add' => 'recruitment.candidates.send_email',
	'excel' => 'exports.excel.records',
	'email_view' => 'recruitment.emails.email'
);

// base application
$app_pre = 'emails:';

// extension liste des boutons de la liste
if(!isset($listActions))
	$listActions=array();

// classes des icones à appliquer aux boutons
$icons = array(
	'add'=>'si-add',
	'display'=>'si-page-white',
	'edit'=>'si-page-white-edit',
	'delete'=>'si-delete',
	'submit'=>'si-disk',
	'save'=>'si-disk',
	'send'=>'si-email-go',
	'add_email'=>'si-email-go',
	'save_continue'=>'si-disk',
	'back'=>'si-application-side-contract',
	'back_bs' => 'chevron-left', 
	'close_email' => 'chevron-left',
	'export_excel'=>'si-page-white-excel',
	'send_bs' => 'send');

// $onLoad($workflow,$user,$record,$thisTask,$method)
if(!isset($onLoad))
	$onLoad = null;
	
$onLoadEmail = function($workflow,$user,$record,$task){
	$default_email = $record->default_email->object;

	if(isset($default_email) && $default_email !='?'){
		$e = new PersistentObject('rct_email_sample.by_default_mail@recruitment','db', array('default_mail'=>$default_email));
		if($e->isOk()){
			//$record->docs->object = $e->docs->object;
			$record->email_type->object = $e->type_email->object;
		}
	}
	
};
// $onChange($workflow,$user,$changes,$old_record,$record,$thisTask)
if(!isset($onChange))
	$onChange = null;

// $onSave($workflow,$user,$record,$thisTask,$method)
if(!isset($onSave))
	$onSave = null;

if(!isset($showSearch))
	$showSearch = 'no';
	
$properties=array
(
	// ========================= CRUD APPLICATION ==================
	'application' => array
	(
		// application descriptor for role = magasin
		$main_role => array
		(
			'meta' => array
			(
				'description' => ('Edit items'),
				'strings' => $strings,

				// data descriptors
				'data'  => $datasources,

				// default display views 
				'views' => $views,
				'icons'=>$icons,
				'forms' => $forms,

				// opérations pouvant être appellées depuis la liste, pour chaque entrée
				'list_operations' => array('display'=>array('nxo'=>$app_pre.'display','type'=>'link')),

				// opérations par défaut
				'operation_init'=>$app_pre.'list',

				// default tasks executed for loading a state
				// 'state_loader'  => 'Workflow_StateLoader',
				'onload'  => array(),

				// tasks executed before executing an action : load submitted form
				'onBeforeAction'  => array(),
				
				'permissions' => $permissions
			),
			
			// OPERATIONS DE L'APPLICATION
			'operations' => array(

				'list' => array(
					'title' => 'list records', 
					'description' => ('List items'),

					'tasks' => array(
						'display_list'=>array(
							'data'=>'list','search'=>'search','view'=>'list',
							'showSearch'=>$showSearch,
							'buttons'=>array('search'=>"?nxo={$app_pre}list")
						)
					),

					'actions'=>$listActions+array(
						//'add_email' => array('name'=>('add_email'),'dialog'=> array('nxo' => 'emails:add','target'=>'content-emails')),
						//'add_email' => array('name'=>'add_email','nxo' => 'emails:add','id'=>'content-emails'),
						'add_email' => array('name'=>'add_email','nxo' => 'emails:add','type'=>'link'),
					)
				),

				'export_excel' => array(

					'tasks' => array(
						'display_list'=>array(
							'data'=>'excel','search'=>'search',
							'view'=>'excel','view_type'=>'XLS',
						)
					)
				),


				'add' => array(
					'title' => ('create record'),
					'description' => ('Create record'),

					'tasks' => array(
						'display_record' => array('media'=>'empty','view'=>'add',
							'buttons'=>array('back'=>$backUrl.'&mode=page'))
					),

					'actions'=>array(
                          // back to main application
						//'back' => array('name'=>('back'),'nxo'=>$app_pre.'list', 'id'=>'content-emails','close_dialog'=>true),				
						//'send' => array('name'=>('send'), 'nxo' => $app_pre.'add_process','id'=>'content-emails','close_dialog'=>true)
						'back_bs' => array('name'=>('back'),'url'=>$backUrl, 'type'=>'link','close_dialog'=>true),				
						'send_bs' => array('name'=>('send'), 'nxo' => $app_pre.'add_process&src='.$_REQUEST['src'],'type'=>'submit','close_dialog'=>true)
					)					

				),
			
				'add_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'save_record'=>array('media'=>'post','method'=>'insert', 'record_property'=>'page.record',
						'onLoad' => $onLoadEmail, 'onChange' => $onChange,
						'onSave' => function($workflow,$user,$record,$task,$method) { $workflow->record = $record; }),						
						'send_email',
						//'redirect'=>array('url'=>'?nxo=emails:list&mode=ajax'),
						//'redirect'=>array('url'=>'?nxo=emails:list&mode=page'),
						'redirect'=>array('url'=>$backUrl.'&mode=page&src='.$_REQUEST['src']),
					)
				),

				'display' => array(
					'title' => ('Email'),
					'description' => ('exec_workflow'),

					'data'=>array('fields'=>array('no_edit'=>'*')),

					'tasks' => array(
						'display_record' => array(
							'media'=>'db','buttons'=>array('back'=>$backUrl.'&mode=page'),
							'view'=>'record'
						)
					),

					'actions'=>array
                    (
						//'back' => array('name'=>('back'),'nxo'=>$app_pre.'list', 'id'=>'content-emails'),
						'close_email' => array('name'=>('close_email'),'nxo'=>'emails:emails_sent_to_candidate&oid'.$_REQUEST['oid'], 'type'=>'ajax', 'id' => 'content-emails'),
					)				
				),

				'emails_sent_to_candidate' => array(
					'title' => ('Email'),
					'description' => ('exec_workflow'),

					'tasks' => array(
						function($workflow, $user){
							$workflow->ctxt->runView('recruitment.candidates.components.panel_emails_list',array('fmethod' => 'toHTML',),null);
						}
					),

					'actions'=>array
                    (
						//'back' => array('name'=>('back'),'nxo'=>$app_pre.'list', 'id'=>'content-emails'),
						'close_email' => array('name'=>('close_email'),'url'=>$backUrl.'&mode=page', 'type'=>'link'),
					)			
				),
				'get_email_sample' => array(
					'title' => ('Email'),
					'description' => ('exec_workflow'),

					'data'=>array('fields'=>array('no_edit'=>'*')),

					'tasks' => array
					(
						'email_sample',
					),

					'actions'=>array
                    (
						'back' => array('name'=>('back'),'nxo'=>$app_pre.'list', 'id'=>'content-emails'),
					)				
				),

				'edit_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'save_record'=>array('media'=>'post','method'=>'update',
							'onLoad' => $onLoad, 'onChange' => $onChange,'onSave' => $onSave),
						'redirect'=>array('url'=>$backUrl.'&mode=page'),
					)
				),

				'delete' => array(
					'title' => ('delete record'),
					'description' => ('delete record'),

					'tasks' => array(
						'delete_record',
						'redirect'=>array('url'=>$backUrl.'&mode=page'),
					)
				)
			)
		)
	)
);
?>