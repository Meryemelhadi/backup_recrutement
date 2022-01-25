
			<?php $_nx_content_stack[]="page.content";	ob_start(); ?>
				
		
		<?php ob_start(); ?>

			<?php 
		$workflow = $this->getProperty('workflow');
		$state = $workflow->getState();
		$title = __($workflow->model->getMeta('title','',$state));
	?>
<script type="text/javascript" language="Javascript">
//<![CDATA[

		if (window.container)
			window.container.setAppTitle("{var:title}");
		
//]]>
</script>
<div class="pm-page-title-wrapper">
	<div class="pm-page-title-inner-wrapper">
		<div id="page_title" class="pm-title">{var:title}
			<div class="title_tb" style="float:right"></div></div></div></div><style>
			{=app.form.css}
		</style>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

			{=app.form.js}
		
//]]>
</script><?php 
			$is_admin=true;
		?><?php 

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
}?><?php 

if(!defined('NX_SELECT_REFRESH'))
	define('NX_SELECT_REFRESH',true);

class GenericForm extends NxProperties
{
	function GenericForm($_nx_record,$ctxt,$form=null,$parent=null,$isForm=true)
	{
		$this->record = $_nx_record;
		$this->ctxt = $ctxt;
		$this->form = $form;
		$this->parent = $parent;

		$this->initFieldList($_nx_record);

		if($isForm)
			$this->formMethod = 'toForm';
		else
			$this->formMethod = 'toHTML';
	}

	function initFieldList($record) {
		$this->fields = array();
		$fields = $this->record->recDesc->fields;
		foreach($fields as $fname=>$desc)
		{
			$this->fields[$fname]=false;
		}
	}

	// check if fields will be missing in form...
	function hideMissingFields()
	{
		$fields = $this->record->recDesc->fields;
		foreach($fields as $fname=>$fdesc)
		{
			// not displayed by this class, and not hidden
			if(!$this->fields[$fname] && !$fdesc->isHidden())
			{
				/* should be displayed, but not in application form desc 
				=> set as hidden so that it appears at the end of the form as hidden field.
				Otherwise, the missing value will erase the record in DB 
				*/
				$this->record->$fname->setProperty('show',false);
				echo $this->record->$fname->toForm();
			}
		}
	}

	/* for setting fields in edit/no edit, show/hide, required
		@param fieldDescs : array('no_edit'=>'f1,f2','show=>'*'') 
		@param workflow : workflow or application object
	*/
	function setFieldsProperty($fieldDescs,$workflow)
	{
		$record = $this->record;

		foreach($fieldDescs as $action => $fnames)
		{
			if($action == 'no_edit')
				$workflow->setFieldsProperty($fnames,'isEdit', false,$record);
			elseif($action == 'edit')
				$workflow->setFieldsProperty($fnames,'isEdit',true,$record);
			elseif($action == 'hide')
				$workflow->setFieldsProperty($fnames,'show',false,$record);
			elseif($action == 'show')
				$workflow->setFieldsProperty($fnames,'show',true,$record);
			elseif($action == 'required')
				$workflow->setFieldsProperty($fnames,'isRequired',true,$record);
		}

	}

	function main($formDesc)
	{ 
		?>
	<script language="javascript" type="text/javascript">
//<![CDATA[

			window.taber = new window.Generis.Tabs();
		
//]]>
</script><?php 
			if(!$formDesc) {
				return;
			}
	
			if(isset($formDesc['tabs']))
			{
				if(count($formDesc['tabs'])<=1)
					$tabHandler = 'tabContent';
				else
					$tabHandler = 'tab';

				foreach($formDesc['tabs'] as $tabN=>$tab)
				{
					$this->$tabHandler($tabN,$tab);
				}
			}

			if(isset($formDesc['panels']))
			foreach($formDesc['panels'] as $idPanel => $panel)
			{
				$this->panel($idPanel,$panel);
			}

			if(isset($formDesc['panel']))
				$this->panel('main_panel',$formDesc['panel']);

			if(isset($formDesc['fields']))
			foreach($formDesc['fields'] as $k => $fname)
			{
				$this->field($k,$fname);
			}

		?>
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
</script><?php 

		if(isset($formDesc['missing fields']) && $formDesc['missing fields'])
			$this->hideMissingFields();
	}

	function tab($tabN,$tab) 
	{
		?>
		<?php $_nx_content_stack[]="_tab_content_";	ob_start(); ?>
			<?php 
			
			$this->tabContent($tabN,$tab);

			?>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
		<?php 

		$tabContent = trim($this->getProperty('_tab_content_',''));
		if(!$tabContent)
			return;

		global $firstTab;

		if(isset($tab['title']))
			$title = __($tab['title']);
		elseif(!is_numeric($tabN))
			//$title = '';
			$title = __($tabN);

		$tabN2 = preg_replace('/[^a-z0-9]/i','_',$tabN);

		if(isset($tab['help']))
			$help = __($tab['help']);
		else
			$help = '';

		?><?php 
			global $firstTab;

			if(!isset($firstTab)||!$firstTab)
			{
				// reverse tpl macro to get tab id in php
				$firstTab = trim(preg_replace('/[<][?]php|[?][>]|echo|;|[$]/','','{var:tabN2}'));
				if($firstTab != '{var:tabN2}')
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
			<div style="{var:displayMode}" id="{var:tabN2}_help" class="tab-help">{var:help}</div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_nav";	ob_start(); ?>
			{=tabs_nav}
			<li id="{var:tabN2}" class="{var:classNav}"><a href="javascript:void(0);" onclick="window.taber.current_menu('{var:tabN2}','{var:tabN2}_div',null,'active')"><b>{var:title}</b></a></li>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

		<?php $_nx_content_stack[]="tabs_src";	ob_start(); ?>
			{=tabs_src}
			<div style="{var:displayMode}" id="{var:tabN2}_div" class="tab panel">
			{var:tabContent}
		</div>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

	<?php 
	}

	function tabContent($tabN,$tab) 
	{
		if(isset($tab['panels']))
		{
			foreach($tab['panels'] as $idPanel => $panel)
			{
				$this->panel($idPanel,$panel);
			}
		}
		elseif(isset($tab['columns']) || isset($tab['property']))
		{
			if(isset($tab['title']))
			{
				$title = __($tab['title']);
				$color = isset($tab['color']) ? $tab['color'] : 'red';
				$cls = 'box-title-'.$color;

				?><div id="panel_" class="form-panel-bs"><div class=""><div class="box-title-wrapper {var:cls}"><div class="box-title"><h3>{var:title}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><?php 

					$this->panelContent($tabN,$tab);

					?></div></div></div><?php 
			}
			else 
			{
				?><div id="panel_{var:idPanel}" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-"><?php 

					$this->panelContent($tabN,$tab);

					?></div></div></div><?php 
			}
		}
		else
		{
			$this->panel($tabN,$tab);
		}
	}

	function panel($idPanel,$panel) 
	{
		?>
		<?php $_nx_content_stack[]="_panel_";	ob_start(); ?>
			<?php 
			
			$this->panelContent($idPanel,$panel);

			?>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
		<?php 
		$panelContent = trim($this->getProperty('_panel_',''));
		if(!$panelContent)
			return;

		if(isset($panel['title']))
		{
			$title = __($panel['title']);
			$color = isset($panel['color']) ? $panel['color'] : 'red';
			$cls = 'box-title-'.$color;

			?><div id="panel_{var:idPanel}" class="form-panel-bs"><div class=""><div class="box-title-wrapper {var:cls}"><div class="box-title"><h3>{var:title}</h3></div></div><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
				{var:panelContent}
			</div></div></div><?php 
		}
		else {
			?><div id="panel_{var:idPanel}" class="form-panel-bs"><div class=""><div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
				{var:panelContent}
			</div></div></div><?php 
		}
	}

	function panelContent($idPanel,$panel) 
	{
		if(isset($panel['columns']))
		{
			$columns = $panel['columns'];
			if(count($columns)>1) 
			{
			?><div class="columns-layout-bs row"><?php 
				$coli = 0;
				foreach($columns as $i=>$column)
				{
					$this->column($coli,$column);
					$coli++;
				}
			?></div><?php 
			}
			else
			{
				$column = reset($columns);
				foreach($column as $k=>$item)
					$panel[$k] = $item;
			}
		}
		if(isset($panel['groups']))
		foreach($panel['groups'] as $group)
		{
			$this->group($group);
		}
		if(isset($panel['fields']))
		foreach($panel['fields'] as $k=>$fname)
		{
			$this->field($k,$fname);
		}
		if(isset($panel['property']))
		{
			echo $this->ctxt->getProperty($panel['property']);
		}
	}

	function column($i, $column) 
	{
		if($i==='1'||$i===0)
			$colCls = 'column-1';
		elseif($i==='2'||$i===1)
			$colCls = 'column-2';
		else
			$colCls = '';

		?><div class="{var:colCls} col-md-6"><div class="row"><?php 
		if(isset($column['groups']))
		foreach($column['groups'] as $group)
		{
			$this->group($group);
		}
		if(isset($column['fields']))
		foreach($column['fields'] as $k=>$fname)
		{
			$this->field($k,$fname);
		}
		if(isset($column['property']))
		{
			echo $this->ctxt->getProperty($column['property']);
		}

		?></div></div><?php 
	}

	function group($group) 
	{
		$_nx_record = $this->record;
		$title = __($group['title']);

		?>
		<?php $_nx_content_stack[]="_fields_";	ob_start(); ?>
		<?php 
		if(isset($group['fields']))
		foreach($group['fields'] as $k=>$fname)
		{
			$this->field($k,$fname);
		}
		if(isset($group['property']))
		{
			echo $this->ctxt->getProperty($group['property']);
		}
		?>
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>
		{if: trim(%property:_fields_%)}
		<fieldset id="group_30" class="field-group-bs"><legend class="">{var:title}</legend><div class="form-group-content">
			{=_fields_}
		</div></fieldset>
		{/if}
		<?php 
	}

	function field($k,$fname) 
	{
		$_nx_record = $this->record;
		$fmethod = $this->formMethod;
		if(in_array($fname,array('no_label','no label','class','property')))
		{
			// inverser key et fname
			$k2 = $fname;
			$fname = $k;
			$k = $k2;
		}

		if((string)$k=='no_label' || (string)$k=='no label')
		{
			$_nx_field = $_nx_record->$fname;
			$this->fields[$fname]=true;

		?><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:}</div><?php 
		}
		elseif((string)$k=='class')
		{
		?>

			{fields}
			<?php 
				if($_nx_field->desc->getProperty('class') == $fname)
				{
					$this->fields[$_nx_field->desc->name]=true;

					if($_nx_field->desc->type == 'records')
					{
				?><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:}</div><?php 
					}
					else
					{
				?><div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:}</div></div><?php 
					}
				}
				?>

			{/fields}
		
		<?php 
		}
		elseif((string)$fname=='*')
		{
		?>

			{fields}<?php 
				
				$this->fields[$_nx_field->desc->name]=true;
				?><div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:}</div></div><?php ?>

			{/fields}
		
		<?php 
		}
		elseif((string)$k=='attachment')
		{
			echo $this->getProperty($fname);
			echo $this->getProperty('_attachements_');
?>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

				if(typeof multiAttachementFileManager != "undefined"){
				multiAttachementFileManager( "<?php echo $this->form['name']; ?>" , '{field.name:file_attachement}' ,'{=lang|fr}' );
				}
			
//]]>
</script><?php 												
		}
		elseif((string)$k=='property')
		{
			echo $this->ctxt->getProperty($fname);													
		}
		elseif((string)$k=='preview')
		{
			if($url = $_nx_record->$fname->toString('url'))
			{
?><iframe src="{var:url}" width="100%" height="800" frameborder="0" marginwidth="0" marginheight="0" align="top" hspace="0" vspace="0" scrolling="0"></iframe><?php 												
			}
		}
		elseif((string)$k=='photo')
		{
?>	
			{if:#field.object:photo# == ''}
			
				{if:#field.object:civility# == 'MR'}
				<div class="dg-cell-wrapper"><img src="/nx/skins/lightsky/img/user_male.png"/></div>
				{/if}
				{if:#field.object:civility# == 'MME' || #field.object:civility# == 'MLLE'}
				<div class="dg-cell-wrapper"><img src="/nx/skins/lightsky/img/user_female.png"/></div>
				{/if}
				{if:#field.object:civility# == '' || #field.object:civility# == ''}
				<div class="dg-cell-wrapper"><img src="/nx/skins/lightsky/img/unknown_user.png"/></div>
				{/if}

			{else}																		
				{field.html:photo}
			{/if}
<?php 
			$this->fields['photo']=true;
		}

		else
		{
			$_nx_field = $_nx_record->$fname;
			$this->fields[$fname]=true;
			if($_nx_field && !$_nx_field->isHidden())
			{
				if($_nx_field->desc->type == 'records')
				{
		?><div id="field_{field.name}" class="form-control-bs {if:field.is_last} last_field{/if}">{field:}</div><?php 
				}
				else
				{
		?><div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}"><div class="control-label-wrapper-bs"><label for="{field.name}" class="control-label-bs control-label">{field.label:}{if:field.isRequired}<span class="required-field">*</span>{/if} :</label></div><div class="form-control-bs" id="{field.name}-control">{field:}</div></div><?php 
				}
			}
		}
	}
}

?>


		<?php $_nx_content_stack[]="_attachements_";	ob_start(); ?>
			 {records:page.record_attachements} 
			{if:records.count>0}
			<div class="control-main-wrapper"><div class="attached-files-label">
				{string:'attached_files_title_dissociation'} :
				</div><div><div class="control" id="{field.name}-control">
						 {record} 
						<div class="attached-file-control-wrapper"><input type="checkbox" name="delete_file_attachement[]" value="{get_field:oid}{field}{/get_field}"/>
							{get_field:file_name}{field}{/get_field}
						</div>
						 {/record} 
					</div></div></div>
			{/if}
			 {/records} 
		<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>


		
	<div id="form1" class="pm-bxm-wrapper">
		{form:page.record}
		
		<script language="javascript" type="text/javascript">
//<![CDATA[

			window.autoSaveDesc = null;
			window.form1 = document.getElementById('{=submit.id}');
			window.currentForm = document.getElementById('{=submit.id}');
			if(window.currentForm)
			{
				window.currentForm.handler = window.form1_handler = new window.Generis.Forms(window.currentForm);
				// window.currentForm.className += 'form-horizontal';
			}

		
//]]>
</script><div class="form-actions-wrapper"><div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
					<script type="text/javascript" language="Javascript">
//<![CDATA[
 
	window.ajax_submit_method = null; 
	window.ajax_submit_mode = null; 

//]]>
</script><?php 
$autosave_url='';
$autosave_timeout=2000;
$form_list = true;

$actions=$this->getProperty('actions');
if(sizeof($actions) == 1){
	$form_list = false;
}
?><style>
.dropdown-menu{
	left:inherit !important;
	right:0;
}
</style><?php 
		if($form_list){
	?><div class="btn-group button_bs_right" role="group"><button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false"><span class="glyphicon glyphicon-menu-hamburger"></span>
		&nbsp;{string:"actions"}</button><ul class="dropdown-menu"><?php 
		}
	?><?php 
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
	{
		$url.=$action['url'];
		if(preg_match('%[{]property:([^}]+)[}]%',$url,$matches))
		{
			$url=$this->getProperty($matches[1]);
		}
	}
	else
	{
		if($url)
			$url.=basename($_SERVER['PHP_SELF']);
	}

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
	elseif(!isset($action['url']))
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

	$html_style='';
	if(isset($action['html_style']))
	{
		$html_style .= $action['html_style'];
	}
	if(isset($action['position']))
	{
		$html_style .= ';float:'.$action['position'];
	}
	if($html_style)
		$html_style=' style="'.$html_style.'"';

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
							<a href="javascript:window.{$dialogID}.exec();" class="pm-button btn-with-icon {var:html_class}" id="{var:html_id}" {var:html_style}="">
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
							<li>
								<a onclick="PMModalbox.display(window.dlg_{var:actionUID}Config{record.index}, event);return false;">
									<span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;{var:title}</a>
							</li><?php 
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
?><?php 
	if($form_list){
?><li><a href="{var:url}" onclick="{$setUrl}this.blur(); return false;"><span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;{var:title}</a></li><?php 
	}else{
?><button type="button" class="btn btn-default right" onclick="{$setUrl}this.blur(); return false;" id="{var:html_id}"><span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;
{var:title}
</button><?php 
	}
?><?php 
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
							<a class="pm-button btn-with-icon {var:html_class}" href="javascript:void(0);" onclick="PMFormSubmit.submit(this, dlg_waitConfig_{$actionUID}, dlg_successConfig_{$actionUID}, dlg_failureConfig_{$actionUID}); this.blur(); return false;" id="{var:html_id}" {var:html_style}="">
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
?><?php 
		if($form_list){
	?><li><a href="javascript:void(0);" onclick="ajax_submit(event,this,'{var:id}','{var:url}'); this.blur();return false;"><span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;{var:title}</a></li><?php 
		}else{
	?><button type="button" class="btn btn-default right" onclick="ajax_submit(event,this,'{var:id}','{var:url}'); this.blur();return false;" id="{var:html_id}"><span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;
		{var:title}
	</button><?php 
		}
	?><?php 
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
?><?php 
				if($form_list){
			?><li><a onclick="PMFormSubmit.submit(this, dlg_waitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;"><span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;{var:title}</a></li><?php 
				}else{
			?><button type="button" class="btn btn-default right" onclick="PMFormSubmit.submit(this, dlg_waitConfig, dlg_successConfig, dlg_failureConfig); this.blur(); return false;" id="{var:html_id}"><span class="glyphicon glyphicon-{$iconCls}" aria-hidden="true"></span>&nbsp;&nbsp;
			 {var:title}
			 </button><?php 
				}
			?><?php 
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
?><?php 
	if($form_list){
?></ul></div><?php 
	}
?></div></div><?php 

				$formDesc = $workflow->model->getFormDesc($this->getProperty('form.desc','record'));

				$f = new GenericForm($_nx_record,$workflow->ctxt,$form,$this);
				$f->main($formDesc);

				?>
			{/form}

			
		<script language="javascript" type="text/javascript">
//<![CDATA[
			
				if(window.autoSaveDesc)
				{
					window.form1_handler.initAutoSave(window.autoSaveDesc.url,window.autoSaveDesc.timeout,window.autoSaveDesc.autosaveIndicator);
				}
			
//]]>
</script></div>
		<script type="text/javascript" language="Javascript">
//<![CDATA[

	// Generis.Recruitment.appendAssocFilesHandlers('assoc-files-control');
	Generis.Recruitment.emailSampleHandler({
		fieldname: 'default_email', 
		element: 'field_email_title',
		emailTitleField: 'email_title',
		emailContentField:'email_content',
		url: '?nxo=emails:get_email_sample'});


//]]>
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
			