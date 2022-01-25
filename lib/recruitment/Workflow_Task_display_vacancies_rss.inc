<?php

class DataRecord {}

class API_Collection {
	var $time;
	var $items;
}

class Workflow_Task_display_vacancies_rss  extends Workflow_Task
{
	function getObjectsXml($ds_list , $ds_compagnie)
	{
		global $NX_DOMAIN;
		// load collection
		$list = new PersistentCollection($ds_list,'db');	
		$compagnie = new PersistentObject($ds_compagnie,'db');	
		if(!$list->isOk())
		{
			$this->ctxt->error(__('no files'));
			return true;
		}
		
		$records_list = $list->records;
		$record_compagnie = $compagnie->record;
		
		// transform to PHP objects
		$recs = $this->transformRecords($records_list,$isMul=true,$baseUrl=$NX_DOMAIN);

		$xml = "@<?xml version='1.0' encoding='utf-8' ?>" . "\n";
		$xml .= '<rss version="2.0">';
		$xml .= '<channel>';
		$xml .= '<title>'.$record_compagnie->compagnie_name.' recrute</title>';
		$xml .= '<link>'.$this->addhttp($record_compagnie->url).'</link>';
		$xml .= '<description>'.$record_compagnie->description->value.'</description>';
		$xml .= '<image><title>'.$record_compagnie->compagnie_name.' recrute</title><url>'.(isset($_SERVER["HTTPS"]) ? 'https' : 'http') . '://'.$_SERVER[HTTP_HOST].$record_compagnie->logo->url.'</url><link>'.$this->addhttp($record_compagnie->url).'</link></image>';
		
		foreach($recs as $r){
			$xml .='<item>';
			$xml .= '<title>'.$r->name.'</title>';
			$xml .= '<description>'.htmlspecialchars($r->mission_definitions).'</description>';
			//$d = new DateTime($r->opening_date->string);
			//$xml .= '<pubDate>'.$d->format("d M Y H:i:s O").'</pubDate>';
			$xml .= '<author>'.$r->email.'</author>';
			$xml .='</item>';
		} 
	
	
		$xml .= '</channel>';
		$xml .= '</rss>';

		return $this->ctxt->outputRes($xml);
	}
	
	function addhttp($url){
		if(!preg_match("~^(?:f|ht)tps?://~i" , $url)){
			$url = "http://".$url;
		}
		return $url;
	}

	function transformRecords($records,$isMul,$baseUrl) 
	{
		$baseUrl=trim($baseUrl,'/');

		$ar=array();
		if($records) for ($iterRec = $records->getRecordIterator(); $iterRec->isValid(); $iterRec->next())
		{
			$record=$iterRec->getCurrent();
			$rec = new DataRecord();

			for ($iterFld = $record->getFieldIterator(); $iterFld->isValid(); $iterFld->next())
			{
				$fld=$iterFld->getCurrent();

				$label = $fld->label;
				$fname = $fld->name;
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

			$ar[] = $rec;
		}

		if(!$isMul && count($ar)>0)
			return $ar[0];
		else
			return $ar;
	}

	function run($workflow, $user)
    {
	
		$model = $workflow->model;
		$this->ctxt->setProperty('workflow',$workflow);

		
		$dsList = $model->getDS('vacancies_app_ws');
		$dsCompagnie = $model->getDS('vacancies_app_compagnie');

		if(!$dsList && !$dsCompagnie) 
		{
			$this->ctxt->error('no valid operation/data defined');
			return false;
		}

		return $this->getObjectsXML($dsList , $dsCompagnie);

	}
}

?>
