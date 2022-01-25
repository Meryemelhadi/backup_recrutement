<?php

class DataRecord {}

class API_Collection {
	var $time;
	var $items;
}

class Workflow_Task_display_list_vacancies_ws  extends Workflow_Task
{
	function getObjects($ds, $ds_count = null , $site_info = null)
	{
		global $NX_DOMAIN;

		$now = time();

		$res = new API_Collection;
		$res->time = time();
		
		if($ds != null){
			// load collection
			$col = new PersistentCollection($ds,'db');	
			if(!$col->isOk())
			{
				$this->ctxt->error(__('no files'));
				return true;
			}
			$records = $col->records;
			
			if($ds_count != null){
				//count total records
				$total = new PersistentObject($ds_count,'db');	
			}

			// transform to PHP objects
			$recs = $this->transformRecords($records,$isMul=true,$baseUrl=$NX_DOMAIN);
			$res->account_mail = $this->ctxt->getProperty('recruitment.mail_account');
			$res->IFTT_KEY = IFTT_KEY;

			if($ds_count != null)
				$res->count = $total->record->count->object;
			$recs[0]->total =  $total->record->count->object;
			$res->items = $recs;
		}
		
		
		if($site_info != null){
			$site_info = $this->transformRecord($site_info,$isMul=true,$baseUrl=$NX_DOMAIN);
			
			/*** Default logo ***/
			if($site_info->logo == NULL || $site_info->logo == ''){
				$logo = new PersistentObject('skin_editor.login.current@admin2','db');
				$logo_record = $this->transformRecord($logo->record,$isMul=true,$baseUrl=$NX_DOMAIN);
			
				if($logo_record->login_logo == NULL || $logo_record->login_logo == ''){
					$site_info->logo = $_SERVER['SERVER_NAME'].'/nx/skins/default/img/site-carriere/logo.png';
					$site_info->logo__small = $_SERVER['SERVER_NAME'].'/nx/skins/default/img/site-carriere/logo.png';
					$site_info->logo__name = 'logo.png';
				}else{
					$site_info->logo = $logo_record->login_logo;
					$site_info->logo__small = $logo_record->login_logo__small;
					$site_info->logo__name = $logo_record->login_logo__name;
				}
			}

			/*** Default society banner ***/
			if($site_info->banner_background_image == '' && $site_info->banner_background_image == NULL){
				$site_info->banner_background_image = $_SERVER['SERVER_NAME'].'/nx/skins/default/img/site-carriere/banner.jpg';
				$site_info->banner_background_image__small = $_SERVER['SERVER_NAME'].'/nx/skins/default/img/site-carriere/banner.jpg';
				$site_info->banner_background_image__name = 'banner.jpg';
			}
			
			/*** Default society banner second ***/
			if($site_info->banner_second_background_image == '' && $site_info->banner_second_background_image == NULL){
				$site_info->banner_second_background_image = $_SERVER['SERVER_NAME'].'/nx/skins/default/img/site-carriere/banner_second.jpg';
				$site_info->banner_second_background_image__small = $_SERVER['SERVER_NAME'].'/nx/skins/default/img/site-carriere/banner_second.jpg';
				$site_info->banner_second_background_image__name = 'banner_second.jpg';
			}
			
			/*** Default society name ***/
			if($site_info->name_society == '' && $site_info->name_society == NULL)
				$site_info->name_society = NX_CLIENT_NAME;
				
			/*** Default contact email ***/
			if($site_info->contact_email == '' && $site_info->contact_email == NULL)
				$site_info->contact_email = 'meryem.elhadi@presencemedia.ma';

			/*** Supprimer les balises html du code css/js ***/
			$site_info->css_txt = strip_tags(html_entity_decode ($site_info->css_txt)); 
			$site_info->js_txt = strip_tags(html_entity_decode (str_replace("&#039;", "'", $site_info->js_txt))); 
			$res->site_info = $site_info;
		}

		// output res = XML or json
		return $this->ctxt->outputRes($res);
	}

	function transformRecords($records,$isMul,$baseUrl) 
	{
		$ar=array();
		if($records) for ($iterRec = $records->getRecordIterator(); $iterRec->isValid(); $iterRec->next())
		{
			$record=$iterRec->getCurrent();
			$ar[] = $this->transformRecord($record,$isMul,$baseUrl);
		}

		if(!$isMul && count($ar)>0)
			return $ar[0];
		else
			return $ar;
	}
	
	function transformRecord($record,$isMul,$baseUrl) 
	{
		$baseUrl=trim($baseUrl,'/');
		
		$rec = new DataRecord();

		for ($iterFld = $record->getFieldIterator(); $iterFld->isValid(); $iterFld->next())
		{
			$fld=$iterFld->getCurrent();

			$label = $fld->label;
			$fname = $fld->alias;
			$type  = $fld->desc->getType();
			
			if(!$fld->desc->isHidden())
			{
				if($type=='image' || $type=='file')
				{
					$url= $fld->toHTML('url');
					if($url)
					{
						$this->resources[] = $rec->$fname = $baseUrl . $fld->toHTML('url');
						$n = $fname.'__small';
						$rec->$n = $baseUrl . $fld->toHTML('url 200x200');
						$n = $fname.'__name';
						$rec->$n = $fld->info['n'];
					}
					else
					{
						$rec->$fname = '';
						$n = $fname.'__small';
						$rec->$n = '';
						$n = $fname.'__name';
						$rec->$n = '';
					}
				}
				elseif($type=='records')
				{
					$rec->$fname->item = $this->transformRecords($fld->toRecords(),true,$baseUrl);
				}
				elseif($type=='text_choice')
				{
					$rec->$fname->html = $fld->toHTML();
					$rec->$fname->value = $fld->object;
				}
				elseif($type=='datetime' || $type=='timestamp')
				{
					$rec->$fname->value = $fld->db;
					$rec->$fname->time = $fld->time;
				}
				elseif($type=='oid' || $type=='ref_oid')
				{
				}
				else
				{
					$v=$fld->toHTML();
					if($v=='&nbsp;')
						$v='';

					$rec->$fname = $v;
				}
			}
		}

		return $rec;
	}

	function run($workflow, $user)
    {
		$model = $workflow->model;
		$this->ctxt->setProperty('workflow',$workflow);

		// operation
		if(!isset($_REQUEST['op']) || !($op=$_REQUEST['op']))
		{
			$this->ctxt->error('no operation defined');
			return;
		}
		
		//Get Site Info
		$site_record =  null;
		if(isset($_REQUEST['company']) && $_REQUEST['company'] == true){
			if(isset($_REQUEST['local']) && isset($_REQUEST['local']) == 1){
				$site_info = new PersistentObject('rct_app_connected.pub_app@recruitment','db');
			}else $site_info = new PersistentObject('rct_app_connected.pub_app_key@recruitment','db');
			if(!$site_info->isOk()) return null;
			$site_record = $site_info->record;
		}
		
		
		$dsList_count = null ; 
		$dsList = null ;
		
		if(isset($_REQUEST['vacancies']) && $_REQUEST['vacancies'] == true){
			$op .= '_ws';
			// op == ds name
			$dsList = $model->getDS($op);
			if(!$dsList) 
			{
				$data = $this->getParam('data','ws');
				$dsList = $model->getDS($data);
			}

			if(!$dsList) 
			{
				$this->ctxt->error('no valid operation/data defined');
				return false;
			}
			
			if($this->getParam('data_count',false)){
				$dsList_count = $model->getDS($this->getParam('data_count',false));	
			}
		}
		
		$res = $this->getObjects($dsList , $dsList_count , $site_info->record);
		

		return true;
	}
}

?>
