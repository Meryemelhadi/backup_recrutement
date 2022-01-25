<script language="php">

include_once(NX_LIB.'framework.inc');
$ctxt=Framework::getContext();
$journal = Portal::applicationDesc();
if ($journal->isOk())
{
	// check perm
	$perms = trim($journal->perms->object);
	if($perms && $perms != '?' && !($GLOBALS['_NX_user']->checkPerm($perms)))
		die(__("access not granted"));

	$title = $journal->name->html;
	$withImage = $journal->with_image->object;
	$withSummary = $journal->with_summary->object;
	$fx= $journal->css_fx->js;
	if($journal->lang->object) 
	{
		global $NX_LANG;
		$NX_LANG = $ctxt->setProperty('lang',$journal->lang->object);
	}

	if($fx)
		$fx = preg_replace(array('%&nbsp;|<br\s*/>%i','%&quot;%'),array('','"'),$fx);

	$css= $journal->cssList->js;
	$modeJ= $journal->mode->object;
	$imgPos= $journal->image_pos->object;
	if ($imgPos!='right')
	{
		$imgPos='left';
	}

	$cssW ='';
	$bgCol = $journal->header_background_color->object;
	if($bgCol) {
		$cssW .= "background-color:$bgCol;";
	}
	$bgIm = $journal->header_background_image->string;
	if($bgCol) {
		$cssW .= "background-image:url(\"$bgIm\");";
	}
	elseif($bgCol) {
		$cssW .= "background-image:none;";
	}

	$cssWA ='';
	$Tcol = $journal->header_text_color->object;
	if($Tcol) {
		$cssWA .= "color: $Tcol !important;";
	}

	$Bcol = $journal->background_color->object;
	if($Bcol) {
		$css = "#page-content, body {background-color: $Bcol !important;} " .$css;
	}

	$withComments = $journal->comment->object;
}
else {
	$title = __('page_title_view');
	$withImage = 1;
	$withSummary = 1;
	$css=$cssW=$cssW='';
	$modeJ='article';
	$withComments = '0';
}

if($withComments=='1')
	$ctxt->setProperty('enable_comments','true');

$title_url = urlencode($title);
$title_GA = str_replace("'",'',$title);


</script><style>
{if: #var:cssW# != ''}
.pm-page-title-wrapper {
	{$cssW}
    margin-left: -12px;
    margin-right: -10px;
    padding-left: 12px;
}
{/if}

{if: #var:cssWA# != ''}
.pm-page-title-wrapper a, .pm-page-title-wrapper .pm-title {
{$cssWA}
}
{/if}

{$fx}
{$css}

</style>

{if: #const:GA_KEY#}
<script type="text/javascript">
	
  window._gaq = window._gaq || [];
  window._gaq.push(['_setAccount', '{const:GA_KEY}']);
  window._gaq.push(['_setDomainName', '{const:GA_DOMAIN}']);
  window._gaq.push(['_setCustomVar','1','Collaborateur','{user:user.userID}','2']);
  window._gaq.push(['_trackPageview','/journal/{$title_GA}']);
  window._gaq.push(['_trackEvent','article','list','{$title_GA}']);
  
  (function() {
	var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
	ga.src = ('http:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
	var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>
{/if}



<?php
$workflow = $this->getProperty('workflow');
?>

<div class="pm-page-title-wrapper"><div class="pm-page-title-inner-wrapper"><div class="pm-title"><?php echo __($workflow->title); ?>
		</div>
	</div>
</div><script language="php">

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


</script><script language="php">
$msgHelp = $this->getProperty('msg.help');
if($msgHelp)
{

</script><div id="help" class="help"><div class="message">{var:msgHelp}
	</div>
</div><script>
	var helpDiv=document.getElementById('help');
	var helpText = (helpDiv.innerText||helpDiv.textContent);
	if(!helpText)
		helpDiv.style.display = 'none';

</script><script language="php">
}
</script><table class="columns-viewer"><tr><td class="left-column"><div class="pm-grid-outer-wrapper"><div class="generis-toolbar-wrapper"><div class="generis-toolbar"><script language="php">

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


						</script><script>
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
		
						</script><a href="javascript:window.{$dialogID}.exec();" class="s-icon {var:iconCls}"><span class="btn-bg"><span>{var:title}
								</span>
							</span>
						</a><script language="php">
	}
	elseif (isset($action['id']))
	{
		$id = $action['id'];

						</script><a class="s-icon {var:iconCls}" href="{var:url}&mode=ajax" onclick="ajax_navigate(event,'{var:url}&mode=ajax','{var:id}'); return false;"><span>{var:title}
							</span>
						</a><script language="php">
	}
	elseif($target)
	{

						</script><a class="s-icon {var:iconCls}" href="{var:url}" target="{var:target}"><span>{var:title}
							</span>
						</a><script language="php">
	}
	else
	{

						</script><a class="s-icon {var:iconCls}" href="{var:url}"><span>{var:title}
							</span>
						</a><script language="php">
	}
}

						</script>
					</div>
				</div><div class="tab_panel"><div class="tab_content {tab_id}">

					 {records:page.records} 
				{if:records.count>0}
				<div class="pm-grid-wrapper"><table class="pm-grid">
					 {record} 
<?php $_nx_content_stack[]="operations";	ob_start(); ?>
					<script language="php">

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

								</script><a href="javascript:void(0);" class="s-icon {$iconCls}" onclick="window.open('{var:url}','{var:target}');return false;" title="{$title}" target="{var:target}"><span class="x-hidden">{$title}
									</span>
								</a><script language="php">
		}
		else
		{

								</script><a href="{var:url}&mode=page" class="s-icon {$iconCls}" onclick="document.location='{var:url}'; window.event.cancelBubble = true;if(event.stopPropagation) event.stopPropagation();return false;" title="{$title}"><span class="x-hidden">{$title}
									</span>
								</a><script language="php">
		}
	}
	elseif(isset($op['confirm']) && $op['confirm'])
	{

								</script><script>
	window.dlg_{var:opID}Config{record.index}_{var:opIDX} = { title : "{string:'dlg_delete_title'}", message : "{string:'dlg_delete_content'}", viewMode : "okCancel", url : "{var:url}&mode=page", target : "content", labels : { ok : "{string:'dlg_ok'}", cancel : "{string:'dlg_cancel'}" } };
	
								</script><a href="javascript:void(0);" class="s-icon {$iconCls}" title="{$title}" onclick="PMModalbox.display(window.dlg_{var:opID}Config{record.index}_{var:opIDX}, event);return false;"><span class="x-hidden">{$title}
									</span>
								</a><script language="php">
	}
	else
	{

								</script><a href="javascript:void(0);" class="s-icon {$iconCls}" title="{$title}" onclick="ajax_navigate(event,'{var:url}&mode=ajax','{var:id}')"><span class="x-hidden">{$title}
									</span>
								</a><script language="php">
	}
}

//$listOperations = null;

								</script>
<?php $this->setProperty(array_pop($_nx_content_stack),ob_get_contents());ob_end_clean();?>

					 {if:record.is_first} 
<tr>
	{fields}
	<th>{field.label}
									</th>
	{/fields}
	<th/>
								</tr>
 {/if} 
					<tr class="grid-row row_{record.even_odd}" onclick="ajax_navigate(event,'{var:edit_url}{record.url_key}&mode=ajax','content')">
						{fields}
						<td><div class="simple-wrapper">{field}
										</div>
									</td>
						{/fields}
						<td class="operations operations-2" onclick="window.event.cancelBubble = true;if(event.stopPropagation) event.stopPropagation();return false;"><div class="simple-wrapper">{=operations}
										</div>
									</td>
								</tr>
					 {/record} 
				
							</table>
						</div>
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
	<ul class="pages"><li class="first-meta"><span>Page(s) {pages.current} sur {pages.nb_pages} : 
									</span>
								</li>
		{pages:previous}
		<li class="previous"><a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{var:ltrUrl}&amp;mode=ajax','content');return false;">&laquo; Page pr&eacute;c&eacute;dente
									</a>
								</li>
		{/pages}

		{pages:all}
		{if:page.is_current}
		<li class="active"><span>{page.index}
									</span>
								</li>
		{else}
		<li><a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{var:ltrUrl}&amp;mode=ajax','content');return false;">{page.index}
									</a>
								</li>
		{/if}
		{/pages}

		{pages:next}
		<li class="next"><a href="javascript:void(0);" onclick="ajax_navigate(event,'{page.url}{var:ltrUrl}&amp;mode=ajax','content');return false;">Page suivante &raquo;
									</a>
								</li>
		{/pages}
	
							</ul>
	{/if}

	{if:pages.nb_records > 0}
	<div class="items-count"><span class="pm-pagination-records-count"><strong>{pages.nb_records}
									</strong> {string:"items_search"}
								</span>
							</div>
	{else}
	<div class="items-count"><span class="pm-pagination-records-count"><strong>{records.count}
									</strong> {string:"items_search"}
								</span>
							</div>
	{/if}

						</div>
{/if}
					
					</div>
				</div>
			</div>
		</td>
	</tr>
</table>