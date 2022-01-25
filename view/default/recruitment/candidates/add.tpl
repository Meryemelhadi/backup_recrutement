
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
			window.container.setAppTitle("
              {string:"page_title_add_candidate"}
        ");
		
//]]>
</script>
<div class="pm-page-title-wrapper">
	<div class="pm-page-title-inner-wrapper">
		<div id="page_title" class="pm-title">
              {string:"page_title_add_candidate"}
        
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

		<?php $_nx_content_stack[]="buttons";	ob_start(); ?>
            <span class="pm-button-sep"></span>
			{if:%property:from% == 'home'}
				<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=back_to_home.url}{=filterKey}'"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back_to_home"}
			</button>
			{elseif:%property:from% == 'vacancy'}
			<button type="button" class="btn btn-default button_back" onclick="document.location.href='{=back_to_vacancy.url}{=filterKey}'"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back_to_vacancy"}
			</button>
			{else}
			<button type="button" class="btn btn-default button_back green" onclick="document.location.href='{=back.url}{=filterKey}'"><span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"back"}
			</button>
			{/if}
			<span class="pm-button-sep"></span><button type="button" class="btn btn-default button_margin right" onclick="PMFormSubmit.submit(this, dlg_submitContinueConfig, null, dlg_failureConfig); this.blur(); return false;"><span class="glyphicon glyphicon-floppy-save" aria-hidden="true"></span>&nbsp;&nbsp;
				{string:"save"}
			</button>
			
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
			<script type="text/javascript" language="Javascript">
//<![CDATA[

                window.dlg_submitConfig = { title : "{string:'dlg_wait_title'}", message : "{string:'dlg_wait_content'}", viewMode : "wait" };

                window.dlg_submitContinueConfig = { title : "{string:'dlg_wait_title'}", url:"{=submit.url}", message : "{string:'dlg_wait_content'}", viewMode : "wait", evalconfig: true };

                window.dlg_failureConfig = { title : "{string:'dlg_failure_title'}", message : "{string:'dlg_failure_content'}", viewMode : "cancel", target : "content", labels : { cancel : "{string:'dlg_cancel'}" } };
			
//]]>
</script>
			<div class="form-actions-wrapper">
				<div class="pm-button-wrapper clear-both pm-bxm-top-button-wrapper">
                    {=buttons}
                </div></div>
				<div id="panel_title-green" class="form-panel-bs">
					<div class="">
						<div class="pm-bxm-box-content pm-bxm-box-content-panel pm-bxm-box-content-">
					<div class="columns-layout-bs row">
						<div class="column-1 col-md-6">
							<div class="row">
							<fieldset id="group_1" class="field-group-bs">
								<legend class="">{string:'profile_infos'}
								</legend>
								<div class="form-group-content">{get_field:first_name}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:first_name}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:first_name}</div></div>{get_field:last_name}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:last_name}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:last_name}</div></div>{get_field:civility}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:civility}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:civility}</div></div>{get_field:gender}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:gender}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:gender}</div></div>{get_field:date_of_birth}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:date_of_birth}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:date_of_birth}</div></div>{get_field:nationality}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:nationality}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:nationality}</div></div></div>
							</fieldset>
							<fieldset id="group_2" class="field-group-bs">
								<legend class="">{string:'candidate_infos'}
								</legend>
								<div class="form-group-content">{get_field:studies_level}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:studies_level}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:studies_level}</div></div></div>
							</fieldset></div></div>
						<div class="column-1 col-md-6">
							<div class="row">
							<fieldset id="group_1" class="field-group-bs">
								<legend class="">{string:'coordinates'}
								</legend>
								<div class="form-group-content">{get_field:email}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:email}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:email}</div></div>{get_field:mobile}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:mobile}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:mobile}</div></div>{get_field:phone_1}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:phone_1}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:phone_1}</div></div>{get_field:phone_2}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:phone_2}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:phone_2}</div></div>{get_field:zip}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:zip}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:zip}</div></div>{get_field:country_oid}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:country_oid}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:country_oid}</div></div>{get_field:town_oid}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:town_oid}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:town_oid}</div></div></div>
							</fieldset>
							<fieldset id="group_2" class="field-group-bs">
								<legend class="">{string:'vacancy'}
								</legend>
								<div class="form-group-content">{get_field:vacancies_oid}{/get_field}
								<div id="field_{field.name}" class="form-group form-group-bs field-type-{field.type} {if:field.is_last} last_field{/if}">
												<div class="control-label-wrapper-bs">
													<label for="{field.name}" class="control-label-bs control-label">{field.label:vacancies_oid}{if:field.isRequired}
									<span class="required-field">*</span>{/if} :
													</label></div>
											<div class="form-control-bs" id="{field.name}-control">{field:vacancies_oid}</div></div></div>
							</fieldset></div></div></div></div></div></div>
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
		<script type="text/javascript" language="Javascript">
//<![CDATA[

            window.onload =function(){window.ajax_load('/nx/skins/default/js/recruitment/form_candidate_add.js','form_candidate_add_js');}
        
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
			