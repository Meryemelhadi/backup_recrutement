
			<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
				
		
		<?php ob_start(); ?>

			<?php 
		$workflow = $this->getProperty('workflow');
		?><?php 
		$current_operation = "edit";
		$linkText = 'title_general_infos';
		$linkText = addslashes(__($linkText));
		$backList = preg_replace('%void-[0-9]+/%','',$this->getProperty('list.url'));
		$mode_readonly = $this->getProperty('mode_readonly');
		$is_drh = $this->getProperty('is_drh');
		
	
	?>
	<?php $_nx_content_stack[]="vacancy_title";	ob_start(); ?>
		﻿{record:vacancy_title_record}{/record}

	<script type="text/javascript" language="Javascript">
//<![CDATA[

/* set current page BC */
if(window.container)
{
	window.container.bc.resetLink().addAjaxLink('{=title}','{=edit.url}&mode=ajax').addLink('{var:linkText}','');
}
document.getElementById('page_title').innerHTML = 'Poste à pourvoir: {=title} <p>{=step}</p>';

//]]>
</script>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	<?php $_nx_content_stack[]="left_column";	ob_start(); ?>
		﻿<?php 
	$current_operation = $this->getProperty('current_operation');
?><td class="directory-card-side-column left_side" id="left_column"><div class="tabbable tabs-left"><ul class="nav nav-tabs"><li class="back-btn"><a href="{var:backList}&mode=page" style="width:245px"><span class="glyphicon glyphicon-chevron-left"></span><span>{string:"back_to_vacancies"}</span></a></li><li class="<?php  if($current_operation == 'edit'){ ?>active<?php } ?>" ><a href=" {=edit.url}&mode=page"><span>{string:"title_general_infos"}</span></a></li><li class="{if:'.$current_operation.' == 'candidates'}active{/if}"><a href="{=candidates.url}&from_vac=1&mode=page"><span>{string:"title_candidates"}</span></a></li><li class="<?php  if($current_operation == 'calendar'){ ?>active<?php } ?>" ><a href="{=calendar.url}&mode=page"><span>{string:"title_calendar"}</span></a></li><li class="<?php  if($current_operation == 'recruitment_providers'){ ?>active<?php } ?>"><a href="{=feedback.url}&mode=page"><span>{string:"title_evaluation"}</span></a></li><li class="<?php  if($current_operation == 'warning'){ ?>active<?php } ?>" ><a href="{=warning.url}&mode=page"><span>{string:"title_warnings"}</span></a></li><li class="<?php  if($current_operation == 'history'){ ?>active<?php } ?>" ><a href="{=history.url}&mode=page"><span>{string:"title_history"}</span></a></li></ul></div></td>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

    
<script type="text/javascript" language="Javascript">
//<![CDATA[

		if (window.container)
			window.container.setAppTitle("");
		
//]]>
</script>
<div class="pm-page-title-wrapper">
	<div class="pm-page-title-inner-wrapper">
		<div id="page_title" class="pm-title">
			<div class="title_tb" style="float:right"></div></div></div></div><div class="pm-page-title-wrapper"><div class="pm-page-title-inner-wrapper">
		{record:vacancy_title_record}
		<div class="pm-title">
			{string:"vacancy"}: {field.html:name}{if:#field.object:code# != ''} (N° {field.html:code}){/if}
			{if:#field.object:current_step# != 0 || #field.object:progress_level# != 0}
				<br/>
				{if:#field.object:current_step# != 0} {field.label:current_step}: {field.html:current_step}, {/if}
				{if:#field.object:progress_level# != 0} {field.label:progress_level}: {field.html:progress_level}{/if}
			{/if}
		</div>
		<?php $_nx_content_stack[]="vtitle";	ob_start(); ?>{field.html:name}<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
		{/record}		
	</div></div>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

/* set current page BC */
if(window.container)
{
	window.container.bc.resetLink().addAjaxLink('{=title}','{=edit.url}&mode=ajax').addLink('{var:linkText}','');
}
document.getElementById('page_title').innerHTML = 'Poste à pourvoir: {=title} <p>{=step}</p>';

//]]>
</script>
		
		{if:%var:is_drh% == false && %var:mode_readonly% == true }
		

		<style type="text/css">
	{=app.form.css}
	#field_technical_qualifications .control-label, #field_behavioral_qualifications .control-label{
	}
	#field_companies_having_same_profile{
		margin-bottom: 24px;
	}
	#field_suited_recruitment_date{
		display:none;
	}
	#requirements_div .control-label-wrapper{
		width:35% !important;
	}
	#groups_user_total_control_1 , .control_lists_filter td, #filter_val_groups_user_total_control, #filter_val_groups_user_readonly, #groups_user_total_control_2, #groups_user_readonly_1, #groups_user_readonly_2{
		width: 170px !important;
		font-size: 11px !important;
	}
	#descriptionProfil-control-wrapper{
		margin-top:3px;
	}
	#field_companies_having_same_profile .control-label{
	}
	.mp_span{
		float: left; 
		width: 80px;
	}
	.mp_btn{
		width : 126px;
	}
	.dropdown-menu {
		right: 0px;
		left: auto !important;
	}
	.checkbox_label{
		font-size : 14px;
	}
	#group_1 .control_lists_filter td {
		position: relative;
	}
	#group_1 .control_lists_filter td select{
		top: 0;
		bottom: 0;
		position: absolute;
		height: inherit;
	}
	#groups_user_total_control-control table, #groups_user_readonly-control table{
		min-height: 250px !important;
	}
	#groups_user_total_control-control  td:nth-child(2), #groups_user_readonly-control  td:nth-child(2){
		padding-left: 70px !important;
	}
	#field_archive_state{
		display:none;
	}

		</style>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

	{=app.form.js}

//]]>
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
?><div id="help" class="help"><div class="message">{var:msgHelp}</div></div><?php 
}?>



<?php $_nx_content_stack[]="comments";	ob_start(); ?>
	<div class="pm-bxm-box-content"><div class="comments-wrapper" id="comments-wrapper">
    {records:comments.records}
        {record}
            <div class="comment-wrapper"><div class="comment"><span class="comment_author">{field:user_oid}</span>: {field:comment}</div><div class="comment_date">{field:date}</div></div>
        {/record}
    {/records}
    </div><div class="add-comment-wrapper"><div class="add-comment"><div class="add-comment-inner"><textarea rows="3" cols="30" name="add_comment_zone" type="text" class="text"></textarea></div></div><div class="add-comment-process clear-both"><a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.addComment(this, 'add_comment_zone', '{=add_comment.url}'); this.blur(); return false;"><span class="btn-bg"><span class="s-icon si-comment-add">{string:"post_comment"}</span></span></a><div style="display: none;" id="vacancy-button-loader"></div></div></div></div>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="accepted_proposals";	ob_start(); ?>
	{records:accepted_proposals.records}
		{record}
			<div class="vacancy-meta-entry"><strong>{field:full_name}</strong> {string:"date_prefix_lc"} {field:proposal_acceptance_date}</div>
		{/record}
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>



<?php $_nx_content_stack[]="selected_candidates";	ob_start(); ?>
	{records:selected_candidates.records}
	{if:records.count>0}
	<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'selected_candidates'}</h3></div>
		<div class="pm-bxm-box-content">
			<div class="table-list-wrapper">
				<table class="table-list">
			
				{record}
				
					<tr>
						<td class="entry"><strong>{field:full_name}</strong><br/>
							<script type="text/javascript" language="Javascript">
//<![CDATA[

							window.dlg_change_contrat_signingCfg{record.index} = { title:"{string:'change_contrat_signing_title'}", url: "{=change_contrat_signing.url}{record.url_key}", width:550 };

							window.dlg_change_integration_planCfg{record.index} = { title:"{string:'change_integration_plan_title'}", url: "{=change_integration_plan.url}{record.url_key}", width:550 };

							window.dlg_change_integration_noteCfg{record.index} = { title:"{string:'change_integration_note_title'}", url: "{=change_integration_note.url}{record.url_key}", width:550 };

							window.dlg_change_hire_dateCfg{record.index} = { title:"{string:'change_hire_date_title'}", url: "{=change_hire_date.url}{record.url_key}", width:550 };
						
//]]>
</script>
							<u>{field.label:contrat_signing}
							</u>: <strong>{field:contrat_signing}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_contrat_signingCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:hire_date}
							</u>: <strong>{if:#field.object:hire_date_raw#!=''}{field:hire_date}{else}{string:"empty_hire_date"}{/if}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_hire_dateCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:integration_plan}
							</u>: <strong>{field:integration_plan}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_planCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:integration_note}
							</u>: <strong>{field:integration_note}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_noteCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/></td>
					</tr>
				{/record}
		   
			
				</table></div></div>
	{/if} 
 {/records}





<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


<?php $_nx_content_stack[]="attached_files";	ob_start(); ?>
	
		<div class="comments-wrapper" id="files_wrapper">
{records:attached_files.records}

			<table class="files_wrapper">
	{record}
	
				<tr class="files_wrapper_{field:oid}">
					<td class="files_wrapper_{field:oid}" id="file_wrapper_{field.object:oid}" style="width:96%">
						<a href="{=download.url}{record.url_key}">{field.html:file_name}</a></td>
					<td class="" style="width:2%,align:right">
<input type="button" class="s-icon si-cross" href="javascript:void(0);" onclick="Generis.Recruitment.deleteFile('{field.object:oid}', '{=delete_attached_file.url}', 'file'); this.blur(); return false;" value="" style="cursor: pointer; background-color:transparent; border:solid 0px"/></td>
				</tr>
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
//<![CDATA[

		window.upload_fileConfig = { 
			exec:function() { PMModalbox.display(window.upload_fileConfig, null); },
			content_id : 'upload_file',
			title : "{string:'upload_file'}", 
			message : "{string:'upload_file_header'}", 
			viewMode : "", 
			target : "files_wrapper", 
			labels : { cancel : "{string:'dlg_cancel'}" }
		};
	
//]]>
</script>
				<button type="button" class="btn btn-default right" onclick="window.upload_fileConfig.exec(); this.blur(); return false;">
					<span class="glyphicon glyphicon-save-file" aria-hidden="true"></span>&nbsp;&nbsp;
			{string:"add_file"}
		
				</button></div></div>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="instant_feedback_count";	ob_start(); ?>
	{records:instant_feedback_count.records}
		{if:records.count > 0}
			{string:"yes"} ({records.count})
		{else}
			{string:"no"}
		{/if}
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="delayed_feedback_count";	ob_start(); ?>
	{records:delayed_feedback_count.records}
		{if:records.count > 0}
			{string:"yes"} ({records.count})
		{else}
			{string:"no"}
		{/if}		
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="offer";	ob_start(); ?>
{if: %property:use_multiposting% && %property:multiposting_url% }
	{record:multiposting.record}
	
	<fieldset id="group_15" class="field-group-bs">
		<legend class="">{string:'title_offer'}
		</legend>
		<div class="form-group-content">
			<div class="pm-bxm-box-content">
				<div class="table-list-wrapper">
					<table class="table-list">
						<tr>
							<td class="entry">{field.label:status}: <strong>{field.html:status}</strong></td>
						</tr>
						<tr>
							<td class="entry">{field.label:nbr_jobboard}: <strong>{field.html:nbr_jobboard}</strong></td>
						</tr>
						<tr>
							<td class="entry">{field.label:nbr_clics}: <strong>{field.html:nbr_clics}</strong> clic(s)</td>
						</tr>
					</table></div></div></div>
	</fieldset>
	{/record}
{/if}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="publication";	ob_start(); ?>
	
		<div class="pm-bxm-box-content">
			<div class="table-list-wrapper">
				<table class="table-list">
					<tr>
						<td class="entry">
							<span class="mp_span">{string:"publiate"}: </span>
							<a class="pm-button btn-with-icon mp_btn" href="{=multiposting_url}">
								<span class="btn-bg">
									<span class="s-icon si-arrow-right">{string:"multiposting_access_new"}</span></span></a></td>
					</tr>
				</table></div></div>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="history";	ob_start(); ?>
	 {require:css/rct.css:skin} 

<?php $_nx_content_stack[]="log";	ob_start(); ?>
	
		<style>
.log-table {
    background-color: #FFF;
    padding: 5px 20px;
    border-radius: 10px;
}

		</style>
		<div class="pm-bxm-box-content">
			{records:candidate_log.records}
			
			<div class="table-list-wrapper log-table">
				<table class="table-list">
					{record}
					
					<tr>
						<td class="entry"><strong>{field:action_oid}</strong> {field:additional_infos} {string:"date_prefix_lc"} {field:date} {string:"by"} {field:user_oid} </td>
					</tr>
					{/record}
				
				</table></div>
			{/records}
			{no_record}
			
			<div class="empty-records">{string:"empty_log_list"}</div>
			{/no_record}
		</div>
		

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="vacancy_history";	ob_start(); ?>
	
	
		<div class="pm-bxm-box-content">
		{records:vacancy_history.records}
		
			<div class="table-list-wrapper log-table">
				<table class="table-list">
				{record}
				
					<tr>
						<td class="entry"><strong>{field:progress_level}</strong> {if:trim(#field:progress_level_meta#) != ''} ({field:progress_level_meta}){/if} </td>
					</tr>
				{/record}
			
				</table></div>
		{/records}
		{no_record}
		
			<div class="empty-records">{string:"empty_vacancy_history_list"}</div>
		{/no_record}
	</div>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


		<div class="directory-card-main-content clear-both history_content">					
	{=vacancy_history}
	{=log}
</div>


<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


	<div id="content_form" class="pm-bxm-wrapper">
		{form:page.record}
		
		<script language="javascript" type="text/javascript">
//<![CDATA[

			window.autoSaveDesc = null;
			window.content_form = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
			{
				window.currentForm.handler = window.content_form_handler = new window.Generis.Forms(window.currentForm);
				// window.currentForm.className += 'form-horizontal';
			}

		
//]]>
</script>
	<?php $_nx_content_stack[]="email_field";	ob_start(); ?>
		<?php
$oid = $_nx_record->oid->object;
$channelOid = $_nx_record->cand_channel->object;
if($channelOid && $channelOid!='?')
	$suffix = str_pad($channelOid, 2, '0', STR_PAD_LEFT);
else
	$suffix='';

$code_client = $this->getProperty('recruitment.code_client');
if(!$code_client)
{
	$a = explode('.',strtolower($_SERVER['SERVER_NAME']));
	if($a[1]=='presencesoft'||$a[1]=='presencerecrute')
		// editialis.presencerecrute.com
		$code_client = $a[0];
	else
		// xx.editialis.fr
		$code_client = $a[1];
}

if($code_client)
{
	$year = '15';
	$oidpad = str_pad($oid, 3, '0', STR_PAD_LEFT);
	$check = ($year * $oid)%100;
	if($check < 10){
		$check = '0'.$check;
	}
	$email = $code_client.'_'.$year.$oidpad.$check.$suffix.'@pourcandidature.com';
}
else
	$email = '';
?>

		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:'Email du poste'} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{$email}</p>
<input type="hidden" name="email" value="{var:email}"/></div></div>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	<?php $_nx_content_stack[]="vacancy_dashboard";	ob_start(); ?>
		
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_delay_open_close"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{field.html:delay_between_open_and_close}</p></div></div>
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_delay_close_office_taking"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{field.html:delay_between_close_and_taking_office} {string:"days"}</p></div></div>
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_instant_feedback"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{=instant_feedback_count}</p></div></div>
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_delayed_feedback"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{=delayed_feedback_count}</p></div></div>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	
			<script type="text/javascript" language="Javascript">
//<![CDATA[

		window.debugme = 2;

		window.dlg_backConfig = { title : "{string:'dlg_back_title'}", message : "{string:'dlg_back_content'}", viewMode : "okCancel", url : "{=back_list.url}", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };

		window.dlg_submitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

		window.dlg_successConfig = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", target : "content", labels : { ok : "{string:'dlg_success'}" } };

		window.dlg_failureConfig = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };
		
		window.dlg_deleteConfig{record.index} = {
										title : "{string:'dlg_delete_title'}",
										message : "{string:'dlg_delete_content'}",
										viewMode : "okCancel",
										url : "{=delete.url}{record.url_key}",
										target : "content",
										labels : {
											ok : "{string:'dlg_ok'}",
											cancel : "{string:'dlg_cancel'}"
									} };
		
		window.dlg_archiveConfig{record.index} = {
                                                title : "{string:'dlg_archive_title'}",
                                                message : "{string:'dlg_archive_content'}",
                                                viewMode : "okCancel",
                                                url : "{=archive.url}{record.url_key}",
                                                target : "content",
                                                labels : {
                                                    ok : "{string:'dlg_ok'}",
                                                    cancel : "{string:'dlg_cancel'}"
                                            } };
	
//]]>
</script>
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
			{if:%property:from_home%}
			
					<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=back_to_home.url}'">
						<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back_to_home"}
			
					</button>
			{else}
			
					<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=list.url}'">
						<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back"}
			
					</button>
			{/if}
			
		</div></div>
			<script language="javascript" type="text/javascript">
//<![CDATA[

			window.taber = new window.Generis.Tabs();
		
//]]>
</script><?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','informations'));
				if($firstTab != 'informations')
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
			<li id="informations" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('informations','informations_div',null,'active')"><b>{string:'title_vacancy_fiche'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="informations_div" class="tab panel">
						<div id="panel_" class="form-panel-bs">
							<div class="">
								<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
							<div class="columns-layout-bs row">
								<div class="column-1 col-md-6">
									<div class="row">
									<fieldset id="group_1" class="field-group-bs">
										<legend class="">{string:'general_infos'}
										</legend>
										<div class="form-group-content">{get_field:name}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:name}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:name}</div></div>{get_field:code}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:code}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:code}</div></div>{get_field:vacancy_project}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:vacancy_project}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:vacancy_project}</div></div>{get_field:number}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:number}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:number}</div></div>{get_field:opening_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:opening_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:opening_date}</div></div></div>
									</fieldset>
									<fieldset id="group_2" class="field-group-bs">
										<legend class="">{string:'title_contract'}
										</legend>
										<div class="form-group-content">{get_field:contract_type_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:contract_type_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:contract_type_oid}</div></div>{get_field:category_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:category_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:category_oid}</div></div>{get_field:mission_start_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:mission_start_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:mission_start_date}</div></div>{get_field:closing_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:closing_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:closing_date}</div>
										<div class="control-help-bs help-block">Date de fermeture du poste</div></div>{get_field:suited_recruitment_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:suited_recruitment_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:suited_recruitment_date}</div></div>{get_field:taking_office_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:taking_office_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:taking_office_date}</div></div></div>
									</fieldset>
										<div id="stage_group" style="display:none">
										<fieldset id="group_1" class="field-group-bs">
											<legend class="">{string:'title_internship_section'}
											</legend>
											<div class="form-group-content">{get_field:internship_title}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:internship_title}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:internship_title}</div></div>{get_field:internship_start}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:internship_start}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:internship_start}</div></div>{get_field:internship_end}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:internship_end}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:internship_end}</div></div>{get_field:executive_committee_presentation}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:executive_committee_presentation}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:executive_committee_presentation}</div></div></div>
										</fieldset></div></div></div>
								<div class="column-1 col-md-6">
									<div class="row">
									<fieldset id="group_1" class="field-group-bs">
										<legend class="">{string:'title_manage_recruitment'}
										</legend>
										<div class="form-group-content">{get_field:manager_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:manager_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:manager_oid}</div></div>{get_field:cand_channel}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:cand_channel}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:cand_channel}</div></div>
									{=email_field}
									{get_field:current_step}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:current_step}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:current_step}</div>
										<div class="control-help-bs help-block">Les différentes états de recrutement:
<br/>
											1 - En cours
<br/>
											2 - Suspendu 
<br/>
											3 - Clôturé 
<br/>
											4 - Archivé 
<br/></div></div>{get_field:archive_state}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:archive_state}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:archive_state}</div></div></div>
									</fieldset>
									<fieldset id="group_2" class="field-group-bs">
										<legend class="">{string:'title_poste_affectation'}
										</legend>
										<div class="form-group-content">{get_field:client_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:client_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:client_oid}</div></div>{get_field:subsidiary_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:subsidiary_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:subsidiary_oid}</div></div>{get_field:establishment}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:establishment}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:establishment}</div></div>{get_field:pole}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:pole}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:pole}</div></div>{get_field:direction}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:direction}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:direction}</div></div>{get_field:service_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:service_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:service_oid}</div></div>{get_field:duty_station_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:duty_station_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:duty_station_oid}</div></div></div>
									</fieldset>
									<fieldset id="group_3" class="field-group-bs">
										<legend class="">{string:'title_salary_package'}
										</legend>
										<div class="form-group-content">{get_field:salary_min}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-double form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:salary_min}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-group-double-controls">
														<div class="form-control-bs control1" id="{field.name}-control">{field:salary_min}</div>
						{get_field:salary_max}{/get_field}
						
														<div class="form-control-bs control2" id="{field.name}-control">{field:salary_max}</div></div></div>{get_field:salary_type}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:salary_type}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:salary_type}</div></div></div>
									</fieldset>
									<fieldset id="group_4" class="field-group-bs">
										<legend class="">{string:'title_vacancy_dashboard'}
										</legend>
										<div class="form-group-content">
									{=vacancy_dashboard}
								</div>
									</fieldset>
								{=selected_candidates}
								{=offer}
								
							</div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','requirements'));
				if($firstTab != 'requirements')
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
			<li id="requirements" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('requirements','requirements_div',null,'active')"><b>{string:'title_requirements'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="requirements_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_sought_after_profile_section'}</legend><div class="form-group-content">{get_field:recruitment_reasons}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:recruitment_reasons}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:recruitment_reasons}</div></div>{get_field:suited_diplomas}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:suited_diplomas}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:suited_diplomas}</div></div>{get_field:years_of_practice}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:years_of_practice}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:years_of_practice}</div></div>{get_field:work_schedule}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:work_schedule}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:work_schedule}</div></div>{get_field:companies_having_same_profile}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:companies_having_same_profile}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:companies_having_same_profile}</div></div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'title_vacancy_requirement_section'}</legend><div class="form-group-content">{get_field:technical_qualifications}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:technical_qualifications}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:technical_qualifications}</div></div>{get_field:behavioral_qualifications}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:behavioral_qualifications}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:behavioral_qualifications}</div></div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'field:descriptionProfil'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:descriptionProfil}</div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'title_mission_definitions_section'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:mission_definitions}</div></div></fieldset><fieldset id="group_3" class="field-group-bs"><legend class="">{string:'title_mission_means_section'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:mission_means}</div></div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','attached_files'));
				if($firstTab != 'attached_files')
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
			<li id="attached_files" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('attached_files','attached_files_div',null,'active')"><b>{string:'title_files_notes'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="attached_files_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_notes'}</legend><div class="form-group-content">
									{=comments}
								</div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_associated_documents'}</legend><div class="form-group-content">
									{=attached_files}
								</div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','publication'));
				if($firstTab != 'publication')
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
			<li id="publication" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('publication','publication_div',null,'active')"><b>{string:'title_vacancy_publication'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="publication_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_publication_detail'}</legend><div class="form-group-content">{get_field:announce_date}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:announce_date}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:announce_date}</div></div>{get_field:closing_announce_date}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:closing_announce_date}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:closing_announce_date}</div></div>{get_field:application_type}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:application_type}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:application_type}</div></div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><div id="annonce_group" style="display:block"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_app_connected_section'}</legend><div class="form-group-content">{get_field:app_connected}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:app_connected}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:app_connected}</div></div></div></fieldset></div>
								{if:%property:use_multiposting%}
								<fieldset id="group_2" class="field-group-bs"><legend class="">{string:'multiposting_publication'}</legend><div class="form-group-content">
									{=publication}
								</div></fieldset>
								{/if}
							</div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','evaluation'));
				if($firstTab != 'evaluation')
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
			<li id="evaluation" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('evaluation','evaluation_div',null,'active')"><b>{string:'title_eval_criteria'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="evaluation_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_eval_criteria'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:evaluation_criteria}</div></div></fieldset></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','history'));
				if($firstTab != 'history')
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
			<li id="history" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('history','history_div',null,'active')"><b>{string:'title_history'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="history_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'vacancy_log'}</legend><div class="form-group-content">
									{=log}
								</div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'vacancy_history_title'}</legend><div class="form-group-content">
									{=vacancy_history}
								</div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	
<input type="hidden" name="tab" value="{$tab}" id="taber"/>

		{if:trim(%property:tabs_help%)}
		
			<div id="help" class="help">{=tabs_help}</div>
			<script type="text/javascript" language="Javascript">
//<![CDATA[

			var helpDiv=document.getElementById('help');
			var helpText = (helpDiv.innerText||helpDiv.textContent).replace(/\s+/,'');
			if(!helpText)
				helpDiv.style.display = 'none';
		
//]]>
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
//<![CDATA[

	if('{$tab}'!='')
		window.taber.current_menu('{$tab}','{$tab}_div',null,'active');

//]]>
</script>
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper"></div></div>
			{/form}

			
		<script language="javascript" type="text/javascript">
//<![CDATA[
			
				if(window.autoSaveDesc)
				{
					window.content_form_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			
//]]>
</script></div>


		{else}
		
		<style type="text/css">
	{=app.form.css}
	#field_technical_qualifications .control-label, #field_behavioral_qualifications .control-label{
	}
	#field_companies_having_same_profile{
		margin-bottom: 24px;
	}
	#field_suited_recruitment_date{
		display:none;
	}
	#requirements_div .control-label-wrapper{
		width:35% !important;
	}
	#groups_user_total_control_1 , .control_lists_filter td, #filter_val_groups_user_total_control, #filter_val_groups_user_readonly, #groups_user_total_control_2, #groups_user_readonly_1, #groups_user_readonly_2{
		width: 170px !important;
		font-size: 11px !important;
	}
	#descriptionProfil-control-wrapper{
		margin-top:3px;
	}
	#field_companies_having_same_profile .control-label{
	}
	.mp_span{
		float: left; 
		width: 80px;
	}
	.mp_btn{
		width : 126px;
	}
	.dropdown-menu {
		right: 0px;
		left: auto !important;
	}
	.checkbox_label{
		font-size : 14px;
	}
	#group_1 .control_lists_filter td {
		position: relative;
	}
	#group_1 .control_lists_filter td select{
		top: 0;
		bottom: 0;
		position: absolute;
		height: inherit;
	}
	#groups_user_total_control-control table, #groups_user_readonly-control table{
		min-height: 250px !important;
	}
	#groups_user_total_control-control  td:nth-child(2), #groups_user_readonly-control  td:nth-child(2){
		padding-left: 70px !important;
	}
	#field_archive_state{
		display:none;
	}

		</style>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

	{=app.form.js}

//]]>
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
?><div id="help" class="help"><div class="message">{var:msgHelp}</div></div><?php 
}?>



<?php $_nx_content_stack[]="comments";	ob_start(); ?>
	<div class="pm-bxm-box-content"><div class="comments-wrapper" id="comments-wrapper">
    {records:comments.records}
        {record}
            <div class="comment-wrapper"><div class="comment"><span class="comment_author">{field:user_oid}</span>: {field:comment}</div><div class="comment_date">{field:date}</div></div>
        {/record}
    {/records}
    </div><div class="add-comment-wrapper"><div class="add-comment"><div class="add-comment-inner"><textarea rows="3" cols="30" name="add_comment_zone" type="text" class="text"></textarea></div></div><div class="add-comment-process clear-both"><a class="pm-button btn-with-icon" href="javascript:void(0);" onclick="Generis.Recruitment.addComment(this, 'add_comment_zone', '{=add_comment.url}'); this.blur(); return false;"><span class="btn-bg"><span class="s-icon si-comment-add">{string:"post_comment"}</span></span></a><div style="display: none;" id="vacancy-button-loader"></div></div></div></div>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="accepted_proposals";	ob_start(); ?>
	{records:accepted_proposals.records}
		{record}
			<div class="vacancy-meta-entry"><strong>{field:full_name}</strong> {string:"date_prefix_lc"} {field:proposal_acceptance_date}</div>
		{/record}
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>



<?php $_nx_content_stack[]="selected_candidates";	ob_start(); ?>
	{records:selected_candidates.records}
	{if:records.count>0}
	<div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'selected_candidates'}</h3></div>
		<div class="pm-bxm-box-content">
			<div class="table-list-wrapper">
				<table class="table-list">
			
				{record}
				
					<tr>
						<td class="entry"><strong>{field:full_name}</strong><br/>
							<script type="text/javascript" language="Javascript">
//<![CDATA[

							window.dlg_change_contrat_signingCfg{record.index} = { title:"{string:'change_contrat_signing_title'}", url: "{=change_contrat_signing.url}{record.url_key}", width:550 };

							window.dlg_change_integration_planCfg{record.index} = { title:"{string:'change_integration_plan_title'}", url: "{=change_integration_plan.url}{record.url_key}", width:550 };

							window.dlg_change_integration_noteCfg{record.index} = { title:"{string:'change_integration_note_title'}", url: "{=change_integration_note.url}{record.url_key}", width:550 };

							window.dlg_change_hire_dateCfg{record.index} = { title:"{string:'change_hire_date_title'}", url: "{=change_hire_date.url}{record.url_key}", width:550 };
						
//]]>
</script>
							<u>{field.label:contrat_signing}
							</u>: <strong>{field:contrat_signing}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_contrat_signingCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:hire_date}
							</u>: <strong>{if:#field.object:hire_date_raw#!=''}{field:hire_date}{else}{string:"empty_hire_date"}{/if}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_hire_dateCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:integration_plan}
							</u>: <strong>{field:integration_plan}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_planCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/>
							<u>{field.label:integration_note}
							</u>: <strong>{field:integration_note}</strong> (
							<a onclick="PMModalbox.loadFromUrl(window.dlg_change_integration_noteCfg{record.index}, event); return false;" href="javascript:void(0);">
								<span>{string:"change_data"}</span></a>)
						
<br/></td>
					</tr>
				{/record}
		   
			
				</table></div></div>
	{/if} 
 {/records}





<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="buttons";	ob_start(); ?>


		<div class="btn-group button_bs_right" role="group">
			<button type="button" class="btn btn-default dropdown-toggle right" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
				<span class="glyphicon glyphicon-menu-hamburger"></span>
	&nbsp;{string:"actions_vacancy"}
			</button>
			<ul class="dropdown-menu">
				<li>
					<a onclick="document.location.href='{=candidates.url}&from_vac=1&mode=page'">
						<span class="fa fa-users"></span>&nbsp;&nbsp;{string:"title_candidates"}</a>
				</li>
				<li>
					<a onclick="document.location.href='{=calendar.url}&mode=page'">
						<span class="glyphicon glyphicon-calendar" aria-hidden="true"></span>&nbsp;&nbsp;{string:"title_calendar"}</a>
				</li>
		{if: %property:use_multiposting% && %property:multiposting_url% }
		
				<li>
					<a href="{=multiposting_url}">
						<span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>&nbsp;&nbsp;{string:"multiposting_access"}</a>
				</li>
		{/if}
		
				<li>
					<a onclick="PMModalbox.display(dlg_deleteConfig{record.index}, event);">
						<span class="glyphicon glyphicon-remove-circle" aria-hidden="true"></span>&nbsp;&nbsp;{string:"dlg_delete_definitly"}</a>
				</li>
				<li>
					<a onclick="PMModalbox.display(dlg_archiveConfig{record.index}, event);">
						<span class="glyphicon glyphicon-th-large" aria-hidden="true"></span>&nbsp;&nbsp;{string:"archive_helper"}</a>
				</li>
				<li>
					<a href="{=candidate_add.url}">
						<span class="glyphicon glyphicon-plus" aria-hidden="true"></span>&nbsp;&nbsp;Ajouter Candidat</a>
				</li>
			</ul></div>
		<button type="button" class="btn btn-default submit_marge" onclick="PMFormSubmit.submit(this, dlg_submitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;">
			<span class="glyphicon glyphicon-floppy-save" aria-hidden="true"></span>&nbsp;&nbsp;
	{string:"submit"} 
		</button>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="attached_files";	ob_start(); ?>
	
		<div class="comments-wrapper" id="files_wrapper">
{records:attached_files.records}

			<table class="files_wrapper">
	{record}
	
				<tr class="files_wrapper_{field:oid}">
					<td class="files_wrapper_{field:oid}" id="file_wrapper_{field.object:oid}" style="width:96%">
						<a href="{=download.url}{record.url_key}">{field.html:file_name}</a></td>
					<td class="" style="width:2%,align:right">
<input type="button" class="s-icon si-cross" href="javascript:void(0);" onclick="Generis.Recruitment.deleteFile('{field.object:oid}', '{=delete_attached_file.url}', 'file'); this.blur(); return false;" value="" style="cursor: pointer; background-color:transparent; border:solid 0px"/></td>
				</tr>
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
//<![CDATA[

		window.upload_fileConfig = { 
			exec:function() { PMModalbox.display(window.upload_fileConfig, null); },
			content_id : 'upload_file',
			title : "{string:'upload_file'}", 
			message : "{string:'upload_file_header'}", 
			viewMode : "", 
			target : "files_wrapper", 
			labels : { cancel : "{string:'dlg_cancel'}" }
		};
	
//]]>
</script>
				<button type="button" class="btn btn-default right" onclick="window.upload_fileConfig.exec(); this.blur(); return false;">
					<span class="glyphicon glyphicon-save-file" aria-hidden="true"></span>&nbsp;&nbsp;
			{string:"add_file"}
		
				</button></div></div>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="instant_feedback_count";	ob_start(); ?>
	{records:instant_feedback_count.records}
		{if:records.count > 0}
			{string:"yes"} ({records.count})
		{else}
			{string:"no"}
		{/if}
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="delayed_feedback_count";	ob_start(); ?>
	{records:delayed_feedback_count.records}
		{if:records.count > 0}
			{string:"yes"} ({records.count})
		{else}
			{string:"no"}
		{/if}		
	{/records}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="offer";	ob_start(); ?>
{if: %property:use_multiposting% && %property:multiposting_url% }
	{record:multiposting.record}
	
	<fieldset id="group_37" class="field-group-bs">
		<legend class="">{string:'title_offer'}
		</legend>
		<div class="form-group-content">
			<div class="pm-bxm-box-content">
				<div class="table-list-wrapper">
					<table class="table-list">
						<tr>
							<td class="entry">{field.label:status}: <strong>{field.html:status}</strong></td>
						</tr>
						<tr>
							<td class="entry">{field.label:nbr_jobboard}: <strong>{field.html:nbr_jobboard}</strong></td>
						</tr>
						<tr>
							<td class="entry">{field.label:nbr_clics}: <strong>{field.html:nbr_clics}</strong> clic(s)</td>
						</tr>
					</table></div></div></div>
	</fieldset>
	{/record}
{/if}
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="publication";	ob_start(); ?>
	
		<div class="pm-bxm-box-content">
			<div class="table-list-wrapper">
				<table class="table-list">
					<tr>
						<td class="entry">
							<span class="mp_span">{string:"publiate"}: </span>
							<a class="pm-button btn-with-icon mp_btn" href="{=multiposting_url}">
								<span class="btn-bg">
									<span class="s-icon si-arrow-right">{string:"multiposting_access_new"}</span></span></a></td>
					</tr>
				</table></div></div>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="history";	ob_start(); ?>
	 {require:css/rct.css:skin} 

<?php $_nx_content_stack[]="log";	ob_start(); ?>
	
		<style>
.log-table {
    background-color: #FFF;
    padding: 5px 20px;
    border-radius: 10px;
}

		</style>
		<div class="pm-bxm-box-content">
			{records:candidate_log.records}
			
			<div class="table-list-wrapper log-table">
				<table class="table-list">
					{record}
					
					<tr>
						<td class="entry"><strong>{field:action_oid}</strong> {field:additional_infos} {string:"date_prefix_lc"} {field:date} {string:"by"} {field:user_oid} </td>
					</tr>
					{/record}
				
				</table></div>
			{/records}
			{no_record}
			
			<div class="empty-records">{string:"empty_log_list"}</div>
			{/no_record}
		</div>
		

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

<?php $_nx_content_stack[]="vacancy_history";	ob_start(); ?>
	
	
		<div class="pm-bxm-box-content">
		{records:vacancy_history.records}
		
			<div class="table-list-wrapper log-table">
				<table class="table-list">
				{record}
				
					<tr>
						<td class="entry"><strong>{field:progress_level}</strong> {if:trim(#field:progress_level_meta#) != ''} ({field:progress_level_meta}){/if} </td>
					</tr>
				{/record}
			
				</table></div>
		{/records}
		{no_record}
		
			<div class="empty-records">{string:"empty_vacancy_history_list"}</div>
		{/no_record}
	</div>

<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


		<div class="directory-card-main-content clear-both history_content">					
	{=vacancy_history}
	{=log}
</div>


<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
<?php $_nx_content_stack[]="upload_file";	ob_start(); ?>
    
		<div id="upload_file" style="display:none">
			<div class="ged_miniform ged_add_files">
<br/>
<br/>
				<form id="" method="post" action="{=add_attached_files.url}" enctype="multipart/form-data">
<input type="hidden" value="100000000" name="MAX_FILE_SIZE"/>
<input type="hidden" value="POST" name="_form_method_"/>
<input type="file" name="file_name" id="file_name" value="" class="form-control"/>
<br/>
<br/>
					<button class="btn btn-default right">{string:'add file'}
					</button>
					<button type="button" class="btn btn-default button_back right marginRight" onclick="PMModalbox.hide(); this.blur(); return false;">
						<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp; {string:"cancel"} 
			
					</button>
				</form>
<br/>
<br/></div></div>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


	<div id="content_form" class="pm-bxm-wrapper">
		{form:page.record}
		
		<script language="javascript" type="text/javascript">
//<![CDATA[

			window.autoSaveDesc = null;
			window.content_form = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
			{
				window.currentForm.handler = window.content_form_handler = new window.Generis.Forms(window.currentForm);
				// window.currentForm.className += 'form-horizontal';
			}

		
//]]>
</script>
	<?php $_nx_content_stack[]="email_field";	ob_start(); ?>
		<?php
$oid = $_nx_record->oid->object;
$channelOid = $_nx_record->cand_channel->object;
if($channelOid && $channelOid!='?')
	$suffix = str_pad($channelOid, 2, '0', STR_PAD_LEFT);
else
	$suffix='';

$code_client = $this->getProperty('recruitment.code_client');
if(!$code_client)
{
	$a = explode('.',strtolower($_SERVER['SERVER_NAME']));
	if($a[1]=='presencesoft'||$a[1]=='presencerecrute')
		// editialis.presencerecrute.com
		$code_client = $a[0];
	else
		// xx.editialis.fr
		$code_client = $a[1];
}

if($code_client)
{
	$year = '15';
	$oidpad = str_pad($oid, 3, '0', STR_PAD_LEFT);
	$check = ($year * $oid)%100;
	if($check < 10){
		$check = '0'.$check;
	}
	$email = $code_client.'_'.$year.$oidpad.$check.$suffix.'@pourcandidature.com';
}
else
	$email = '';
?>

		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:'Email du poste'} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{$email}</p>
<input type="hidden" name="email" value="{var:email}"/></div></div>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	<?php $_nx_content_stack[]="vacancy_dashboard";	ob_start(); ?>
		
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_delay_open_close"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{field.html:delay_between_open_and_close}</p></div></div>
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_delay_close_office_taking"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{field.html:delay_between_close_and_taking_office} {string:"days"}</p></div></div>
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_instant_feedback"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{=instant_feedback_count}</p></div></div>
		<div class="form-group form-group-bs {if:field.is_last} last_field{/if}">
			<div class="control-label-wrapper-bs">
				<label class="control-label-bs control-label">{string:"title_delayed_feedback"} :
				</label></div>
			<div class="form-control-bs">
					<p class="form-control-static">{=delayed_feedback_count}</p></div></div>
	<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
	
			<script type="text/javascript" language="Javascript">
//<![CDATA[

		window.debugme = 2;

		window.dlg_backConfig = { title : "{string:'dlg_back_title'}", message : "{string:'dlg_back_content'}", viewMode : "okCancel", url : "{=back_list.url}", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };

		window.dlg_submitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

		window.dlg_successConfig = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", target : "content", labels : { ok : "{string:'dlg_success'}" } };

		window.dlg_failureConfig = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };
		
		window.dlg_deleteConfig{record.index} = {
										title : "{string:'dlg_delete_title'}",
										message : "{string:'dlg_delete_vacancy_content'}",
										viewMode : "okCancel",
										url : "{=delete.url}{record.url_key}",
										target : "content",
										labels : {
											ok : "{string:'dlg_ok'}",
											cancel : "{string:'dlg_cancel'}"
									} };
		
		window.dlg_archiveConfig{record.index} = {
                                                title : "{string:'dlg_archive_title'}",
                                                message : "{string:'dlg_archive_content'}",
                                                viewMode : "okCancel",
                                                url : "{=archive.url}{record.url_key}",
                                                target : "content",
                                                labels : {
                                                    ok : "{string:'dlg_ok'}",
                                                    cancel : "{string:'dlg_cancel'}"
                                            } };
	
//]]>
</script>
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
			{if:%property:from_home%}
			
					<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=back_to_home.url}'">
						<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back_to_home"}
			
					</button>
			{else}
			
					<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=list.url}'">
						<span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back"}
			
					</button>
			{/if}
			{=buttons}
		</div></div>
			<script language="javascript" type="text/javascript">
//<![CDATA[

			window.taber = new window.Generis.Tabs();
		
//]]>
</script><?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','informations'));
				if($firstTab != 'informations')
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
			<li id="informations" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('informations','informations_div',null,'active')"><b>{string:'title_vacancy_fiche'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="informations_div" class="tab panel">
						<div id="panel_" class="form-panel-bs">
							<div class="">
								<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
							<div class="columns-layout-bs row">
								<div class="column-1 col-md-6">
									<div class="row">
									<fieldset id="group_1" class="field-group-bs">
										<legend class="">{string:'general_infos'}
										</legend>
										<div class="form-group-content">{get_field:name}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:name}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:name}</div></div>{get_field:code}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:code}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:code}</div></div>{get_field:vacancy_project}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:vacancy_project}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:vacancy_project}</div></div>{get_field:number}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:number}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:number}</div></div>{get_field:opening_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:opening_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:opening_date}</div></div></div>
									</fieldset>
									<fieldset id="group_2" class="field-group-bs">
										<legend class="">{string:'title_contract'}
										</legend>
										<div class="form-group-content">{get_field:contract_type_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:contract_type_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:contract_type_oid}</div></div>{get_field:category_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:category_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:category_oid}</div></div>{get_field:mission_start_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:mission_start_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:mission_start_date}</div></div>{get_field:closing_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:closing_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:closing_date}</div>
										<div class="control-help-bs help-block">Date de fermeture du poste</div></div>{get_field:suited_recruitment_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:suited_recruitment_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:suited_recruitment_date}</div></div>{get_field:taking_office_date}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:taking_office_date}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:taking_office_date}</div></div></div>
									</fieldset>
										<div id="stage_group" style="display:none">
										<fieldset id="group_1" class="field-group-bs">
											<legend class="">{string:'title_internship_section'}
											</legend>
											<div class="form-group-content">{get_field:internship_title}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:internship_title}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:internship_title}</div></div>{get_field:internship_start}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:internship_start}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:internship_start}</div></div>{get_field:internship_end}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:internship_end}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:internship_end}</div></div>{get_field:executive_committee_presentation}{/get_field}
											<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
															<div class="control-label-wrapper-bs">
																<label for="{field.name}" class="control-label-bs control-label">{field.label:executive_committee_presentation}{if:field.isRequired}
												<span class="required-field">*</span>{/if} :
																</label></div>
														<div class="form-control-bs" id="{field.name}-control">{field:executive_committee_presentation}</div></div></div>
										</fieldset></div></div></div>
								<div class="column-1 col-md-6">
									<div class="row">
									<fieldset id="group_1" class="field-group-bs">
										<legend class="">{string:'title_manage_recruitment'}
										</legend>
										<div class="form-group-content">{get_field:manager_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:manager_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:manager_oid}</div></div>{get_field:cand_channel}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:cand_channel}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:cand_channel}</div></div>
									{=email_field}
									{get_field:current_step}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:current_step}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:current_step}</div>
										<div class="control-help-bs help-block">Les différentes états de recrutement:
<br/>
											1 - En cours
<br/>
											2 - Suspendu 
<br/>
											3 - Clôturé 
<br/>
											4 - Archivé 
<br/></div></div>{get_field:type_ao}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:type_ao}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:type_ao}</div></div>{get_field:sector_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:sector_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:sector_oid}</div></div>{get_field:vacancy_success}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:vacancy_success}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:vacancy_success}</div></div>{get_field:archive_state}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:archive_state}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:archive_state}</div></div></div>
									</fieldset>
									<fieldset id="group_2" class="field-group-bs">
										<legend class="">{string:'title_poste_affectation'}
										</legend>
										<div class="form-group-content">{get_field:client_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:client_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:client_oid}</div></div>{get_field:subsidiary_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:subsidiary_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:subsidiary_oid}</div></div>{get_field:establishment}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:establishment}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:establishment}</div></div>{get_field:pole}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:pole}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:pole}</div></div>{get_field:direction}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:direction}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:direction}</div></div>{get_field:service_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:service_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:service_oid}</div></div>{get_field:duty_station_oid}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:duty_station_oid}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:duty_station_oid}</div></div></div>
									</fieldset>
									<fieldset id="group_3" class="field-group-bs">
										<legend class="">{string:'title_salary_package'}
										</legend>
										<div class="form-group-content">{get_field:salary_min}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-double form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:salary_min}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-group-double-controls">
														<div class="form-control-bs control1" id="{field.name}-control">{field:salary_min}</div>
						{get_field:salary_max}{/get_field}
						
														<div class="form-control-bs control2" id="{field.name}-control">{field:salary_max}</div></div></div>{get_field:salary_type}{/get_field}
										<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
														<div class="control-label-wrapper-bs">
															<label for="{field.name}" class="control-label-bs control-label">{field.label:salary_type}{if:field.isRequired}
											<span class="required-field">*</span>{/if} :
															</label></div>
													<div class="form-control-bs" id="{field.name}-control">{field:salary_type}</div></div></div>
									</fieldset>
								{=selected_candidates}
								{=offer}
								
							</div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','requirements'));
				if($firstTab != 'requirements')
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
			<li id="requirements" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('requirements','requirements_div',null,'active')"><b>{string:'title_requirements'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="requirements_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_sought_after_profile_section'}</legend><div class="form-group-content">{get_field:recruitment_reasons}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:recruitment_reasons}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:recruitment_reasons}</div></div>{get_field:suited_diplomas}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:suited_diplomas}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:suited_diplomas}</div></div>{get_field:years_of_practice}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:years_of_practice}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:years_of_practice}</div></div>{get_field:work_schedule}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:work_schedule}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:work_schedule}</div></div>{get_field:companies_having_same_profile}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:companies_having_same_profile}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:companies_having_same_profile}</div></div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'title_vacancy_requirement_section'}</legend><div class="form-group-content">{get_field:technical_qualifications}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:technical_qualifications}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:technical_qualifications}</div></div>{get_field:behavioral_qualifications}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:behavioral_qualifications}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:behavioral_qualifications}</div></div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_organisme_definitions_section'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:organisme_definitions}</div></div></fieldset><fieldset id="group_2" class="field-group-bs"><legend class="">{string:'title_mission_definitions_section'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:mission_definitions}</div></div></fieldset><fieldset id="group_3" class="field-group-bs"><legend class="">{string:'field:descriptionProfil'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:descriptionProfil}</div></div></fieldset><fieldset id="group_4" class="field-group-bs"><legend class="">{string:'title_mission_means_section'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:mission_means}</div></div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','publication'));
				if($firstTab != 'publication')
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
			<li id="publication" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('publication','publication_div',null,'active')"><b>{string:'title_vacancy_publication'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="publication_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_publication_detail'}</legend><div class="form-group-content">{get_field:announce_date}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:announce_date}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:announce_date}</div></div>{get_field:closing_announce_date}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:closing_announce_date}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:closing_announce_date}</div></div></div></fieldset><div id="ref_jobboard" style="display:block"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_offer'}</legend><div class="form-group-content"><span class="glyphicon glyphicon-info-sign" aria-hidden="true" style="float: right;font-size: 18px;color: rgba(45, 148, 197, 0.82);" title="Si vous ne pouvez pas utiliser l'adresse du poste sur votre annonce , renseignez la référence des sources ci-dessous. "></span><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:offers_list}</div></div></fieldset></div></div></div><div class="column-1 col-md-6"><div class="row"><div id="annonce_group" style="display:block"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_app_connected_section'}</legend><div class="form-group-content">{get_field:app_connected}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:app_connected}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:app_connected}</div></div></div></fieldset></div>
								{if:%property:use_multiposting%}
								<fieldset id="group_2" class="field-group-bs"><legend class="">{string:'multiposting_publication'}</legend><div class="form-group-content">
									{=publication}
								</div></fieldset>
								{/if}
							</div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','permission'));
				if($firstTab != 'permission')
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
			<li id="permission" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('permission','permission_div',null,'active')"><b>{string:'permissions'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="permission_div" class="tab panel">
<?php
	$user = &$GLOBALS['_NX_user'];
	$userOid = $user->getProperty('oid');
	if($_nx_record->creator->object != $userOid && $_nx_record->manager_oid->object != $userOid && !$user->checkPerm('?-drh'))
	{
		$_nx_record->groups_user_total_control->setProperty('isEdit',false);
		$_nx_record->groups_user_readonly->setProperty('isEdit',false);
	}
?>

				<div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'total_control'}</legend><div class="form-group-content">{get_field:creator}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:creator}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:creator}</div></div>{get_field:rh_oid}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:rh_oid}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:rh_oid}</div></div>{get_field:groups_user_total_control}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{string:'total_control'} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:groups_user_total_control}</div></div></div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_readonly'}</legend><div class="form-group-content">{get_field:groups_user_readonly}{/get_field}<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{string:'readOnly'} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:groups_user_readonly}</div></div></div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','evaluation'));
				if($firstTab != 'evaluation')
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
			<li id="evaluation" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('evaluation','evaluation_div',null,'active')"><b>{string:'title_eval_criteria'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="evaluation_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_eval_criteria'}</legend><div class="form-group-content"><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:evaluation_criteria}</div></div></fieldset></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','history'));
				if($firstTab != 'history')
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
			<li id="history" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('history','history_div',null,'active')"><b>{string:'title_history'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="history_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'vacancy_log'}</legend><div class="form-group-content">
									{=log}
								</div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'vacancy_history_title'}</legend><div class="form-group-content">
									{=vacancy_history}
								</div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','attached_files'));
				if($firstTab != 'attached_files')
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
			<li id="attached_files" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('attached_files','attached_files_div',null,'active')"><b>{string:'title_files_notes'}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="attached_files_div" class="tab panel"><div id="panel_" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><div class="columns-layout-bs row"><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_notes'}</legend><div class="form-group-content">
									{=comments}
								</div></fieldset></div></div><div class="column-1 col-md-6"><div class="row"><fieldset id="group_1" class="field-group-bs"><legend class="">{string:'title_associated_documents'}</legend><div class="form-group-content">
									{=attached_files}
								</div></fieldset></div></div></div></div></div></div></div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	
<input type="hidden" name="tab" value="{$tab}" id="taber"/>

		{if:trim(%property:tabs_help%)}
		
			<div id="help" class="help">{=tabs_help}</div>
			<script type="text/javascript" language="Javascript">
//<![CDATA[

			var helpDiv=document.getElementById('help');
			var helpText = (helpDiv.innerText||helpDiv.textContent).replace(/\s+/,'');
			if(!helpText)
				helpDiv.style.display = 'none';
		
//]]>
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
//<![CDATA[

	if('{$tab}'!='')
		window.taber.current_menu('{$tab}','{$tab}_div',null,'active');

//]]>
</script>
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
			{=buttons}
		</div></div>
			{/form}

			
		<script language="javascript" type="text/javascript">
//<![CDATA[
			
				if(window.autoSaveDesc)
				{
					window.content_form_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			
//]]>
</script></div>

{=upload_file}


		<script type="text/javascript" language="Javascript">
//<![CDATA[

	window.ajax_load('/nx/skins/default/js/recruitment/form_vacancy.js','form_vacancy_js');

//]]>
</script>
		{/if}
	

	

    <?php 	
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
	<link rel="icon" href="/nx/skins/default/img/favicon.ico" />

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
{if: #const:SMARTLOOK_ID#}
	<script type="text/javascript">
	   function msieversion()
	   {
		  var ua = window.navigator.userAgent
		  var msie = ua.indexOf ( "MSIE " )

		  if ( msie > 0)      // If Internet Explorer, return version number
			 return parseInt (ua.substring (msie+5, ua.indexOf (".", msie )))
		  else                 // If another browser, return 0
			 return 0
	   }

		
		window.smartlook||(function(d) {
		var o=smartlook=function(){ o.api.push(arguments)},h=d.getElementsByTagName('head')[0];
		var c=d.createElement('script');o.api=new Array();c.async=true;c.type='text/javascript';
		c.charset='utf-8';c.src='//rec.smartlook.com/recorder.js';h.appendChild(c);
		})(document);
		smartlook('init', '{const:SMARTLOOK_ID}');
		smartlook('tag', 'name', '{user:user.userID}');
		var msie=msieversion(); 
		if(msie > 0)
			smartlook('tag', 'IE', msie);
	</script>
{/if}

{if: #const:CHAT_ID#}
<!-- Smartsupp Live Chat script -->
<script type="text/javascript">
var _smartsupp = _smartsupp || {};
_smartsupp.key = '{const:CHAT_ID}';
window.smartsupp||(function(d) {
	var s,c,o=smartsupp=function(){ o._.push(arguments)};o._=[];
	s=d.getElementsByTagName('script')[0];c=d.createElement('script');
	c.type='text/javascript';c.charset='utf-8';c.async=true;
	c.src='//www.smartsuppchat.com/loader.js?';s.parentNode.insertBefore(c,s);
})(document);
</script>
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

<?php 
if(($iframe = isset($_GET["ifram"]) && $_GET["ifram"])=='1') 
{
?>
<style>
	div.pm-title {padding: 0px 0px 0px;}
	#content {margin-top: 0 !important;}
	#outer-content-wrapper {padding: 0 14px 14px 14px; border-top:0;background: none transparent;}
</style>
<?php
}
?>


<link href="/nx/controls/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css"  media="all" />
<link href="/nx/controls/font-awesome/css/font-awesome-bs.min.css" rel="stylesheet" type="text/css"  media="all" />



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
			<div id="page-footer-links1">R&eacute;alisation par <a href="http://www.presencesoft.com" title="Visitez le site de Pr&eacute;sence">Pr&eacute;sence</a> &copy; 2008-<?php echo strftime("%Y"); ?></div>
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

<script type="application/javascript" src="/nx/controls/ajax/jquery-3.0.0.min.js"></script>
<script type="text/javascript">$.noConflict();</script>
<script type="application/javascript" src="/nx/controls/bootstrap/js/bootstrap.min.js"></script>

</body>
</html>
			{/if}
			