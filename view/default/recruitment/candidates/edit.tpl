
			<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
				
		
		<?php ob_start(); ?>

			<?php 
		$workflow = $this->getProperty('workflow');
		$candidate = $this->getProperty('page.record');
		?>
		{require:css/recruitment/candidate.css:skin}
	
<script type="text/javascript" language="Javascript">
		if (window.container)
			window.container.setAppTitle("");
		</script>
<div class="pm-page-title-wrapper">
	<div class="pm-page-title-inner-wrapper">
		<div id="page_title" class="pm-title">
			<div class="title_tb" style="float:right"></div></div></div></div><style>
            {=app.form.css}

        </style>
		<script type="text/javascript" language="Javascript">
            {=app.form.js}
        </script><?php 

	echo $this->getProperty('log.warn',$_SESSION['log.warn']);
	echo $this->getProperty('log.errors',$_SESSION['log.errors']);
	echo $this->getProperty('log.ok',$_SESSION['log.ok']);

	if(defined('KEEP_SESSION') && KEEP_SESSION==false)
		session_start();

	if(isset($_SESSION['log.warn']))
		unset($_SESSION['log.warn']);

	if(isset($_SESSION['log.errors']))
		unset($_SESSION['log.errors']);

	if(isset($_SESSION['log.ok']))
		unset($_SESSION['log.ok']);

?><?php 
$msgHelp = $this->getProperty('msg.help');
if($msgHelp)
{
?><div id="help" class="help"><div class="message">{var:msgHelp}</div></div>
		<script type="text/javascript" language="Javascript">
	var helpDiv=document.getElementById('help');
	var helpText = (helpDiv.innerText||helpDiv.textContent);
	if(!helpText)
		helpDiv.style.display = 'none';
</script><?php 
}?>


        <?php $_nx_content_stack[]="panel_files";	ob_start(); ?>
            <div class="comments-wrapper" id="files_wrapper">
{records:attached_files.records}
<table class="files_wrapper">
	{record}
	<tr class="files_wrapper_{field:oid}"><td class="files_wrapper_{field:oid}" id="file_wrapper_{field.object:oid}">{field.html:file}</td><td class="" style="width:2%,align:right"><input type="button" class="s-icon si-cross" href="javascript:void(0);" onclick="Generis.Recruitment.deleteFile('{field.object:oid}', '{=delete_attached_file.url}', 'file'); this.blur(); return false;" value="" style="cursor: pointer; background-color:transparent; border:solid 0px"/></td></tr>
	{/record}
</table>
{/records}

{no_record}
    <div class="tab_empty">
        <?php
            echo __('empty_list_file');
        ?>
    </div>
    {/no_record}
</div>
		<div class="add-comment-wrapper">
			<div class="add-comment-process clear-both">
				<script type="text/javascript" language="Javascript">
		window.upload_fileConfig = { 
			exec:function() { PMModalbox.display(window.upload_fileConfig, null); },
			content_id : 'upload_file',
			title : "{string:'upload_file'}", 
			message : "{string:'upload_file_header'}", 
			viewMode : "cancel", 
			target : "files_wrapper", 
			labels : { cancel : "{string:'dlg_cancel'}" }
		};
	</script>
				<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="window.upload_fileConfig.exec(); this.blur(); return false;">
					<span class="btn-bg">
						<span class="s-icon si-page-white-add">{string:"add_file"}</span></span></a></div></div>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="interviews";	ob_start(); ?>
            
		<div class="pm-bxm-box-content">
	{records:candidate_interviews.records}
	
			<div class="table-list-wrapper">
				<table class="table-list">
			{record}
			
					<tr class="{if:record.is_last}last{/if}">
						<td class="entry">{field:date} {string:"at"} {field:time_start}  {if:#field.object:vacancy_oid# != ''}(Dossier: 
							<a href="/recruitment/vacancies/admin/directory.php?nxo=edit&mode=page&oid={field.object:vacancy_oid}">{field:vacancy_oid}</a>){/if}</td>
						<td class="entry">
					{if:#field.html:interview_etat# != ''}Etat: <strong>{field.html:interview_etat}</strong> {/if}&nbsp;
					{if:#field.object:interview_by_oid# != ''}{string:"with"}: <strong>{field.html:interview_by_oid}</strong>{/if}
				</td>
						<td class="action plus-action">
							<a href="javascript:void(0);" onclick="ajax_navigate(event,'{=edit_interview.url}&mode=ajax{record.url_key}','content'); return false;">
								<span>{string:"more_details"}</span></a></td>
					</tr>
			{/record}
		
				</table></div>
	{/records}
    {no_record}
    
			<div class="tab_empty">
        <?php
            echo __('empty_list_interview');
        ?>
    </div>
    {/no_record}
</div>
		<div class="pm-button-wrapper clear-both">
			<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="ajax_navigate(event,'{=add_interview.url}','content'); this.blur(); return false;" style="float:right">
				<span class="btn-bg">
					<span class="s-icon si-calendar">{string:"schedule_an_interview"}</span></span></a></div>

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="tests";	ob_start(); ?>
        
		<fieldset class="test_fieldset">
			<div class="table-list-wrapper" id="test_oid-list-wrapper">
    {records:candidate_tests.records}
        {record}
            
				<table class="table-list" style="width:100%">
					<tr class="test_{field.object:test_oid}">
						<td class="entry_{field.object:test_oid}" id="entry_{field.object:test_oid}" style="width:49%"><strong>Test:</strong> {field.html:test_oid}</td>
						<td class="entry_prct_{field.object:test_oid}" id="entry_prct_{field.object:test_oid}" style="width:49%"><strong>Pourcentage:</strong> {field.html:pourcentage}%</td>
						<td class="" style="width:2%,align:right">
<input type="button" class="s-icon si-cross" href="javascript:void(0);" onclick="Generis.Recruitment.deleteTest('{field.object:test_oid}', '{=delete_test.url}', 'test'); this.blur(); return false;" value="" style="cursor: pointer; background-color:transparent; border:solid 0px;width:15px"/></td>
					</tr>
					<tr class="test_{field.object:test_oid}_comment">
						<td><strong>{field.label:comment}:</strong></td>
						<td colspan="2">{field.html:comment}</td>
					</tr>
				</table>
        {/record}
    {/records}
    </div>
<br/>
    {record:candidate_tests.record}
    
			<div class="add_test">
				<div class="pm-bx-form pm-bx-form-normal-layout">
					<div class="record_wrapper">
						<div class="record" id="control_test">
							<div class="control-main-wrapper">
								<table class="table-list">
									<tr>
										<td class="entry" stylex="width:50%">
											<div class="control-label-wrapper">
												<div class="control-label">{field.label:test_oid}:</div></div>
											<div class="control-wrapper">
												<div class="control" id="available-tests-control">
                                            {field.form:test_oid}
                                        </div>
												<div class="control control-inline" id="available-pourcent-control">
                                            {field.form:pourcentage}
													<span class="control-label-wrapper-inline">{field.label:pourcentage}</span></div></div></td>
									</tr>
									<tr>
										<td class="entry">
											<div class="control-label-wrapper">
												<div class="control-label">{field.label:comment}:</div></div>
											<div class="control-wrapper">
												<div class="control">
                                            {field.form:comment}
                                        </div></div></td>
									</tr>
								</table></div></div></div></div></div>
    {/record}

    
			<div class="pm-button-wrapper clear-both">
				<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.addTest('control_test','test_oid' ,'pourcentage', 'comment', 'add_test', '{=add_test.url}', 'test_oid'); this.blur(); return false;" style="float:right">
					<span class="btn-bg">
						<span class="s-icon si-add">{string:"add_test"}</span></span></a>
				<div id="test-button-loader" style="display:none;"></div></div>
		</fieldset>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="update_resume";	ob_start(); ?>
        
		<div id="update_resume" style="display:none">
			<div class="ged_miniform ged_add_files">
<br/>
<br/>
				<form id="" method="post" action="?nxo=candidates:update_cv" enctype="multipart/form-data">
<input type="hidden" value="100000000" name="MAX_FILE_SIZE"/>
<input type="hidden" value="POST" name="_form_method_"/>
<input type="file" name="temp_cv_file" id="temp_cv_file" value="" style="width:100%; margin: -1px 0 0;"/>
<br/>
<br/>
					<button type="submit">{string:'update resume'}
					</button>
				</form>
<br/>
<br/></div></div>

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="comments_part";	ob_start(); ?>
        
		<div class="comments-wrapper" id="comments-wrapper">
    {records:comments.records}
    {record}
    
			<div class="comment-wrapper_{field:oid}">
				<table style="width:100%">
					<tr>
						<td style="width:98%">
							<div class="comment">
								<span class="comment_author">{field:user_oid}</span>: {field:comment}</div></td>
						<td style="width:2%,align:right">
                    {if:#user:oid# == #field.object:user_oid#}
                    
<input type="button" class="s-icon si-cross" href="javascript:void(0);" onclick="Generis.Recruitment.deleteComment('{field:oid}','{=delete_comment.url}'); this.blur(); return false;" value="" style="cursor: pointer; background-color:transparent; border:solid 0px"/>
                    {/if}
                </td>
					</tr>
					<tr>
						<td>
							<div class="comment_date">{field:date}</div></td>
					</tr>
				</table></div>
    {/record}
    {/records}
</div>
		<div class="add-comment-wrapper">
			<div class="add-comment">
				<div class="add-comment-inner">
<textarea rows="3" cols="30" name="add_comment_zone" type="text" class="text"></textarea></div></div>
			<div class="add-comment-process clear-both">
				<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.addComment(this, 'add_comment_zone', '{=add_comment.url}'); this.blur(); return false;">
					<span class="btn-bg">
						<span class="s-icon si-comment-add">{string:"post_comment"}</span></span></a>
				<div style="display: none;" id="vacancy-button-loader"></div></div></div>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="emails";	ob_start(); ?>
        <?php 
		$emails = new PersistentCollection('rct_email_cand.list','db',array('candidate_oid',$_REQUEST['oid']));
		if($emails->isOk())
			$this->setProperty('page.records',$emails->records);

		$actions = array(
			'add_email' => array('name'=>('add_email'),'iconCls'=>'si-email-go','dialog'=> array('nxo' => 'emails:add','target'=>'content-emails')),
			// 'add_sms'=>array('nxo'=>'emails:add','iconCls'=>'si-add','id'=>'content-emails')
		);
		$listOperations = array(
			'edit'=>array('nxo'=>'emails:display','iconCls'=>'si-page-white','id'=>'content-emails'),
			//'delete'=>array('nxo'=>'emails:delete','iconCls'=>'si-delete','confirm'=>true)
		);
		$tabId='emails';
		$opPar='nxo';
		$this->setProperty('nxo','nxo');
		$title = "Emails envoyés au candidat";
	?><style>
.tab_empty {
	font-size: 12px;
	/* background-color: #eee; */
	line-height: 20px;
	border: solid 1px #eee;
	padding: 10px;
	border-left: solid 3px #eee;
}
</style><div class="pm-bxm-box-wrapper pm-bxm-box-last"><div class="pm-bxm-box"><div class="box-title-wrapper box-title-orange"><div class="box-title"><h3>{var:title}</h3></div></div><div class="pm-bxm-box-content" id="content-emails"><div class="pm-grid-outer-wrapper"><div class="generis-toolbar-wrapper"><div class="generis-toolbar"><?php 

if(!isset($actions))
	$actions=$workflow->getActions();

$opPar = $this->getProperty('nxo','nxo');
if(!isset($zone))
	$zone='';

foreach($actions as $actionId=>$action)
{
	if(isset($op['zone']) && $op['zone']!=$zone)
		continue;

	if(isset($op['name']))
		$title = __($action['name']);
	else
		$title = __($actionId);

	$iconCls = $action['iconCls'];

	// link type
	if(isset($action['type']))
		$type = $action['type'];
	else
		$type = 'ajax';

	$target='';$id='';
	if(isset($action['target']))
	{
		$type = 'link';
		$target = $action['target'];
	}
	else
		$target='';

	$url='';

/*	if(isset($action['url']))
	{
		$url=$action['url'];
		if(!preg_match('/\?/',$url))
			$url.='?';
	}
	else
		$url='?';
*/
/*	if(isset($action['url']))
		$targetDef = $action['url'];
	else
		$targetDef = $action;
*/

	if(isset($action['dirkey-request']))
	{
		$fkey = $action['dirkey-request'];
		if(isset($_REQUEST[$fkey]))
		{
			$url=$action['dirkey-request'].'-'.$_REQUEST[$fkey].'/'.$url;
		}
	}

	if(isset($action['dirkey-from']))
	{
		$url='from-'.$action['dirkey-from'].'/'.$url;
	}

	if(isset($action['url']))
		$url.=$action['url'];
	elseif($url)
		$url.=basename($_SERVER['PHP_SELF']);

	if(!preg_match('/\?/',$url))
		$url.='?';

	if(isset($action[$opPar]))
		$url.=$opPar.'='.$action[$opPar];
	elseif(!isset($action['url']))
		$url.=$opPar.'='.$actionId;

	if(isset($action['action']))
		$url.='&amp;action='.$action['action'];

	if(isset($action['filterKey']))
		$url .= $this->getProperty('filterKey','');

	if(isset($action['mkey']) && $action['mkey'])
	{
		require_once(NX_LIB."login/NxLogin_key.inc");
		global $_NX_site;
		$login=new NxLogin_key($_NX_site);
		$url.='&amp;'.$login->getCurrentParamKey(true);
	}

	$dialog = isset($action['dialog']['nxo']) || (isset($action['dialog']['ds']) || isset($action['dialog']['url'])) ? $action['dialog'] : null;
	if($dialog)
	{
		//		$urlDialog = $action['dialog']['url'];

		// get URL for loading the dialog
		if(!isset($action['dialog']['nxo']))
			$action['dialog']['nxo']='load_action_form';

		$urlDialog = '?nxo='.$action['dialog']['nxo'];
		
		// ID of the descriptor that will be used by the dialog
		$dialogID = 'action_'.$index.'_Config';

		// url of action to be called by current form
		$actionIdUrl = urlencode($actionId);

		// store current state (used to check that the action is not triggered twice)
		$stateUrl=urlencode($state);

?>
								<script type="text/javascript" language="Javascript">
			window.{$dialogID} = 
			{ 
				exec:function() 
				{
					// check data and open dialog with dates
					// if(window.form1.onsubmit(window.form1,'{$actionId}'))
						PMModalbox.loadFromUrl(window.{$dialogID}, null);
				},

				// dialog params : used by MB for opening the dialog
				title : "{$title}",
				url: '{var:urlDialog}&dialogId={$actionIdUrl}&submitDesc={$dialogID}&mode=ajax',			
				message : "{string:'enter parameters'}", 
				viewMode : "cancel", 
				target : "content", 
				width : 600,
				height:500,
				labels : { cancel : "{string:'dlg_cancel'}" },

				// this form params : used by the dialogue for submitting the form if user clicks on ok in dialog
				//form:window.form1,
				actionUrl:'{var:url}',
				submit:function()
				{
					// called from dialog
					if(window.form1.onsubmit(window.form1,'{$actionId}'))
					{
						window.form1.action='{var:url}';
						window.form1.submit();
					}
				}
			};
		</script>
								<a href="javascript:window.{$dialogID}.exec();" class="s-icon {var:iconCls}">
									<span class="btn-bg">
										<span>{var:title}</span></span></a><?php 
	}
	elseif (isset($action['id']))
	{
		$id = $action['id'];
?><a class="s-icon {var:iconCls}" href="{var:url}&mode=ajax" onclick="ajax_navigate(event,'{var:url}&mode=ajax','{var:id}'); return false;"><span>{var:title}</span></a><?php 
	}
	elseif($target)
	{
?><a class="s-icon {var:iconCls}" href="{var:url}" target="{var:target}"><span>{var:title}</span></a><?php 
	}
	else
	{
?><a class="s-icon {var:iconCls}" href="{var:url}"><span>{var:title}</span></a><?php 
	}
}
?></div></div>

				{records:page.records}
				{if:records.count>0}
					<div class="pm-grid-wrapper"><table id="table-{var:tabId}" class="pm-grid">
						{record}
							<?php $_nx_content_stack[]="operations_st";	ob_start(); ?>
								<?php 

if(!isset($GLOBALS['_OP_ID_']))
	$GLOBALS['_OP_ID_']=1;

if(!isset($opPar))
	$opPar='nxo';

if(!isset($listOperations))
{
	if(isset($_nx_record->object))
		$listOperations=$_nx_record->object->getListOperations();
	else
	{
		if(!isset($listOperations))
			$listOperations=$this->getProperty('list_operations');

		if(!$listOperations && $workflow)
			$listOperations=$workflow->getListOperations();
	}
}

$edit_url=null;
$type_url=null;

$legend=array();
if(!isset($zone))
	$zone='';

if($listOperations) foreach($listOperations as $opID=>$op)
{
	$opIDX=$GLOBALS['_OP_ID_']++;

	if(isset($op['zone']) && $op['zone']!=$zone)
		continue;

	if(isset($op['name']))
		$title = __($op['name']);
	else
		$title = __($opID);
		
	$iconCls = $op['iconCls'];

	// link type
	if(isset($op['type']))
		$type = $op['type'];
	else
		$type = 'ajax';

	$target='';$id='content';
	if(isset($op['target']))
	{
		$type = 'link';
		$target = $op['target'];
	}

	if(isset($op['id']))
	{
		$type = 'ajax';
		$id=$op['id'];
	}
	$url='';
	if(isset($op['dirkey']))
	{
		$fkey = isset($op['field-key'])?$op['field-key']:'oid';
		$url=$op['dirkey'].'-'.$_nx_record->$fkey->object.'/';
	}

	if(isset($op['dirkey-request']))
	{
		$fkey = $op['dirkey-request'];
		if(isset($_REQUEST[$fkey]))
		{
			$url.=$op['dirkey-request'].'-'.urlencode($_REQUEST[$fkey]).'/';
		}
	}

	if(isset($op['url']))
		$url.=$op['url'];
	elseif($url)
		$url.=basename($_SERVER['PHP_SELF']);

	if(!preg_match('/\?/',$url))
		$url.='?';

	if(isset($op[$opPar]))
		$url.=$opPar.'='.$op[$opPar];
	else
		$url.=$opPar.'='.$opID;

	if(isset($op['action']))
		$url.='&amp;action='.$op['action'];

	if(isset($action['filterKey']))
		$url .= '&amp;filterKey='.urlencode($this->getProperty('filterKey',''));

	$legend[$title] = $iconCls;

	$url.=$_nx_record->getUrlKey();

	if(isset($op['mkey']) && $op['mkey'])
	{
		if(!isset($mkey))
		{
			require_once(NX_LIB.'login/NxLogin_key.inc');
			global $_NX_site;
			$login=new NxLogin_key($_NX_site);
			$mkey='&amp;'.$login->getCurrentParamKey(true);
		}
		$url .= $mkey;
	}

	// if not mode key as directory => pass key as params
	/*if(!isset($op['dirkey'])) 
	{
		$url.=$_nx_record->getUrlKey();
	}*/

	if(!$edit_url)
		$edit_url=$url;

	if(!$defaultAction)
	{		
		if($type=='link')
			$defaultAction = "function(event,url){document.location=url;}";
		else
			$defaultAction = "function (event,url){ajax_navigate(event,url,'content');}";
	}
	
	if($type == 'link')
	{
		if($target)
		{
?><a href="javascript:void(0);" class="s-icon {$iconCls}" onclick="window.open('{var:url}','{var:target}');return false;" title="{$title}" target="{var:target}"><span class="x-hidden">{$title}</span></a><?php 
		}
		else
		{
?><a href="{var:url}&mode=page" class="s-icon {$iconCls}" onclick="document.location='{var:url}'; window.event.cancelBubble = true;if(event.stopPropagation) event.stopPropagation();return false;" title="{$title}"><span class="x-hidden">{$title}</span></a><?php 
		}
	}
	elseif(isset($op['confirm']) && $op['confirm'])
	{
?>
								<script type="text/javascript" language="Javascript">
	window.dlg_{var:opID}Config{record.index}_{var:opIDX} = { title : "{string:'dlg_delete_title'}", message : "{string:'dlg_delete_content'}", viewMode : "okCancel", url : "{var:url}&mode=page", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };
	</script>
								<a href="javascript:void(0);" class="s-icon {$iconCls}" title="{$title}" onclick="PMModalbox.display(window.dlg_{var:opID}Config{record.index}_{var:opIDX}, event);return false;">
									<span class="x-hidden">{$title}</span></a><?php 
	}
	else
	{
?><a href="javascript:void(0);" class="s-icon {$iconCls}" title="{$title}" onclick="ajax_navigate(event,'{var:url}&mode=ajax','{var:id}')"><span class="x-hidden">{$title}</span></a><?php 
	}
}

//$listOperations = null;
?>
							<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

							 {if:record.is_first} 
<tr>
	{fields}
	<th>{field.label}</th>
	{/fields}
	<th></th></tr>
 {/if} 

							<tr class="row-{record.index} grid-row row_{record.even_odd}" onclick="ajax_navigate(event,'{var:edit_url}{record.url_key}&mode=ajax','content')">
							{fields}
                           
								{if:#field.name != 'email_content'}
									<td class="cell-{field.index} cell-{field.name}"><div class="simple-wrapper">{field}</div></td>
								{/if}
							{/fields}

							<td class="operations operations-2" onclick="window.event.cancelBubble = true;if(event.stopPropagation) event.stopPropagation();return false;"><div class="simple-wrapper">{=operations_st}</div></td></tr>
						{/record}
						</table></div>
				{/if}
				{/records}

				{no_record}
				<div class="tab_empty"><?php
					$msg = $this->getProperty('tab_empty_list_msg');
					if(!$msg)
						$msg = __('emails_empty_list');
					echo $msg;
				?>
				</div>
				{/no_record}
				
				{if:pages.several_pages || pages.nb_records > 0}
<?php
if(isset($_REQUEST['ltr']) && $_REQUEST['ltr'])
{
	$ltrUrl = '&ltr='.$_REQUEST['ltr'];
}
else
{
	$ltrUrl = '';
}
?>
<div class="pm-pagination clear-both">
	{if:pages.several_pages}
	<ul class="pages"><li class="first-meta"><span>Page(s) {pages.current} sur {pages.nb_pages} : </span></li>
		{pages:previous}
		<li class="previous"><a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{var:ltrUrl}&amp;mode=ajax','content');return false;">&laquo; Page pr&eacute;c&eacute;dente</a></li>
		{/pages}

		{pages:all}
		{if:page.is_current}
		<li class="active"><span>{page.index}</span></li>
		{else}
		<li><a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{var:ltrUrl}&amp;mode=ajax','content');return false;">{page.index}</a></li>
		{/if}
		{/pages}

		{pages:next}
		<li class="next"><a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{var:ltrUrl}&amp;mode=ajax','content');return false;">Page suivante &raquo;</a></li>
		{/pages}
	</ul>
	{/if}

	{if:pages.nb_records > 0}
	<div class="items-count"><span class="pm-pagination-records-count"><strong>{pages.nb_records}</strong> {string:"items_search"}</span></div>
	{else}
	<div class="items-count"><span class="pm-pagination-records-count"><strong>{records.count}</strong> {string:"items_search"}</span></div>
	{/if}
</div>
{/if}
			</div></div></div></div><br/><br/>


        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="emails_received";	ob_start(); ?>
        ﻿<?php 
    $emails = new PersistentCollection('rct_candidate_email.list','db',array('candidate_oid',$_REQUEST['oid']));
    if($emails->isOk())
    $this->setProperty('page.records',$emails->records);

    $actions = array(
    );
    $listOperations = array(
    'edit'=>array('nxo'=>'emails:display','iconCls'=>'si-page-white','id'=>'content-emails'),
    );
    $tabId='emails';
    $opPar='nxo';
    $title=__('Emails reçus du candidat');
    $this->setProperty('nxo','nxo');
    $void = isset($_GET['void'])?$_GET['void']:'';

?>

{records:page.records}
{if:records.count>0}
<style>
#received-emails div.email_content
{
	border:solid 1px #eee;
	border-radius:5px;
}
</style><div class="pm-bxm-box-wrapper pm-bxm-box-last"><div class="pm-bxm-box"><div class="box-title-wrapper box-title-blue"><div class="box-title"><h3>{var:title}</h3></div></div><div class="pm-bxm-box-content" id="received-emails"><div class="pm-grid-outer-wrapper"><div class="pm-grid-wrapper"><table id="table-{var:tabId}" class="pm-grid">
                        {record}
                        <tr class="row-{record.index} grid-row row_{record.even_odd}" onclick="$('email_content_{record.index}').toggle()"><td class="cell-1 cell-name"><div class="simple-wrapper">{field:email_from_name} {if:%field.object:email_from% }&lt;{field:email_from}&gt;{/if}</div></td><td class="cell-subject"><div class="simple-wrapper">{field:email_title}</div></td><td class="cell-cv"><div class="simple-wrapper">{field:cv}</div></td><td class="cell-lm"><div class="simple-wrapper">{field:lm}</div></td><td class="cell-date"><div class="simple-wrapper">{field:date}</div></td></tr><tr id="email_content_{record.index}" class="email_content" style="display:none" onclick="this.toggle()"><td colspan="5" style="text-align:center"><iframe id="iframe_email_content_{field.object:oid}" class="email_content" src="{=email.url}{field.object:oid}" scrolling="yes" frameborder="0" width="100%" height="600px"></iframe></td><tr>

                        {/record}
                    </tr></tr></table></div></div></div>
{/if}
</div></div>
{/records}
<br/><br/>

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="vacancies_list";	ob_start(); ?>
        <?php
	$currentGroup = uniqid('sub_form_');
?>
<style>
    #vacancies_div{
        padding: 5px 0;
    }
    .history_row{
        border-top: solid 4px #fff;
    }
</style>
{records:candidates_vacancies_list.records}

    {record}

		<table class="directory-grid"><?php 
            $oid = $_nx_record->oid->object;
            $editUrl = $editUrlDir.'void-'.$oid.'/'.$editUrlBase.$_nx_record->getUrlKey();
            $candidateUrl = $editUrlDir.'void-'.$oid.'/'.$candidatesUrlBase.$_nx_record->getUrlKey();
			$PORTAL_URL_PREFIX = PORTAL_URL_PREFIX;
    ?>
			<script type="text/javascript" language="Javascript">
        window.chargeArrow =function(event,url,content) {
            ajax_navigate(event,url,content);
            PMDH.toggle(content,'appear');
            return false;
        };
    </script>
			<tr>
				<td colspan="5" class="btns_row">
            {if:#field:key_readonly# == 0 or #field:key_recrute# != 0 or #field:key_total_control# !=0}
            
					<div class="dg-cell-wrapper">
						<script type="text/javascript" language="Javascript">

                    window.dlg_unlinkConfig_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'dlg_unlink_candidate_title'}",
                        message: "{string:'dlg_unlink_candidate_content'}",
                        viewMode: "okCancel",
                        url: "{=unlink_candidate.url}{field.object:oid}{record.url_key}",
                        target: "content",
                        labels: {
                            ok: "{string:'dlg_ok'}",
                            cancel: "{string:'dlg_cancel'}"
                        }
                    };

                    window.dlg_confirmForJobConfig_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'dlg_confirm_for_job_title'}",
                        message: "{string:'dlg_confirm_for_job_content'}",
                        viewMode: "okCancel",
                        url: "{=accepted_for_job.url}{field.object:oid}{record.url_key}",
                        target: "content",
			labels: {
                            ok: "{string:'dlg_ok'}", cancel: "{string:'dlg_cancel'}"
                        }
                    };

                    window.dlg_cancelForJobConfig_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'dlg_cancel_for_job_title'}",
                        message: "{string:'dlg_cancel_for_job_content'}",
                        viewMode: "okCancel",
                        url: "{=cancel_accepted_for_job.url}{field.object:oid}{record.url_key}",
                        target: "content", labels: {
                            ok: "{string:'dlg_ok'}", cancel: "{string:'dlg_cancel'}"
                        }
                    };

                    window.dlg_refuseConfig_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'dlg_refuse_candidate_title'}",
                        message: "{string:'dlg_refuse_candidate_content'}",
                        viewMode: "okCancel",
                        url: "{=refuse_candidate.url}{field.object:oid}{record.url_key}",
                        target: "content", labels: {
                            ok: "{string:'dlg_ok'}", cancel: "{string:'dlg_cancel'}"
                        }
                    };

                    window.dlg_accepted_proposal_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'accepted_proposal_title'}",
                        url: "{=accepted_proposal.url}{field.object:oid}{record.url_key}",
                        width: 550
                    }
                    window.dlg_refused_proposal_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'refused_proposal_title'}",
                        url: "{=refused_proposal.url}{field.object:oid}{record.url_key}",
                        width: 550
                    }
                    window.dlg_send_to_client_{$currentGroup}_{field.object:oid}= {
                        title: "{string:'send_to_client_title'}",
                        url: "{=send_to_ic.url}{field.object:oid}{record.url_key}",
                        width: 550
                    };

                </script>
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.loadFromUrl(window.dlg_send_to_client_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-page-white-go">{string:"send_to_client_helper"}</span></span></a>
						<span class="pm-button-sep"></span>

                {if:#field.object:job_acceptance_state# == '1'}
                
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.display(window.dlg_cancelForJobConfig_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-user-delete">{string:"unselect_for_job_helper"}</span></span></a>
						<span class="pm-button-sep"></span>
                {else}
                
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.display(window.dlg_confirmForJobConfig_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-user-add">{string:"selected_for_job_helper"}</span></span></a>
						<span class="pm-button-sep"></span>
                {/if}
                {if:trim(#field.object:status#) == '8'}
                
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="ajax_navigate(event,'{=reinit_status.url}{field.object:oid}{record.url_key}','content'); return false;">
							<span class="btn-bg">
								<span class="s-icon si-tick">{string:"accept_candidate_helper"}</span></span></a>
						<span class="pm-button-sep"></span>
                {else}
                
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.display(window.dlg_refuseConfig_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-cross">{string:"refuse_candidate_helper"}</span></span></a>
						<span class="pm-button-sep"></span>
                {/if}

                
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.loadFromUrl(window.dlg_accepted_proposal_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-thumb-up">{string:"accepted_proposal_helper"}</span></span></a>
						<span class="pm-button-sep"></span>
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.loadFromUrl(window.dlg_refused_proposal_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-thumb-down">{string:"refused_proposal_helper"}</span></span></a>
						<span class="pm-button-sep"></span>
						<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="window.chargeArrow(event,'{=candidate_record.url}{field.object:oid}','candidate_history_{$currentGroup}_{field.object:oid}','idButton_{$currentGroup}_{field.object:oid}'); return false;">
							<span class="btn-bg">
								<span class="s-icon si-information">{string:"poste_historique"}</span></span></a>
						<span class="pm-button-sep"></span></div>
            {/if}
        </td>
			</tr>
			<tr class="directory-grid-row columns-layout columns-layout-4 width-padding width-white-border row_odd" title="{string:'poste_details'}">
				<td class="dg-column" onclick="window.chargeArrow(event,'{=candidate_record.url}{field.object:oid}','candidate_history_{$currentGroup}_{field.object:oid}','idButton_{$currentGroup}_{field.object:oid}'); return false;">
            {if:%field.object:manager_oid% == %user:oid%}
            
					<div class="star-five yellow" style="float:right;position:relative;top:-10px;" title="{string:'Poste dont je suis le recruteur'}"></div>
            {/if}
            {if:%field.html:contract_type_oid% == 'Stage'}
            
					<span style="font-weight:bold;color:#7FBA00;float:right;position:relative;top:-10px;font-size:16px;" title="Stage">S</span>
            {/if}

            
					<div class="dg-cell-wrapper">
						<span class="field-content"><strong>{field:name}</strong></span>
                {if:#field.object:number# != ''}
                
						<span class="field-content">({field:number})</span>
                {/if}
                
<br/>
						<span class="field-content">{field:category_oid}{if:#field.object:category_oid# != '' && #field.object:contract_type_oid#}, {/if}{field:contract_type_oid}</span>
                {if:#field.object:code# != ""}
                
<br/>
						<span class="field-content">{string:"code_no"} {field:code}</span>
                {/if}
                
<br/>
						<span class="field-content">{string:"manager_oid"} : {field:manager_oid}</span></div></td>
				<td class="dg-column elastic" onclick="window.chargeArrow(event,'{=candidate_record.url}{field.object:oid}','candidate_history_{$currentGroup}_{field.object:oid}','idButton_{$currentGroup}_{field.object:oid}'); return false;">
					<div class="dg-cell-wrapper">
						<span class="field-label">{field.label:subsidiary_oid} :</span>
						<span class="field-content">{field:subsidiary_oid}</span>
<br/>
						<span class="field-label">{field.label:service_oid} :</span>
						<span class="field-content">{field:service_oid}</span>
<br/>
						<span class="field-label">{field.label:duty_station_oid} :</span>
						<span class="field-content">{field:duty_station_oid}</span>
<br/>
						<span class="field-label">{field.label:establishment} :</span>
						<span class="field-content">{field:establishment}</span></div></td>
				<td class="dg-column elastic" onclick="window.chargeArrow(event,'{=candidate_record.url}{field.object:oid}','candidate_history_{$currentGroup}_{field.object:oid}','idButton_{$currentGroup}_{field.object:oid}'); return false;">
					<div class="dg-cell-wrapper">
						<span class="field-label">{field.label:progress_level} :</span>
						<span class="field-content">{field:current_step}</span>
<br/>
						<span class="field-label">{field.label:current_step} :</span>
						<span class="field-content">{field:progress_level}{if:#field:progress_level_meta# != ''} ({field:progress_level_meta}){/if}</span>
<br/>
						<span class="field-label">{string:"application_type"} :</span>
						<span class="field-content">{field:application_type}</span>
<br/>
						<div style="float:right">
							<span class="field-label">{string:"number_candidates"} :</span>
							<span class="field-content candidate_count">{field:candidates_count}</span></div></div></td>
				<td class="dg-column elastic" onclick="window.chargeArrow(event,'{=candidate_record.url}{field.object:oid}','candidate_history_{$currentGroup}_{field.object:oid}','idButton_{$currentGroup}_{field.object:oid}'); return false;">
					<div class="dg-cell-wrapper">
						<span class="field-label">{field.label:opening_date} :</span>
						<span class="field-content">
									{if:#field:opening_date# != '-/-/-'}{field:opening_date}{else}-{/if}
									</span>
<br/>
						<span class="field-label">{field.label:closing_date} :</span>
						<span class="field-content">
									{if:#field:closing_date# != '-/-/-'}{field:closing_date}{else}-{/if}
									</span>
<br/>
						<span class="field-content">&nbsp;</span></div></td>
				<td class="dg-column elastic">
					<div class="dg-cell-wrapper">
						<a class="pm-button btn-with-icon" style="margin-bottom:5px" href="javascript:void(0);" onclick="document.location.href='{var:PORTAL_URL_PREFIX}/recruitment/vacancies/admin/directory.php?nxo=candidates&mode=page&oid={field.object:oid}#candidate_{field.object:candidate_oid}'">
							<span class="btn-bg">
								<span class="s-icon si-arrow-redo">{string:"go_to_vacancy"}</span></span></a>
						<span class="pm-button-sep"></span>
						<a class="pm-button btn-with-icon" style="width:140px" href="javascript:void(0);" onclick="PMModalbox.display(window.dlg_unlinkConfig_{$currentGroup}_{field.object:oid}, event); return false;">
							<span class="btn-bg">
								<span class="s-icon si-disconnect">{string:"unlink_candidate"}</span></span></a>
						<span class="pm-button-sep"></span></div></td>
			</tr>
			<tr>
				<td colspan="5">
					<div class="candidate-history-wrapper history_row" id="candidate_history_{$currentGroup}_{field.object:oid}" style="display:none;"></div></td>
			</tr>
		</table>
    {/record}


{/records}

{no_record}

		<div class="empty-records">{string:"empty_vacancies_list"}</div>
{/no_record}

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="panel_cv_preview";	ob_start(); ?>
        {record:page.record}
{if:#field.string:cv_path:url# == ""}

		<div class="empty-records">Il n’ya pas de CV attaché à cette fiche candidat, Merci d’utiliser le bouton mise à jour de CV qui se trouve au dessus pour ajouter un CV.</div>
{else}

		<iframe src="{field.string:cv_path:url}" width="100%" height="800" frameborder="0" marginwidth="0" marginheight="0" align="top" hspace="0" vspace="0" scrolling="0"></iframe>

{/if}

{/record}
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="panel_toolbox";	ob_start(); ?>
        

		<div class="pm-bxm-box-wrapper">
			<div class="pm-bxm-box">
				<div class="box-title-wrapper box-title-red">
					<div class="box-title"><h3><strong>{string:"toolbox"}</strong></h3></div></div>
				<div class="pm-bxm-box-content">
					<div class="columns-layout clear-both">
						<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:"HR management"}</h3></div>
						<div class="pm-bx-form pm-bxm-box-content">
							<div class="record_wrapper">
								<div class="record">
									<div class="control-main-wrapper">
										<div class="control-wrapper">
											<div class="control control-small">
										{field:hr_manager}
									</div></div></div>
									<div class="right">
										<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMFormSubmit.submit(this, dlg_waitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;">
											<span class="btn-bg">
												<span class="s-icon si-disk">{string:"submit"}</span></span></a></div></div></div></div>
				{=send}
				
<br/>
						<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:"candidate_etat"}</h3></div>
						<div class="pm-bx-form pm-bxm-box-content">
					{=etats}
				</div>
						<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:"qualification CV"}</h3></div>
						<div class="pm-bx-form pm-bxm-box-content">
							<div class="record_wrapper">
								<div class="record">
									<div class="control-main-wrapper">
										<div class="control-label-wrapper">
											<div class="control-label">{field.label:available_from}</div></div>
										<div class="control-wrapper">
											<div class="control control-small">
												<div style="float:left">{field:available_delai}</div>
												<div style="float:left">{field:available_from}</div></div></div></div>
									<div class="control-main-wrapper">
										<div class="control-label-wrapper">
											<div class="control-label">{field.label:salary_min}</div></div>
										<div class="control-wrapper">
											<div class="control">
												<div class="control control-small">
										{field:salary_min} {field:salary_max}
										</div></div></div></div>
									<div class="control-main-wrapper">
										<div class="control-label-wrapper">
											<div class="control-label">{field.label:profile}</div></div>
										<div class="control-wrapper">
											<div class="control">
												<div class="control">{field:profile}</div></div></div></div>
									<div class="control-main-wrapper">
										<div class="control-label-wrapper" style="width:100%">
											<div class="control-label">{field.label:category_oid}</div></div>
										<div class="control-wrapper">
											<div class="control">
												<div class="control">
											{field:category_oid}
										</div></div></div></div>
									<div class="control-main-wrapper">
										<div class="control-label-wrapper">
											<div class="control-label">{field.label:years_of_practice}</div></div>
										<div class="control-wrapper">
											<div class="control control-small">
										{field:years_of_practice}						
									</div></div></div></div></div></div>
						<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:"candidate_vacancies"}</h3></div>
						<div class="pm-bxm-box-content">
					{=vacancies}
					{=available_vacancies}
				</div></div></div></div></div>


 
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="buttons_cv";	ob_start(); ?>
        <?php

if($_nx_record->cv_path->path)
{
?>

		<a class="pm-button btn-with-icon" href="{=download_cv.url}" style="float:right">
			<span class="btn-bg">
				<span class="s-icon si-page-white-acrobat">{string:"download_cv"}</span></span></a>
		<span class="pm-button-sep"></span>
{/if}


		<script type="text/javascript" language="Javascript">
    window.update_cvConfig = {
        exec:function() { PMModalbox.display(window.update_cvConfig, null); },
        content_id : 'update_resume',
        title : "{string:'update_resume'}",
        message : "{string:'update_resume_header'}",
        viewMode : "cancel",
        target : "content",
        labels : { cancel : "{string:'dlg_cancel'}" }
    };
</script>
		<a class="pm-button btn-with-icon" href="javascript:void(0);" style="float:right" onclick="window.update_cvConfig.exec(); this.blur(); return false;">
			<span class="btn-bg">
				<span class="s-icon si-table-go">{string:"update_resume"}</span></span></a>
		<span class="pm-button-sep" style="float:right"></span>
<br/>
<br/>
<br/>

        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="button_save";	ob_start(); ?>
        
<br/>
		<a class="pm-button btn-with-icon" href="javascript:void(0);" style="float:right" onclick="PMFormSubmit.submit(this, dlg_waitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;">
			<span class="btn-bg">
				<span class="s-icon si-disk">{string:"submit"}</span></span></a>
<br/>
		<script type="text/javascript" language="Javascript">
    window.dlg_waitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };
    window.dlg_successConfig = {
        title : "{string:'dlg_success_title'}",
        message : "{string:'dlg_success_content'}",
        viewMode : "ok",
        url : "{=edit.url}&mode=ajax",
        target : "content",
        labels : { ok : "{string:'dlg_success'}" }
    };

    window.dlg_failureConfig = {
        title : "{string:'dlg_failure_title'}",
        message : "{string:'dlg_failure_content'}",
        viewMode : "cancel",
        target : "content",
        labels : { cancel : "{string:'dlg_cancel'}" }
    };
</script>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="button_associer";	ob_start(); ?>
        
		<div class="pm-button-wrapper clear-both" id="association_button">
			<a class="pm-button btn-with-icon" href="javascript:void(0);" style="float: right" onclick="associateToVacancy('available_vacancies-control', 'available_vacancies', 'associate-to-vacancy'); this.blur(); return false;">
				<span class="btn-bg">
					<span class="s-icon si-attach">{string:"Associer"}</span></span></a>
			<div id="vacancy-button-loader" style="display:none;"></div></div>
<br/>
		<script type="text/javascript" language="Javascript">
    window.dlg_associateToVacancy = {
        title : "{string:'assoc_to_vacancy_title'}",
        url: "{=massive_associate_to_vacancy.url}{record.url_key}",
        width:550
    };

    function associateToVacancy (control, field, wrapper) {
        Modalbox.show(null,{overlayClose: false});
        var form 			= PMDH.getParentElementByTagName(document.getElementById(control),'form');
        var select 			= form.elements[field];
        var vacancyValue 	= select.options[select.selectedIndex].value;
        var url = '{=associate_to_vacancy.url}';

        if( vacancyValue == '?' ) {
            new Effect.Highlight(
                    select,
                    { startcolor: '#fbb2b2', endcolor: '' }
            );
            return false;
        } else {
            
            new Ajax.Request(url+'&vacancy_oid='+vacancyValue,{
                method		: 'post',
                asynchronous: true,
                contentType	: 'application/x-www-form-urlencoded',
                encoding	: 'UTF-8',
                onSuccess	: function(transport) {
                    document.location.href= window.location.href+'&tab=vacancies';
                }
            });
        }
    };
</script>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="buttons_send_to_collab";	ob_start(); ?>
        
		<span class="pm-button-sep"></span>
		<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.loadFromUrl({ title:'{string:'send_to_client_title'}',width:550,url: '{=send_to_client.url}{record.url_key}'}, event); return false;" style="float:right">
			<span class="btn-bg">
				<span class="s-icon si-send">{string:"send_to_collab"}</span></span></a>
		<span class="pm-button-sep"></span>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php $_nx_content_stack[]="button_delete";	ob_start(); ?>
        
		<span class="pm-button-sep"></span>
		<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="PMModalbox.display(window.window.dlg_massiveDeleteCfg, event); return false;" style="float:right">
			<span class="btn-bg">
				<span class="s-icon si-delete">{string:"delete"}</span></span></a>
		<span class="pm-button-sep"></span>
		<script type="text/javascript" language="Javascript">
    window.dlg_massiveDeleteCfg = {
        title 		: "{string:'dlg_delete_title'}",
        message 	: "{string:'dlg_delete_content'}",
        viewMode 	: "okCancel",
        url 		: "{=delete.url}",
        target 		: "content",
        labels	 	: {
            ok 		: "{string:'dlg_ok'}",
            cancel 	: "{string:'dlg_cancel'}"
        }
    };
</script>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="buttons";	ob_start(); ?>
        {if:%property:previous_operation_link.url%}

		<a class="pm-button btn-with-icon" href="{=previous_operation_link.url}">
			<span class="btn-bg">
				<span class="s-icon si-application-side-contract">
        {if:%property:from_vacancy%}{string:"back_to_vacancy"}{elseif:%property:from_vacancy_calendar%}{string:"back_to_vacancy_calendar"}{elseif:%property:my_calendar%}{string:"back_to_calendar"}{else}{string:"back"}{/if}
    </span></span></a>
{else}

		<a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.hide_cv_menu();PMFormSubmit.validate(this, dlg_backConfig, event); this.blur(); return false;">
			<span class="btn-bg">
				<span class="s-icon si-application-side-contract">{string:"back"}</span></span></a>
{/if}

		<span class="pm-button-sep"></span>
		<a class="pm-button btn-with-icon" id="form-submit" href="javascript:void(0);" onclick="PMFormSubmit.submit(this, dlg_waitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;">
			<span class="btn-bg">
				<span class="s-icon si-disk">{string:"submit"}</span></span></a>
		<span class="pm-button-sep"></span>
		<script type="text/javascript" language="Javascript">
    window.dlg_waitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };
    window.dlg_successConfig = {
        title : "{string:'dlg_success_title'}",
        message : "{string:'dlg_success_content'}",
        viewMode : "ok",
	url : "{=edit.url}&mode=ajax",
        target : "content",
        labels : { ok : "{string:'dlg_success'}" }
    };

    window.dlg_failureConfig = {
        title : "{string:'dlg_failure_title'}",
        message : "{string:'dlg_failure_content'}",
        viewMode : "cancel",
        target : "content",
        labels : { cancel : "{string:'dlg_cancel'}" }
    };
</script>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="upload_file";	ob_start(); ?>
        
		<div id="upload_file" style="display:none">
			<div class="ged_miniform ged_add_files">
<br/>
<br/>
				<form id="" method="post" action="{=add_attached_files.url}" enctype="multipart/form-data">
<input type="hidden" value="100000000" name="MAX_FILE_SIZE"/>
<input type="hidden" value="POST" name="_form_method_"/>
<input type="file" name="file" id="file" value="" style="width:100%; margin: -1px 0 0;"/>
<br/>
<br/>
					<button>{string:'add file'}
					</button>
				</form>
<br/>
<br/></div></div>
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

        <?php $_nx_content_stack[]="historique";	ob_start(); ?>
        {records:candidate_log.records}

		<div class="table-list-wrapper log-table">
			<table class="table-list">
        {record}
        
				<tr>
					<td class="entry"><strong>{field:action_oid}</strong> par {field:user_oid} {field:date} {if:#field.object:ref_oid#!=null && #field.object:ref_oid#!=0 }(Poste:{field.html:ref_oid}){/if}{field:additional_infos}</td>
				</tr>
        {/record}
    
			</table></div>
{/records}
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
		
		<?php $_nx_content_stack[]="consultations";	ob_start(); ?>
        {records:page.records}

		<div class="table-list-wrapper log-table">
			<table class="table-list">
        {record}
        
				<tr>
					<td class="entry">Lu par <strong>{field:user_oid}</strong>. Date <strong>{field:read_time}</strong></td>
				</tr>
        {/record}
    
			</table></div>
{/records}
        <?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
		

        
	<div id="content_form" class="pm-bxm-wrapper">
		{form:page.record}
		
		<script language="javascript" type="text/javascript">
			window.autoSaveDesc = null;
			window.content_form = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
			{
				window.currentForm.handler = window.content_form_handler = new window.Generis.Forms(window.currentForm);
				// window.currentForm.className += 'form-horizontal';
			}

		</script>
			<script type="text/javascript" language="Javascript">
			
			document.getElementById('page_title').innerHTML = 'Fiche candidat : <a>{field.html:first_name} {field.html:last_name}</a> ';
            if (typeof document.getElementById('page-bread-crumb') === "undefined") {
				document.getElementById('page-bread-crumb').innerHTML += ' > <span class="png_bg"><a class="nav-item" href="#">'+document.getElementById('page_title').innerHTML+'</a></span>';
			}
			
			</script>
				<table class="table-edit">
					<tr>
						<td>
						<div class="form-actions-wrapper">
							<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
                               {=buttons}
                               {=buttons_send_to_collab}
							   {=button_delete}
                            </div></div>
						<script language="javascript" type="text/javascript">
			window.taber = new window.Generis.Tabs();
		</script><?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','cv'));
				if($firstTab != 'cv')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="cv" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('cv','cv_div',null,'active')"><b>{string:'cv'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="cv_div" class="tab panel">
									<div id="panel_" class="form-panel-bs">
										<div class="">
												<div class="box-title-wrapper box-title-red">
													<div class="box-title"><h3>{string:'cv'}</h3></div></div>
											<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
                                        {=buttons_cv}
                                        {=panel_cv_preview}
                                    </div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','recruitement_card'));
				if($firstTab != 'recruitement_card')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="recruitement_card" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('recruitement_card','recruitement_card_div',null,'active')"><b>{string:'recruitement card'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="recruitement_card_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'recruitement card'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'comments'}</legend><div class="form-group-content">
                                                    {=comments_part}
                                                </div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'upload_file'}</legend><div class="form-group-content">
                                                    {=panel_files}
                                                </div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'candidate_interviews'}</legend><div class="form-group-content">
                                                    {=interviews}
                                                </div></fieldset><fieldset id="group_test_cand" class="field-group-bs"><legend class="">{string:'candidate_tests'}</legend><div class="form-group-content">
                                                    {=tests}
                                                </div></fieldset><fieldset id="group_3" class="field-group-bs"><legend class="">{string:'recrutement'}</legend><div class="form-group-content">{get_field:relevance}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:relevance}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:relevance}</div></div>{get_field:sources}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:sources}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:sources}</div></div>{get_field:application_type}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:application_type}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:application_type}</div></div>{get_field:archive_state}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:archive_state}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:archive_state}</div></div>{get_field:cand_channel}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:cand_channel}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:cand_channel}</div></div>{get_field:establishment}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:establishment}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:establishment}</div></div></div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','general_infos'));
				if($firstTab != 'general_infos')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="general_infos" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('general_infos','general_infos_div',null,'active')"><b>{string:'candidate_infos'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="general_infos_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'candidate_infos'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'profile_infos'}</legend><div class="form-group-content">{get_field:last_name}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:last_name}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:last_name}</div></div>{get_field:first_name}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:first_name}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:first_name}</div></div>{get_field:civility}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:civility}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:civility}</div></div>{get_field:gender}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:gender}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:gender}</div></div>{get_field:date_of_birth}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:date_of_birth}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:date_of_birth}</div></div>{get_field:nationality}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:nationality}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:nationality}</div></div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'candidate_infos'}</legend><div class="form-group-content">{get_field:studies_level}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:studies_level}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:studies_level}</div></div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'coordinates'}</legend><div class="form-group-content">{get_field:email}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:email}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:email}</div></div>{get_field:mobile}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:mobile}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:mobile}</div></div>{get_field:phone_1}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:phone_1}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:phone_1}</div></div>{get_field:phone_2}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:phone_2}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:phone_2}</div></div>{get_field:zip}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:zip}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:zip}</div></div>{get_field:country_oid}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:country_oid}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:country_oid}</div></div>{get_field:town_oid}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:town_oid}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:town_oid}</div></div></div></fieldset></div></div></div></div></div></div><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'education_infos'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'education_entries_1'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:education_entries}</div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'bachelor'}</legend><div class="form-group-content">{get_field:bachelor_year}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:bachelor_year}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:bachelor_year}</div></div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'languages'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:language_entries}</div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'education_entries_2'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:education_entries_2}</div></div></fieldset></div></div></div></div></div></div><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'experiences'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'experiences'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:employment_entries}</div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'training'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:training_entries}</div></div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','emails'));
				if($firstTab != 'emails')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="emails" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('emails','emails_div',null,'active')"><b>{string:'emails'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="emails_div" class="tab panel">
                                    {=emails}
                                    {=emails_received}
                                </div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','vacancies'));
				if($firstTab != 'vacancies')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="vacancies" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('vacancies','vacancies_div',null,'active')"><b>{string:'vacancies'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="vacancies_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-green"><div class="box-title"><h3>{string:'title_vacancies'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><fieldset id="group_1" class="field-group-bs"><legend class=""/><div class="form-group-content"><div id="add_vacancy_wrapper"><div id="add_vacancy_wrapper2">{get_field:available_vacancies}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:available_vacancies}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:available_vacancies}</div></div>
														{=button_associer}
													</div></div></div></fieldset><div class="vancancies_wrapper">
													{=vacancies_list}
												</div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','historique'));
				if($firstTab != 'historique')
					$firstTab = $$firstTab;

				$displayMode = 'display:block';
				$classNav='active current';
			}
			else
			{
				$displayMode = 'display:none;';
				$classNav='';
			}
		?>

		<?php $_nx_content_stack[]="tabs_help";	ob_start(); ?>
			{=tabs_help}
			
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="historique" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('historique','historique_div',null,'active')"><b>{string:'historique'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="historique_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-green"><div class="box-title"><h3>{string:'historique'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
                                                {=historique}
                                        </div></div></div><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper box-title-green"><div class="box-title"><h3>{string:'viewer_list'}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
                                                {field:viewers}
                                        </div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	
<input type="hidden" name="tab" value="{$tab}" id="taber"/>

		{if:trim(%property:tabs_help%)}
		
						<div id="help" class="help">{=tabs_help}</div>
						<script type="text/javascript" language="Javascript">
			var helpDiv=document.getElementById('help');
			var helpText = (helpDiv.innerText||helpDiv.textContent).replace(/\s+/,'');
			if(!helpText)
				helpDiv.style.display = 'none';
		</script>

		{/if}

		
							<div id="nav">
								<ul class="nav nav-tabs nav-tabs-bs">{=tabs_nav}
								</ul></div>

		{=tabs_src}

		<?php 
global $firstTab;
$tab = isset($_REQUEST['tab']) ? $_REQUEST['tab'] : $firstTab;
			
		?>
						<script language="javascript" type="text/javascript">
	if('{$tab}'!='')
		window.taber.current_menu('{$tab}','{$tab}_div',null,'active');
</script></td>
						<td class="td-toolbox">
						<div id="panel_toolbox" class="form-panel-bs">
							<div class="">
									<div class="box-title-wrapper box-title-red">
										<div class="box-title"><h3>{string:'toolbox'}</h3></div></div>
								<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
							<fieldset id="group_1" class="field-group-bs">
								<legend class="">{string:'HR management'}
								</legend>
								<div class="form-group-content">{get_field:hr_manager}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:hr_manager}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:hr_manager}</div></div></div>
							</fieldset>
							<fieldset id="group_2" class="field-group-bs">
								<legend class="">{string:'candidate_etat'}
								</legend>
								<div class="form-group-content">{get_field:etat_oid}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:etat_oid}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:etat_oid}</div></div></div>
							</fieldset>
							<fieldset id="group_3" class="field-group-bs">
								<legend class="">{string:'qualification CV'}
								</legend>
								<div class="form-group-content">{get_field:available_delai}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:available_delai}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:available_delai}</div></div>
								<div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:available_from}</div>{get_field:salary_min}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:salary_min}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:salary_min}</div></div>{get_field:salary_max}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:salary_max}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:salary_max}</div></div>{get_field:profile}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:profile}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:profile}</div></div>{get_field:category_oid}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:category_oid}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:category_oid}</div></div>{get_field:years_of_practice}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:years_of_practice}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:years_of_practice}</div></div></div>
							</fieldset></div></div></div></td>
					</tr>
				</table>
			{/form}

			
		<script language="javascript" type="text/javascript">			
				if(window.autoSaveDesc)
				{
					window.content_form_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			</script></div>
    {=update_resume}
    {=upload_file}

    
		<script type="text/javascript" language="Javascript">
		var edit_url = "{=submit.url}";
        window.ajax_load('/nx/skins/default/js/recruitment/form_candidate.js','form_candidate_js');
    </script><?php 	
			$__buf=ob_get_contents();
			ob_end_clean();
			echo preg_replace(
				array('/[ \t]+/'),
				array(' '), $__buf);
		; ?>
			<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
			<?php 
			if(isset($_REQUEST['mode']) && $_REQUEST['mode']=='ajax') {
			?>
				{=page.content}
			{else}
				<!DOCTYPE HTML>
<?php
if(preg_match('/AppleWebKit/i',$_SERVER['HTTP_USER_AGENT']) && !preg_match('/chrome/i',$_SERVER['HTTP_USER_AGENT']))
{
	$device='ipad';
}
else
	$device='pc';
$pageMode = isset($_GET["spacemode"])?$_GET["spacemode"]:(isset($_GET["pagemode"])?($_GET["pagemode"]):'');
$this->setProperty('pagemode',$pageMode);
$portalType = $this->getProperty('portal.type');
?>

<html lang="fr"  class="lang_{=lang} device_{$device}">
<head>
	<title><?php echo INTRANET_TITLE; ?></title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />

<?php
if($device=='ipad') 
{
?>
	<meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=0, minimum-scale=1.0, maximum-scale=1.0" />
	<meta name="apple-mobile-web-app-capable" content="yes" />

	<!-- CSS -->
	<style type="text/css" media="all">
	#wrapper {
		position:absolute;
		z-index:1;
		top:0px; bottom:0px; left:0;
		width:100%;
		overflow:auto;
	}
	#scroll-content {
		position:absolute;
		z-index:1;
		width:100%;
		padding:0;
	}
	</style>

<?php 
} 
?>


	<!-- CSS -->
	{require:css/page_bs.css:skin}
	{require:js/page.js:skin}
		
	{if:%var:pageMode% == 'minimal'}
	<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/minimal.css" media="screen" />
	{/if}
	
	<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/rct_print.css" media="print" />
	
{if:%var:pageMode% != 'minimal'}
	<script language="JavaScript" type="text/javascript" src="/nav/nav_def.php?suid={get:suid|0}&section=fdv&amp;delegate={request:delegate}"></script>

<?php

class PageThemeParams {	function __get($k) {return '';} }

// space theme
class SpacePageThemeParams  extends PageThemeParams {
	function __construct($space,$props) {

		$this->space=$space;
		$this->props = $props;
		$this->type = 'space';

		$bgCol = $space->bgColor->object;
		$bgImURL = $space->bgImage->toHTML('url');
		$banURL = $space->banner->toHTML('url');

		// theme
		$this->theme = $this->space->space_theme->object;

		// title
		if(trim($space->banner_title->url) != '')
		{
			$this->title = '<img src="'.$space->banner_title->url.'" />';
		}
		else
			// $this->title = '<span>Espace</span><br>'.$this->space->title->object;
			$this->title = $this->space->title->object;

		// main banner
		$bannerInnerStyle = '';
		$banner = new PageThemeParams;
		$bannerBg = $space->banner_background->object;
		if( $space->banner->path)
		{
			$banURL = $space->banner->url;

			// inner banner
			$bannerInnerStyle = "background:".$bannerBg." url(".$banURL.") no-repeat 0 0 !important;";
		}

		// background : outer banner
		if($space->banner_background_image->path)
			$banner->style = 'background: url('.$space->banner_background_image->url.') repeat-x scroll 0 0 transparent !important;';

		// float div
		$banfloat = new PageThemeParams;
		if($space->banner_float->path)
		{
			$banfloat->url = $this->space->banner_float->url;
			$banfloat->style = "background: url(".$banfloat->url.") no-repeat right top !important;position: absolute;right: 0;top: 0;";
		}

		// inner banner
		$banInner = new PageThemeParams;
		$this->nav = new PageThemeParams;
		$navBanStyle=''; 

		if($h=$space->banner_height->object)
		{
			$bannerInnerStyle .= 'height: '.$h.'px;'; 
			$this->nav->style = 'top:'.($h-53).'px;';
		}

		$banInner->style = $bannerInnerStyle;

		$banner->inner=$banInner;
		$banner->float=$banfloat;
		$this->banner = $banner;

		// free CSS
		$this->freeCss = $this->space->free_css->object;

		// logo
		$this->logo = new PageThemeParams;
		if($space->logo->path)
			$this->logo->url = $space->logo->url;

		$this->logo->name = 'Logo';

		// menu
		$this->topMenu=new PageThemeParams;
		if( $space->banner_menu->path)
		{
			$banMenuURL = $space->banner_menu->url;
			$this->topMenu->style = <<<EOH
.navTop li .leftOnglet,.navTop li .onglet,ul#main-navigation li.nav-item a.nav-link span,ul#main-navigation li.nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nav-link.hovered span, ul#main-navigation li.nav-item a.nav-link:hover span,
ul#main-navigation li.active-nav-item a.nav-link span, ul#main-navigation li.active-nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nomenu.hovered em,ul#main-navigation li.nav-item a.nomenu:hover em {
	background-image:url($banMenuURL);
}

EOH;
		}

	}
}

// portal theme
class PortalPageThemeParams extends PageThemeParams {
	function __construct($props) 
	{
		$this->props = $props;
		$this->type = 'portal';

		// theme
		$this->theme = $props->getProperty('space.theme','');

		// title
		if( trim($_SERVER['site_informations']['_banner_title']) != "")
		{
			$this->title = '<img src="'.$_SERVER['site_informations']['_banner_title'].'" />';
		}
		else
			$this->title = INTRANET_TITLE;

		// main banner
		$banner = new PageThemeParams;

		$bannerBg = (trim($_SERVER['site_informations']['_banner_background']) == "")?"":$_SERVER['site_informations']['_banner_background'];
		if( trim($_SERVER['site_informations']['_banner']) != "")
		{
			$banURL = (trim($_SERVER['site_informations']['_banner']) == "")?"":$_SERVER['site_informations']['_banner'];
			$banner->style = "background:".$bannerBg." url(".$banURL.") no-repeat 0 0 !important;";
		}

		$banInner = new PageThemeParams;
		$this->nav = new PageThemeParams;
		$navBanStyle=''; 
		$bannerInnerStyle = '';
		if($space->banner_height->object)
			$bannerInnerStyle = 'height: '.$space->banner_height->object.'px;'; 

		if( trim($_SERVER['site_informations']['_banner_height']) != "")
		{
			$bannerInnerStyle = 'height:'.$_SERVER['site_informations']['_banner_height'].'px;';
			$this->nav->style = 'top:'.($_SERVER['site_informations']['_banner_height']-53).'px;';
		}
		$banInner->style = $bannerInnerStyle;

		// float div
		$banfloat = new PageThemeParams;
		if( trim($_SERVER['site_informations']['_banner_float']) != "")
		{
			$banfloat->url = $_SERVER['site_informations']['_banner_float'];
			$banfloat->style = "background: url(".$banfloat->url.") no-repeat 0 0 !important;position: absolute;right: 0;top: 0;";			
		}			

		$banner->float=$banfloat;
		$banner->inner=$banInner;
		$this->banner = $banner;

		// free CSS
		$this->freeCss = $this->space->free_css->object;

		// logo
		$this->logo = new PageThemeParams;
		if(isset($_SERVER['site_informations']['_logo']))
			$this->logo->url = $_SERVER['site_informations']['_logo'];

		$this->logo->name = 'Logo';

		// menu
		$this->topMenu=new PageThemeParams;
		if( trim($_SERVER['site_informations']['_banner_menu']) != "")
		{
			$banMenuURL = (trim($_SERVER['site_informations']['_banner_menu']) == "")?"":$_SERVER['site_informations']['_banner_menu'];
			$this->topMenu->style = <<<EOH
.navTop li .leftOnglet,.navTop li .onglet,ul#main-navigation li.nav-item a.nav-link span,ul#main-navigation li.nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nav-link.hovered span, ul#main-navigation li.nav-item a.nav-link:hover span,
ul#main-navigation li.active-nav-item a.nav-link span, ul#main-navigation li.active-nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nomenu.hovered em,ul#main-navigation li.nav-item a.nomenu:hover em {
	background-image:url($banMenuURL);
}
EOH;
		}
	}
}


?>

<?php 

if($portalType=='space')
{
	$space=$this->getProperty('space.record');
	$pageParams = new SpacePageThemeParams($space,$this);
} 
else
{
	$pageParams = new PortalPageThemeParams($this);
}

$space_theme = $pageParams->theme;
$space_type = $pageParams->type;
$pageType = $pageParams->pageType;
$space_title = $pageParams->title;
$cssTopMenu=$pageParams->topMenu->style;
$bannerFloatStyle = $pageParams->banner->float->style;
$logoUrl = $pageParams->logo->url;
$logoName = $pageParams->logo->name;

?>
{/if}

</head>
<?php flush(); ?>
<body lang="{=lang}" class="lang_{=lang} theme_{var:space_theme}">

<script>
	var fluidScreen = new FluidScreen('content',[680,1024,1280]);
	var homeUrl = '<?php echo PORTAL_HOME; ?>';
</script>

{if:%var:pageMode% != 'minimal'}
<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/theme_{var:space_theme}.css" />

<style>
	#top-navigation {right: 130px;}
	#logo a {padding: 20px;}

	html,body {	background-color:#ffffff;}
	#page-header		{<?php echo $pageParams->banner->style;?>}
	#page-header-inner	{<?php echo $pageParams->banner->inner->style;?> }
	#page-navigation	{<?php echo $pageParams->nav->style; ?>}

	{=skin_free_css_container}
	{var:cssTopMenu}
	<?php echo $pageParams->freeCss; ?>
</style>
{/if}

<link href="/nx/controls/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css"  media="all" />

<div id="wrapper"><div id="scroll-content">
<!--
{if:#property:portal.type# == 'space'}{/if}
 -->
	<div id="page-wrapper">
		
		{if:%var:pageMode% != 'minimal'}
		<div id="page-header">

			<?php if($bannerFloatStyle) {  ?>
			<div id="banner_float" style="<?php echo $bannerFloatStyle; ?>" class="png"><img src="<?php echo $pageParams->banner->float->url; ?>"/></div>
			<?php } ?>

			<div id="page-header-inner">
				<div id="logo">
					<a href="javascript:void(0);" onclick="document.location='<?php echo PORTAL_HOME; ?>';return false;">
					<?php if($logoUrl) { ?>
						<img src="{var:logoUrl}" class="png_bg" alt="{var:logoName}" />
					<?php } ?></a>
				</div>

				<h1 class="banner_title" style="{$bannerTitleStyle}" title="Accueil" onclick="document.location='<?php echo PORTAL_HOME; ?>';return false;">{var:space_title}</h1>
								
				<div id="top-navigation" class="png_bg">
					<div class="top-navigation-w png_bg">
						<div class="top-navigation-i png_bg">
							<ul class="clear-both">
								<li class="first"><span><strong>Bienvenue {user:first_name} {user:last_name}</strong></span></li>
		
								{if:#property:portal.type# != 'space' || #property:portal.suid|portal#!='portal'}
								
								{if:#property:portal.messages# == 'yes'}
								<li><a class="messages" href="/messenger/index.php"><span id="messages-count">...</span> <span class="messages-label">Messages</span></a></li>
								{/if}
		
								<li><a href="/user/profile_editor.php" title="Editer les informations relatives &agrave; mon profil"><span>Mon profil</span></a></li>
								<li class="last"><a href="/user/logout.php"><span>D&eacute;connexion</span></a></li>
								{else}

								{/if}
							</ul>
						</div>
					</div>
				</div>			
			</div>

			<div id="page-navigation">
				<script>
					var currentURL = "<?php echo preg_replace('%/.?oid-[0-9]+/%','/',$_SERVER['REQUEST_URI']); ?>";
					window.container = new Container(nav_def,currentURL);
					// debugger;
					document.write(window.container.nav.displayMenu());
				</script>			
			</div>
			<!-- <div id="page-current-menu" class="clear-both">
				<script>
					var curMenu = container.currentMenu.displayMenu();
					if(curMenu)
						document.write(curMenu);
					else
						$('page-current-menu').hide();
				</script>
			</div>
			-->
		<div id="page-bread-crumb" class="clear-both">
				<script>
					var curMenu = window.container.bc.displayMenu();
					if(curMenu)
						document.write(curMenu);
					else
						$('page-bread-crumb').hide();
				</script>
			</div>
 		</div>
		{/if}
		
		<div id="page-content">
			
			<div id="outer-content-wrapper">
				<div id="content">
					{=page.content}
				</div>
			</div>

		</div>
		
		{if:%var:pageMode% != 'minimal'}
		<div id="page-footer">
			<div id="page-footer-links1">Cet Intranet a &eacute;t&eacute; r&eacute;alis&eacute; par <a href="http://www.presencesoft.com" title="Visitez le site de Pr&eacute;sence">Pr&eacute;sence</a> &copy; 2008-<?php echo strftime("%Y"); ?></div>
		</div>
		{/if}
	</div>
	
	

	{if:%var:pageMode% != 'minimal'}
	<script>
		//new Ajax.PeriodicalUpdater("messages-count","/messenger/index.php?nxo=count_unread_messages",{method:'get',frequency: 5});
	</script>
	{else}
	<div id="page-tools">
	<a href="javascript:document.location.reload();" class="s-icon si-arrow-refresh" style="position:absolute;top:10px;right:10px;padding-left: 16px;" title="{string:'refresh'}">&nbsp;</a>
	</div>
	{/if}

 </div></div>

<?php
if($device=='ipad' && $this->getProperty('iscroll_active',true)) 
{
?>
<script type="application/javascript" src="/nx/controls/iscroll/iscroll.js"></script>
<script type="text/javascript">
var theScroll;
function scroll() {
    theScroll = new iScroll('wrapper');
}
document.addEventListener('DOMContentLoaded', scroll, false);
</script>
<div style="height:500px"><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br></div>
<?php 
} 
?>

</body>
</html>
			{/if}
			