<?php

//Permission DRH
	$drh = "";
	if($GLOBALS['_NX_user']->checkPerm('?-drh')) $drh = "-drh";
		
$app_desc = $this->ctxt->getProperty('application.desc');

$icons = array(
	'add'=>'si-add',
	'edit'=>'si-page-white-edit',
    'submit'=>'si-disk',
	'delete'=>'si-delete',
	'save'=>'si-disk',
	'export_excel'=>'si-page-white-excel');


// data sources (optional)
$datasources = array(
    // EDIT
    'record'   => 'rct_candidate.edit@recruitment',       // default record form
	'excel' => 'handler:recruitment.candidates.excel@recruitment',
    'delete_comment' => 'rct_candidate_comment.delete@recruitment'
);

$strings   = $this->ctxt->getProperty('page.strings',$strings);

$forms   = $this->ctxt->getProperty('app.forms',array());

$this->ctxt->setProperty('app.form.css',<<<ECSS
	/* CSS RULES here */
    @import url("/nx/skins/lightsky/css/recruitment/candidate_bs.css");
ECSS
);

$this->ctxt->setProperty('app.form.js',<<<EJS
	/* js code */
	//ajax_require('/nx/skins/default/js/recruitment/form_candidate.js','recruitment');
	
EJS
);

// form definition
include('candidate_form_desc.inc');

$nxo = $this->ctxt->getProperty('nxo','nxo');

$defaultLogic = function($workflow,$user) {
	$ctxt = $workflow->ctxt;
	$logic = $ctxt->getProperty('page.logic');
	return $ctxt->runLogic($logic);
};


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

				'uid' => 'candidates@recruitment',

				// data descriptors
				'data'  => array(
					'search' => 'rct_candidate.search@recruitment',
					'new' => 'rct_candidate.add'.$drh.'@recruitment',
					'excel' => 'handler:recruitment.candidates.excel@recruitment',
                    'record' => 'rct_candidate.edit@recruitment',

					'fields' => array
					(
						'search' => array(
							'hide' => array('age'),
						)
					)
				),

				// default display views
				'views' => array(
					'list' => 'workflow.xlist_search@workflow',
					'new' => 'recruitment.candidates.add@recruitment',
					//'record' => 'workflow.xedit_generic@workflow',
                    'record' => 'workflow.xedit_generic_attachments3@workflow',
					'excel' => 'exports.excel.records'
				),

				'forms' => $forms,

				'icons'=>$icons,

				'list_operations' => array('edit'=>array('nxo'=>'edit'),'delete'=>array('nxo'=>'delete')),

				'operation_init'=>'list',

				// default tasks executed for loading a state
				// 'state_loader'  => 'Workflow_StateLoader',
				'onload'  => array(),

				// tasks executed before executing an action : load submitted form
				'onBeforeAction'  => array(),

				// default tasks executed after executing an action
				// 'onAfterAction'  => array( 'tasks' => array('log')),
			),

			'operations' => array(

				'list' => array(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'load_my_entities@admin2',
						'list_candidates'=>array(
							'data'=>'list','search'=>'search','view'=>'list',
						//	'buttons'=>array('action'=>'?nxo=action','add'=>'?nxo=add')
						)
					),

					'actions'=>array(
						'add' => array('name'=>('add'),'nxo' => 'add','type'=>'link'),
						// 'export_excel' => array('name'=>('export_excel'),'nxo' => 'export_excel')
					)
				),

				'add' => array(
					'title' => ('Create record'),
					'description' => ('Create record'),

					'tasks' => array(
						'load_my_entities@admin2',
						function($workflow, $user){
							if(isset($_REQUEST['from'])) {
								$workflow->ctxt->setProperty('from' , $_REQUEST['from']);
								$workflow->ctxt->setProperty('back_to_home.url' , PORTAL_URL_PREFIX.'/recruitment3/');
								if(isset($_REQUEST['vacancy_oid']) && $_REQUEST['vacancy_oid']){
									$workflow->ctxt->setProperty('back_to_home.url' , PORTAL_URL_PREFIX.'/recruitment3/#/homepage/job/'.$_REQUEST['vacancy_oid'].'/');
								}
								$workflow->ctxt->setProperty('back_to_vacancy.url' , PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=edit&mode=page&oid='.$_REQUEST['vacancy_oid']);
							}else{
								$workflow->ctxt->setProperty('back.url' , PORTAL_URL_PREFIX.'/recruitment/candidates/directory.php');
							}
						},
                        'display_record' => array('media'=>'empty','buttons'=>array('back'=>"?nxo={$app_pre}list" , 'submit'=>"?nxo={$app_pre}add_process"),  'view'=>'new'),
                    ),

					'actions'=>array(
						 'submit' => array('name'=>('submit'), 'nxo' => 'add_process')
					)
				),

				'add_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'load_my_entities@admin2',
						'add_candidate_process',
						/*
						'save_record'=>array('media'=>'post','method'=>'insert'),
						'redirect'=>array('url'=>'?nxo=list&mode=ajax'),
						*/
					)
				),
				
				'export_excel' => array(

                    'tasks' => array(
                        'display_list'=>array(
                            'data'=>'excel','search'=>'search',
                            'view'=>'excel','view_type'=>'XLS', 'file.name'=>'candidates.xls'
                        )
                    )
                ),


				'edit' => array(
					'title' => ('edit record'),
					'description' => ('exec_workflow'),

					'tasks' => array(
						'load_my_entities@admin2',
                        'edit_candidate'
                        //'display_record' => array('media'=>'db','buttons'=>array('back'=>"?nxo={$app_pre}list"))

					),

					'actions'=>array
                    (
						// 'save' => array('name'=>('save'), 'nxo' => 'edit_save','id'  => 'content'),
						'submit' => array('name'=>'submit', 'nxo' => 'edit_process','id'  => 'content')
					)
				),

				'edit_save' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'load_my_entities@admin2',
						$defaultLogic
					),
					'actions'=>array
                    (
						//'back' => array('name'=>('back'), 'nxo' => 'list', 'id'  => 'content'),
						'save' => array('name'=>('save'), 'nxo' => 'edit_save','id'  => 'content'),
						'submit' => array('name'=>('submit'), 'nxo' => 'edit_process','id'  => 'content')
					)
				),

				'edit_process' => array(
					'title' => ('process record'),
					'description' => ('process record'),

					'tasks' => array(
						'load_my_entities@admin2',
						'edit_candidate_process'
					)
				),

				'delete' => array(
					'title' => ('delete record'),
					'description' => ('delete record'),

					'tasks' => array(
						'delete_candidate',
					)
				),
				'delete_cvs' => array(
					'title' => ('delete record'),
					'description' => ('delete record'),

					'tasks' => array(
						'delete_cvs',
					)
				),
				
				'archive_cv' => array(
					'title' => ('archive CV'),
					'description' => ('Archive CV'),

					'tasks' => array(
						'archive_cv',
					)
				),
				
				'archive_cvs' => array(
					'title' => ('archive CV'),
					'description' => ('Archive CV'),

					'tasks' => array(
						'archive_cvs',
					)
				),
				
                'delete_form_vacancies' => array(
                    'title' => ('delete record'),
                    'description' => ('delete record'),

                    'tasks' => array(
                        'delete_candidate',
                    )
                ),

				'upload_cv' => array(
					'title' => ('process record'),
					'description' => ('process cv'),

					'tasks' => array(
						'upload_cv'=>array('mode'=>'auto'),
					)
				),
				
				'get_email_body'=> array(
                    'title' => ('get_email_body'),
                    'description' => ('get_email_body'),

                    'tasks' => array(
                        'get_email_body'
                    )
                ),

				'update_cv' => array(
					'title' => ('process record'),
					'description' => ('process cv'),

					'tasks' => array(
						'upload_cv'=>array('mode'=>'update'),
					)
				),

				'cancel_interview' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview_cancel'
					)
				),

				'delete_interview' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'edit_interview_cancel',
						'delete_interview'
					)
				),

				// send CV to client
				'send_to_client' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'send_to_client_display'
					)
				),
				'send_to_client_process' => array
				(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'send_to_client_process',
						// 'redirect'=>array('url'=>'?nxo=candidates:edit&mode=ajax'),
					)
				),
				'massive_associate_to_recuiter' => array(
					'title' => 'Affect recruiter to many candidate', 
					'description' => ('Affect recruiter to many candidate'),

					'tasks' => array(
						'massive_associate_to_recuiter'
					)
				),
				'massive_associate_to_recuiter_process' => array(
					'title' => 'Affect recruiter to many candidate', 
					'description' => ('Affect recruiter to many candidate'),

					'tasks' => array(
						'massive_associate_to_recuiter_process'
					)
				),
                'add_comment' => array
                (
                    'title' => 'Add comment',
                    'description' => ('Add comment'),

                    'tasks' => array(
                        'add_comment',
                    )
                ),
                'delete_comment' => array
                (
                    'title' => 'Delete comment',
                    'description' => ('Delete comment'),

                    'tasks' => array(
                        'delete_comment',
                    )
                ),
                'add_test' => array
                (
                    'title' => 'Add test',
                    'description' => ('Add test'),

                    'tasks' => array(
                        'add_test',
                    )
                ),
                'add_attached_files' => array
                (
                    'title' => 'Add attached files',
                    'description' => ('Add attached files'),

                    'tasks' => array(
                        'add_attached_files',
                    )
                ),
				'check_candidate_doublon' => array
				(
					'title' => 'Check candidate doublon',
                    'description' => ('Check candidate doublon'),

                    'tasks' => array(
                        'check_candidate_doublon',
                    )
				),
				'associate_to_vacancy'=> array
				(
					'title' => 'Associate candidate to vacancy',
                    'description' => ('Associate candidate to vacancy'),

                    'tasks' => array(
                        'associate_candidate_to_vacancy',
                    )
				),
				'listbs' => array(
					'title' => 'Liste des candidats', // ('List items'),
					'description' => ('List items'),

					'tasks' => array(
						'load_my_entities@admin2',
						'list_candidates_bs'
					)
				),
				
				'massive_associate_to_vacancy' => array(
					'title' => 'Associate to vacancy', // ('List items'),
					'description' => ('Associate to vacancy'),

					'tasks' => array(
						'massive_associate_to_vacancy_display'
					)
				),
				'massive_associate_to_vacancy_process' => array(
					'title' => 'Associate to vacancy', // ('List items'),
					'description' => ('Associate to vacancy'),

					'tasks' => array(
						'massive_associate_to_vacancy_process'
					)
				),
				'massive_associate_to_etat_process' => array(
					'title' => 'Associate to etat', // ('List items'),
					'description' => ('Associate to etat'),

					'tasks' => array(
						'massive_associate_to_etat_process'
					)
				),
				
				'associate_to_etat_process' => array(
					'title' => 'Associate to etat', // ('List items'),
					'description' => ('Associate to etat'),

					'tasks' => array(
						'associate_to_etat_process'
					)
				),
				'massive_relevance_process' => array(
					'title' => 'Massive relevance', // ('List items'),
					'description' => ('Massive relevance'),

					'tasks' => array(
						'massive_relevance_process'
					)
				),
				/*'send_cvs_to_many_client' => array(
					'title' => 'Send cvs to many client', 
					'description' => ('Send cvs to many client'),

					'tasks' => array(
						'send_cvs_to_many_client_display'
					)
				),*/
				'action' => array(
					'title' => 'Action', // ('List items'),
					'description' => ('Action'),

					'tasks' => array(
						'actions_ws'
					)
				),
				'etat_actions' => array(
					'title' => 'Actions état', // ('List items'),
					'description' => ('Actions état'),

					'tasks' => array(
						'etat_actions'
					)
				),
				
				'test' => array(
					'title' => 'Action', // ('List items'),
					'description' => ('Action'),

					'tasks' => array(
						function($workflow, $user){
							$data = json_decode( urldecode($_POST['customer']));
							var_dump($data);
						},
					)
				),
				// default operation
				'default' => array(
					'title' => ('delete record'),
					'description' => ('delete record'),

					'tasks' => array(
						'load_my_entities@admin2',
						$defaultLogic
					)
				)
			)
		)
	)
);

?>