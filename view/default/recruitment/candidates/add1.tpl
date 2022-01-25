
			<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
				
		
		<?php ob_start(); ?>

			<?php 
		$workflow = $this->getProperty('workflow');

	?>
	<script language="javascript" type="text/javascript">
//<![CDATA[


        window.dlg_backConfig = { title : "{string:'dlg_back_title'}", message : "{string:'dlg_back_content'}", viewMode : "okCancel", url : "?nxo=list", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };

        window.dlg_waitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

        window.dlg_successConfig = { skipConfirm: true, title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", url : "{=edit.url}", evalConfig : true, target : "content", labels : { ok : "{string:'dlg_success'}" } };

        window.dlg_failureConfig = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };


    
//]]>
</script>
<script type="text/javascript" language="Javascript">
//<![CDATA[

		if (window.container)
			window.container.setAppTitle("<table><tr><td>  <?php echo $logo; ?> </td><td>  <?php echo $title; ?> </td></tr></table>");
		
//]]>
</script>
<div class="pm-page-title-wrapper">
	<div class="pm-page-title-inner-wrapper">
		<div id="page_title" class="pm-title">
<table>
	<tr>
		<td>  <?php echo $logo; ?> </td>
		<td>  <?php echo $title; ?> </td>
	</tr>
</table>
			<div class="title_tb" style="float:right"></div></div></div></div>
		<style>
            {=app.form.css}

        
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
	<div id="form1" class="pm-bxm-wrapper">
		{form:page.record}
		
		<script language="javascript" type="text/javascript">
//<![CDATA[

			window.autoSaveDesc = null;
			window.form1 = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
				window.currentForm.handler = window.form1_handler = new window.Generis.Forms(window.currentForm);
		
//]]>
</script>
		<table class="pm-bxm">
			<tr><td class="pm-bxm-main-column"><div class="form-actions-wrapper"><div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper"><a class="pm-button" href="{=back.url}{=filterKey}"><span class="btn-bg"><span class="s-icon si-application-side-contract">{string:"back"}</span></span></a><span class="pm-button-sep"></span>
					<script type="text/javascript" language="Javascript">
//<![CDATA[
 
	window.ajax_submit_method = null; 
	window.ajax_submit_mode = null; 

//]]>
</script><?php 

$autosave_url='';
$autosave_timeout=2000;

$actions=$this->getProperty('actions');
$index=-1;
if(!isset($zone))
	$zone='';

if(!isset($state))
	$state=$workflow->getState();

foreach($actions as $actionId=>$action)
{
	if(isset($op['zone']) && $op['zone']!=$zone)
		continue;

	if(isset($action['name']))
		$title = __($action['name']);
	else
		$title = __($actionId);

	$iconCls = $action['iconCls'];

	$index++;
	$actionUID = 'action_'.$index;

	$type='submit';
/*
	if($actionId=='submit')
		$type='submit';
	else
		$type = 'ajax';
*/

/*	if(isset($action['url']))
	{
		$url=$action['url'];
		if(!preg_match('/\?/',$url))
			$url.='?';
	}
	else
		$url='?';
*/

	$url='';
	if(isset($action['dirkey']))
	{
		$fkey = isset($action['field-key'])?$action['field-key']:'oid';
		$url=$action['dirkey'].'-'.$_nx_record->$fkey->object.'/'.$url;
	}

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

	// op
	if(isset($action['nxo']))
	{
		$url.='nxo='.$action['nxo'];
		// action
		if(isset($action['action']))
			$url.='&action='.$action['action'];
	}
	else
	{
		if(isset($action['confirm']) && $action['confirm'])
			$type='ajax';
		else
			$type='submit';

		$url=$this->getProperty('action.url','?nxo=action');

		// action
		if(isset($action['action']))
			$url.='&action='.$action['action'];
		else
			$url.='&action='.$actionId;
	}
	
	// link type
	if(isset($action['type']))
		$type = $action['type'];

	// target or ajax id
	$target='';$id='';
	if(isset($action['target']))
	{
		$type = 'link';
		$target = $action['target'];
	}
	elseif (isset($action['id']))
	{
		$type = 'ajax';
		$id = $action['id'];
		$target = '';
	}

	if($type == 'ajax'&& !$id)
		$id = 'content';

	if($type == 'ajax')
		$url .='&amp;mode=ajax';

	// parameters
	if(isset($_REQUEST['filterKey']))
	{
		$filterKeyUrl = '&amp;filterKey='.urlencode($_REQUEST['filterKey']);
		$url.=$filterKeyUrl;
	}

	if(isset($action['params']))
		$url.=$action['params'];

	if(isset($action['key']) && $action['key']===true)
		$url.=$_nx_record->getUrlKey();

	// init auto save url and timeout
	if($type=='auto_save')
	{
		$autosave_url=$url;

		if(isset($action['autosave_timeout']))
			$autosave_timeout=1000*$action['autosave_timeout'];
		else
			$autosave_timeout=2000;
	}

	//HTML class && id
	$html_class = '';
	$html_id = '';

	if(isset($action['html_id']))
	{
		$html_id = $action['html_id'];
	}
	if(isset($action['html_class']))
	{
		$html_class = $action['html_class'];
	}

	// auth
	if(isset($action['auth']))
	{
		require_once(NX_LIB."login/NxLogin_key.inc");
		$login=new NxLogin_key($_NX_site);
		$url.=$login->getCurrentParamKey(true);
	}

	$dialog = isset($action['dialog']['nxo']) || (isset($action['dialog']['ds']) || isset($action['dialog']['url'])) ? $action['dialog'] : null;
	if($dialog)
	{
		//		$urlDialog = $action['dialog']['url'];

		// get URL for loading the dialog
		if(!isset($action['dialog']['nxo']))
			$action['dialog']['nxo']='load_action_form';

		$urlDialog = '?nxo='.$action['dialog']['nxo'];
		if(isset($workflow->record))
		{
			if($workflow->record->oid->object)
				$urlDialog .= '&oid='.$workflow->record->oid->object;
		}
		
		// ID of the descriptor that will be used by the dialog
		$dialogID = 'action_'.$index.'_Config';

		// url of action to be called by current form
		$actionIdUrl = urlencode($actionId);

		// store current state (used to check that the action is not triggered twice)
		$stateUrl=urlencode($state);

?>
					<script type="text/javascript" language="Javascript">
//<![CDATA[

			window.{$dialogID} = 
			{ 
				exec:function() 
				{
					// check data and open dialog with dates
					if(window.form1.onsubmit(window.form1,'{$actionId}'))
						PMModalbox.loadFromUrl(window.{$dialogID}, null);
				},

				// dialog params : used by MB for opening the dialog
				title : "{$title}",
				url: '{var:urlDialog}&dialogId={$actionIdUrl}&for_state={$stateUrl}&submitDesc={$dialogID}',			
				message : "{string:'enter parameters'}", 
				viewMode : "cancel", 
				target : "content", 
				width : 600,
				height:500,
				labels : { cancel : "{string:'dlg_cancel'}" },

				// this form params : used by the dialogue for submitting the form if user clicks on ok in dialog
				form:window.form1,
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
		
//]]>
</script>
					<a href="javascript:window.{$dialogID}.exec();" class="pm-button btn-with-icon {var:html_class}" id="{var:html_id}">
						<span class="btn-bg">
							<span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	else

	if(isset($action['confirm']) && $action['confirm'])
	
	{
		if(!$id)
			$id = 'content';

?>
					<script type="text/javascript" language="Javascript">
//<![CDATA[

			window.dlg_{var:actionUID}Config{record.index} = { title : "{string:'dlg_delete_title'}", message : "{string:'dlg_delete_content'}", viewMode : "okCancel", url : "{var:url}{record.url_key}&mode=ajax", target : "{var:id}", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };
		
//]]>
</script>
					<span class="pm-button-sep"></span>
					<a class="pm-button btn-with-icon" href="javascript:void(0);" title="{$title}" onclick="PMModalbox.display(window.dlg_{var:actionUID}Config{record.index}, event);return false;">
						<span class="btn-bg">
							<span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	elseif($type=='submit')
	{
		if($url)
			$setUrl="if(window.form1.onsubmit(window.form1,'".$actionId."')){window.form1.action='".$url."';window.form1.submit();}";
		else
		{
			$url=$this->getProperty('submit.url');
			$setUrl="if(window.form1.onsubmit(window.form1,'".$actionId."')){window.form1.submit();}";
		}
?><span class="pm-button-sep"></span><a class="pm-button {var:html_class}" href="{var:url}" onclick="{$setUrl}this.blur(); return false;" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	elseif($type == 'ajax_check')
	{
		if(!$id)
			$id = 'content';
?>
					<script type="text/javascript" language="Javascript">
//<![CDATA[

		window.dlg_waitConfig_{$actionUID} = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait", url:"{var:url}" };

		window.dlg_successConfig_{$actionUID} = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", urlX: "{=back.url}&mode=ajax", targetX : "{var:id}", labels : { ok : "{string:'dlg_success'}" } };

		window.dlg_failureConfig_{$actionUID} = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };
	
//]]>
</script>
					<span class="pm-button-sep"></span>
					<a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="PMFormSubmit.submit(this, dlg_waitConfig_{$actionUID}, dlg_successConfig_{$actionUID}, dlg_failureConfig_{$actionUID}); this.blur(); return false;" id="{var:html_id}">
						<span class="btn-bg">
							<span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	elseif($type == 'ajax')
	{
		if(!$id)
			$id = 'content';
		
		if($actionId=='back')
		{
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="ajax_navigate(event,'{var:url}','{var:id}'); this.blur(); return false;" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
		else
		{
			// si on est dans un dialogue, il faut un patch pour le CK editor
			// $start = "if(typeof CKEDITOR != 'undefined') for (p in CKEDITOR.instances){CKEDITOR.instances[p].updateElement();};";
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="ajax_submit(event,this,'{var:id}','{var:url}'); this.blur();return false;" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
	}
	elseif($type == 'link')
	{
		if($target)
		{
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" target="{var:target}" href="{var:url}{record.url_key}&mode=page" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
		else
		{
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" href="{var:url}{record.url_key}&mode=page" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
	}
	elseif($type='auto_save')
	{
?>
					<script language="javascript" type="text/javascript">
//<![CDATA[

		window.autoSaveDesc = 
		{
			url:'{$autosave_url}', 
			
			timeout:{$autosave_timeout},

			autosaveIndicator : {
				reset : function() {
				},

				saving : function() {

					var indicator = $('save_state');
					if(indicator) {
						indicator.className = 'saving';
					}
				},

				saved : function() {
					var indicator = $('save_state');
					if(indicator) {
						indicator.className = 'saved';
					}
				}
			}
		}
	
//]]>
</script><?php 
	}
}
?></div></div><div id="panel_title-green" class="pm-bxm-box-wrapper"><div class="pm-bxm-box"><div class="box-title-wrapper box-title-red"><div class="box-title"><h3>{string:'general_infos'}</h3></div></div><div class="pm-bxm-box-content"><div class="columns-layout clear-both"><div class="column-1"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'profile_infos'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:first_name}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:first_name}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:first_name}</div></div></div>{get_field:last_name}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:last_name}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:last_name}</div></div></div>{get_field:civility}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:civility}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:civility}</div></div></div>{get_field:gender}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:gender}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:gender}</div></div></div>{get_field:date_of_birth}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:date_of_birth}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:date_of_birth}</div></div></div>{get_field:nationality}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:nationality}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:nationality}</div></div></div></div></div></div><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'candidate_infos'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:studies_level}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:studies_level}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:studies_level}</div></div></div></div></div></div></div><div class="column-1"><div class="section-title-wrapper"><h3 class="section-title inline-block">{string:'coordinates'}</h3></div><div class="pm-bx-form"><div class="record_wrapper"><div class="record">{get_field:email}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:email}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:email}</div></div></div>{get_field:mobile}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:mobile}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:mobile}</div></div></div>{get_field:phone_1}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:phone_1}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:phone_1}</div></div></div>{get_field:phone_2}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:phone_2}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:phone_2}</div></div></div>{get_field:zip}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:zip}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:zip}</div></div></div>{get_field:country_oid}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:country_oid}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:country_oid}</div></div></div>{get_field:town_oid}{/get_field}<div id="field_{field.name}" class="control-main-wrapper {if:field.is_last} last_field{/if}"><div class="control-label-wrapper"><div class="control-label">{field.label:town_oid}{if:field.isRequired}<span class="required-field">*</span>{/if} :</div></div><div class="control-wrapper" id="{field.name}-control-wrapper"><div class="control" id="{field.name}-control">{field:town_oid}</div></div></div></div></div></div></div></div></div></div></div><div class="form-actions-wrapper"><div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper"><a class="pm-button" href="{=back.url}"><span class="btn-bg"><span class="s-icon si-application-side-contract">{string:"back"}</span></span></a><span class="pm-button-sep"></span>
					<script type="text/javascript" language="Javascript">
//<![CDATA[
 
	window.ajax_submit_method = null; 
	window.ajax_submit_mode = null; 

//]]>
</script><?php 

$autosave_url='';
$autosave_timeout=2000;

$actions=$this->getProperty('actions');
$index=-1;
if(!isset($zone))
	$zone='';

if(!isset($state))
	$state=$workflow->getState();

foreach($actions as $actionId=>$action)
{
	if(isset($op['zone']) && $op['zone']!=$zone)
		continue;

	if(isset($action['name']))
		$title = __($action['name']);
	else
		$title = __($actionId);

	$iconCls = $action['iconCls'];

	$index++;
	$actionUID = 'action_'.$index;

	$type='submit';
/*
	if($actionId=='submit')
		$type='submit';
	else
		$type = 'ajax';
*/

/*	if(isset($action['url']))
	{
		$url=$action['url'];
		if(!preg_match('/\?/',$url))
			$url.='?';
	}
	else
		$url='?';
*/

	$url='';
	if(isset($action['dirkey']))
	{
		$fkey = isset($action['field-key'])?$action['field-key']:'oid';
		$url=$action['dirkey'].'-'.$_nx_record->$fkey->object.'/'.$url;
	}

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

	// op
	if(isset($action['nxo']))
	{
		$url.='nxo='.$action['nxo'];
		// action
		if(isset($action['action']))
			$url.='&action='.$action['action'];
	}
	else
	{
		if(isset($action['confirm']) && $action['confirm'])
			$type='ajax';
		else
			$type='submit';

		$url=$this->getProperty('action.url','?nxo=action');

		// action
		if(isset($action['action']))
			$url.='&action='.$action['action'];
		else
			$url.='&action='.$actionId;
	}
	
	// link type
	if(isset($action['type']))
		$type = $action['type'];

	// target or ajax id
	$target='';$id='';
	if(isset($action['target']))
	{
		$type = 'link';
		$target = $action['target'];
	}
	elseif (isset($action['id']))
	{
		$type = 'ajax';
		$id = $action['id'];
		$target = '';
	}

	if($type == 'ajax'&& !$id)
		$id = 'content';

	if($type == 'ajax')
		$url .='&amp;mode=ajax';

	// parameters
	if(isset($_REQUEST['filterKey']))
	{
		$filterKeyUrl = '&amp;filterKey='.urlencode($_REQUEST['filterKey']);
		$url.=$filterKeyUrl;
	}

	if(isset($action['params']))
		$url.=$action['params'];

	if(isset($action['key']) && $action['key']===true)
		$url.=$_nx_record->getUrlKey();

	// init auto save url and timeout
	if($type=='auto_save')
	{
		$autosave_url=$url;

		if(isset($action['autosave_timeout']))
			$autosave_timeout=1000*$action['autosave_timeout'];
		else
			$autosave_timeout=2000;
	}

	//HTML class && id
	$html_class = '';
	$html_id = '';

	if(isset($action['html_id']))
	{
		$html_id = $action['html_id'];
	}
	if(isset($action['html_class']))
	{
		$html_class = $action['html_class'];
	}

	// auth
	if(isset($action['auth']))
	{
		require_once(NX_LIB."login/NxLogin_key.inc");
		$login=new NxLogin_key($_NX_site);
		$url.=$login->getCurrentParamKey(true);
	}

	$dialog = isset($action['dialog']['nxo']) || (isset($action['dialog']['ds']) || isset($action['dialog']['url'])) ? $action['dialog'] : null;
	if($dialog)
	{
		//		$urlDialog = $action['dialog']['url'];

		// get URL for loading the dialog
		if(!isset($action['dialog']['nxo']))
			$action['dialog']['nxo']='load_action_form';

		$urlDialog = '?nxo='.$action['dialog']['nxo'];
		if(isset($workflow->record))
		{
			if($workflow->record->oid->object)
				$urlDialog .= '&oid='.$workflow->record->oid->object;
		}
		
		// ID of the descriptor that will be used by the dialog
		$dialogID = 'action_'.$index.'_Config';

		// url of action to be called by current form
		$actionIdUrl = urlencode($actionId);

		// store current state (used to check that the action is not triggered twice)
		$stateUrl=urlencode($state);

?>
					<script type="text/javascript" language="Javascript">
//<![CDATA[

			window.{$dialogID} = 
			{ 
				exec:function() 
				{
					// check data and open dialog with dates
					if(window.form1.onsubmit(window.form1,'{$actionId}'))
						PMModalbox.loadFromUrl(window.{$dialogID}, null);
				},

				// dialog params : used by MB for opening the dialog
				title : "{$title}",
				url: '{var:urlDialog}&dialogId={$actionIdUrl}&for_state={$stateUrl}&submitDesc={$dialogID}',			
				message : "{string:'enter parameters'}", 
				viewMode : "cancel", 
				target : "content", 
				width : 600,
				height:500,
				labels : { cancel : "{string:'dlg_cancel'}" },

				// this form params : used by the dialogue for submitting the form if user clicks on ok in dialog
				form:window.form1,
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
		
//]]>
</script>
					<a href="javascript:window.{$dialogID}.exec();" class="pm-button btn-with-icon {var:html_class}" id="{var:html_id}">
						<span class="btn-bg">
							<span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	else

	if(isset($action['confirm']) && $action['confirm'])
	
	{
		if(!$id)
			$id = 'content';

?>
					<script type="text/javascript" language="Javascript">
//<![CDATA[

			window.dlg_{var:actionUID}Config{record.index} = { title : "{string:'dlg_delete_title'}", message : "{string:'dlg_delete_content'}", viewMode : "okCancel", url : "{var:url}{record.url_key}&mode=ajax", target : "{var:id}", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };
		
//]]>
</script>
					<span class="pm-button-sep"></span>
					<a class="pm-button btn-with-icon" href="javascript:void(0);" title="{$title}" onclick="PMModalbox.display(window.dlg_{var:actionUID}Config{record.index}, event);return false;">
						<span class="btn-bg">
							<span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	elseif($type=='submit')
	{
		if($url)
			$setUrl="if(window.form1.onsubmit(window.form1,'".$actionId."')){window.form1.action='".$url."';window.form1.submit();}";
		else
		{
			$url=$this->getProperty('submit.url');
			$setUrl="if(window.form1.onsubmit(window.form1,'".$actionId."')){window.form1.submit();}";
		}
?><span class="pm-button-sep"></span><a class="pm-button {var:html_class}" href="{var:url}" onclick="{$setUrl}this.blur(); return false;" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	elseif($type == 'ajax_check')
	{
		if(!$id)
			$id = 'content';
?>
					<script type="text/javascript" language="Javascript">
//<![CDATA[

		window.dlg_waitConfig_{$actionUID} = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait", url:"{var:url}" };

		window.dlg_successConfig_{$actionUID} = { title : "{string:'dlg_success_title'}", message : "{string:'dlg_success_content'}", viewMode : "ok", urlX: "{=back.url}&mode=ajax", targetX : "{var:id}", labels : { ok : "{string:'dlg_success'}" } };

		window.dlg_failureConfig_{$actionUID} = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };
	
//]]>
</script>
					<span class="pm-button-sep"></span>
					<a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="PMFormSubmit.submit(this, dlg_waitConfig_{$actionUID}, dlg_successConfig_{$actionUID}, dlg_failureConfig_{$actionUID}); this.blur(); return false;" id="{var:html_id}">
						<span class="btn-bg">
							<span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
	}
	elseif($type == 'ajax')
	{
		if(!$id)
			$id = 'content';
		
		if($actionId=='back')
		{
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="ajax_navigate(event,'{var:url}','{var:id}'); this.blur(); return false;" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
		else
		{
			// si on est dans un dialogue, il faut un patch pour le CK editor
			// $start = "if(typeof CKEDITOR != 'undefined') for (p in CKEDITOR.instances){CKEDITOR.instances[p].updateElement();};";
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="ajax_submit(event,this,'{var:id}','{var:url}'); this.blur();return false;" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
	}
	elseif($type == 'link')
	{
		if($target)
		{
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" target="{var:target}" href="{var:url}{record.url_key}&mode=page" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
		else
		{
?><span class="pm-button-sep"></span><a class="pm-button btn-with-icon {var:html_class}" href="{var:url}{record.url_key}&mode=page" id="{var:html_id}"><span class="btn-bg"><span class="s-icon {$iconCls}">{var:title}</span></span></a><?php 
		}
	}
	elseif($type='auto_save')
	{
?>
					<script language="javascript" type="text/javascript">
//<![CDATA[

		window.autoSaveDesc = 
		{
			url:'{$autosave_url}', 
			
			timeout:{$autosave_timeout},

			autosaveIndicator : {
				reset : function() {
				},

				saving : function() {

					var indicator = $('save_state');
					if(indicator) {
						indicator.className = 'saving';
					}
				},

				saved : function() {
					var indicator = $('save_state');
					if(indicator) {
						indicator.className = 'saved';
					}
				}
			}
		}
	
//]]>
</script><?php 
	}
}
?></div></div></td>
			</tr>
		</table>			
			{/form}

			
		<script language="javascript" type="text/javascript">
//<![CDATA[
			
				if(window.autoSaveDesc)
				{
					window.form1_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			
//]]>
</script></div><?php 	
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
	{require:css/page.css:skin}
	{require:js/page.js:skin}
		
	{if:%var:pageMode% == 'minimal'}
	<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/minimal.css" media="screen" />
	{/if}
	
	<link rel="stylesheet" type="text/css" href="/nx/skins/lightsky/css/rct_print.css" media="print" />
	
{if:%var:pageMode% != 'minimal'}
	<script language="JavaScript" type="text/javascript" src="/nav/nav_def.php?suid={get:suid|0}&section=fdv&amp;delegate={request:delegate}"></script>

<?php 
class PageThemeParams {	function __get($k) {return '';} }
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
		$this->title = '<span>Espace</span><br>'.$this->space->title->object;

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
		if($space->logo->path)
			$this->logo->url = $space->logo->url;

		$this->logo->name = 'Logo';

		// menu
		$this->topMenu=new PageThemeParams;
		if( trim($_SERVER['site_informations']['_banner_menu']) != "")
		{
			$banMenuURL = (trim($_SERVER['site_informations']['_banner_menu']) == "")?"":$_SERVER['site_informations']['_banner_menu'];
			$this->topMenu->style = <<<EOH
.navTop li .leftOnglet,.navTop li .onglet,ul#main-navigation li.nav-item a.nav-link span,ul#main-navigation li.nav-item a.nav-link em,
ul#main-navigation li.nav-item a.nav-link.hovered span, ul#main-navigation li.nav-item a.nav-link:hover span,
ul#main-navigation li.active-nav-item a.nav-link span, ul#main-navigation li.active-nav-item a.nav-link em {
	background-image:url($banMenuURL);
}
EOH;
		}
	}
}

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
					document.write(container.nav.displayMenu());
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
					var curMenu = container.bc.displayMenu();
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
			