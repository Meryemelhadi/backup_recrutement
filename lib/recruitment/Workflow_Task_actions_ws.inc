<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');
include_once(NX_LIB.'ws/nxEvents.inc');

class Workflow_Task_actions_ws extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}
	

	function run()
	{ 

		if(isset($_REQUEST['action']) && $_REQUEST['action'] != ''){
			$action_key = $_REQUEST['action'];
			$_REQUEST['oid'] = $_REQUEST['action'];
			/*** Get web service ***/
			$action = new PersistentObject('services_web.record@recruitment','db');
		
			if(isset($_REQUEST['candidate']) && $_REQUEST['candidate'] != ''){
				$this->setProperty('candidate',$_REQUEST["candidate"]);
				/*** Get Candidate object ***/
				$candidate =  new PersistentObject('rct_candidate.record_ws@recruitment','db');
					
				if($candidate->isOk()){
					/*** choose connector ***/
					if (class_exists('Ws_connector_'.strtolower(trim($action->type)))) {
						$className = 'Ws_connector_'.strtolower(trim($action->type->object));
						$connector = new $className($candidate , $action);
					}else{
						$connector = new Ws_connector_default($candidate , $action);
					}
			
					$result = $connector->send() ; 
								
					if($result){
						$result = json_decode(urldecode($result));
					
					
						if($result->msg != null && $result->msg !=''){
							$msg  = $result->msg;
						}else $msg  = $action->notification;
						//nxEvents::fireEvent('candidat', $candidat->first_name->object.' '.$candidat->last_name->object , mysql_real_escape_string($msg)  , array('oid'=>1));
						
						if($result->name && $result->url){
							$msg .= ' <button onclick="window.open(\''.$result->url.'\'); return false;">'.$result->name.'</button>';
						}
						
						
						/*** Historique ***/
						$log= new lib_recruitment_candidates_services_log($this);
						$log->addLog($_REQUEST["candidate"] , $user->oid->object, 15 , '' , mysql_real_escape_string($msg));
						
						$this->msgOkBs($msg);
						
						
					}else $this->msgErrorBs(__('error_operation'));
					
				}
			}
		}

		return true;
	}
}

/*** Default connector ***/
class Ws_connector_default {
	var $candidate;
	var $action;
	function __construct($candidate , $action)
	{
		$this->candidate = $candidate;
		$this->action = $action;
	}
	function send(){ 
		$candidate_array = array(); 
		$candidate_record = $this->candidate->record; 
		for ($iterFld = $candidate_record->getFieldIterator(); $iterFld->isValid(); $iterFld->next())
		{
		
			$fld=$iterFld->getCurrent();
			$candidate_array[$fld->name] = $fld->value;
		}
		
		if (function_exists('curl_file_create')) { // php 5.5+
		  $cFile = curl_file_create($candidate_record->cv_path->path);
		} else { // 
		  $cFile = '@' . realpath($candidate_record->cv_path->path);
		}

		$url = trim($this->action->url->value);
		$data_string = urlencode(json_encode($candidate_array));
		$post_data = array('candidate'=>$data_string , 'cv' => $cFile);
		//Method d'authentification : GET , POST , OAUTH
		if($this->action->auth_type->object == 1){
			$url .= '?username='.$this->action->login->object.'&password='.$this->action->password->object;
			$ch=curl_init($url);
		}else if($this->action->auth_type->object == 3){
			$ch=curl_init($url);
			$post_data['grant_type'] = 'authorization_code';
			$post_data['code'] =$this->action->key->object;
			curl_setopt($ch, CURLOPT_USERPWD, $this->action->login->object.":".$this->action->password->object);
		}else{
			$ch=curl_init($url);
			$post_data['username'] = $this->action->login->object;
			$post_data['password'] = $this->action->password->object;
		}
		
		curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
		
		curl_setopt($ch, CURLOPT_SAFE_UPLOAD, false);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data );
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);         
		curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);			
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);

		$result = curl_exec($ch);
		echo $result;
		$resultStatus = curl_getinfo($ch, CURLINFO_HTTP_CODE);
		
		curl_close($ch);

		if($resultStatus == 200){
			if($result!= '') return $result;
			return true;
		}
			
			
		return false;
			
		
	}
}

/*** Annuaire ***/
class Ws_connector_annuaire {
	var $candidate;
	var $action;
	function __construct($candidate , $action)
	{
		$this->candidate = $candidate;
		$this->action = $action;
	}
	function send(){ 
		$candidate_array = array(); 
		$candidate_record = $this->candidate->record; 
		for ($iterFld = $candidate_record->getFieldIterator(); $iterFld->isValid(); $iterFld->next())
		{
		
			$fld=$iterFld->getCurrent();
			if($fld->name == 'contract_type_oid'){
				$candidate_array[$fld->name] = $fld->string;
			}else{
				if($fld->value != '')
			 		$candidate_array[$fld->name] = $fld->value;
			 	else $candidate_array[$fld->name] = $fld->string;
			}
		}
		
		if (function_exists('curl_file_create')) { // php 5.5+
		  $cFile = curl_file_create($candidate_record->cv_path->path);
		} else { // 
		  $cFile = '@' . realpath($candidate_record->cv_path->path);
		}

		$url = trim($this->action->url->value);

		$data_string = urlencode(json_encode($candidate_array));
		$post_data = array('candidate'=>$data_string , 'cv' => $cFile , 'url' => $url );

		//Method d'authentification : GET , POST , OAUTH
		if($this->action->auth_type->object == 1){
			$url .= '?username='.$this->action->login->object.'&password='.$this->action->password->object;
			$ch=curl_init($url);
		}else if($this->action->auth_type->object == 3){
			$ch=curl_init($url);
			$post_data['grant_type'] = 'authorization_code';
			$post_data['code'] =$this->action->key->object;
			curl_setopt($ch, CURLOPT_USERPWD, $this->action->login->object.":".$this->action->password->object);
		}else{
			$ch=curl_init($url);
			$post_data['username'] = $this->action->login->object;
			$post_data['password'] = $this->action->password->object;
			
		}
		
		curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
		curl_setopt($ch, CURLOPT_POST, 1);
		
		
		curl_setopt($ch, CURLOPT_SAFE_UPLOAD, false);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
		curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);		
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
		curl_setopt($ch, CURLOPT_POSTFIELDS, $post_data);

		$result = curl_exec($ch);
		//var_dump( curl_error($ch));
		echo $result;
		

		$resultStatus = curl_getinfo($ch, CURLINFO_HTTP_CODE);
		
		curl_close($ch);

		if($resultStatus == 200){
			if($result!= '') return $result;
			return true;
		}
			
			
		return false;
			
		
	}
}

/*** Twitter Connector ***/
class Ws_connector_twitter {
	var $candidate;
	var $action;
	function __construct($candidate , $action)
	{
		$this->candidate = $candidate;
		$this->action = $action;
	}
	function send(){
		$candidate_array = array(); 
		$candidate_record = $this->candidate->record; 
		for ($iterFld = $candidate_record->getFieldIterator(); $iterFld->isValid(); $iterFld->next())
		{
		
			$fld=$iterFld->getCurrent();
			$candidate_array[$fld->name] = $fld->value;
		}
		
		if (function_exists('curl_file_create')) { // php 5.5+
		  $cFile = curl_file_create($candidate_record->cv_path->path);
		} else { // 
		  $cFile = '@' . realpath($candidate_record->cv_path->path);
		}
		
		$ch=curl_init(trim($this->action->url));
		$data_string = urlencode(json_encode($candidate_array));
		curl_setopt($ch, CURLOPT_CUSTOMREQUEST, "POST");
		curl_setopt($ch, CURLOPT_USERPWD, $this->action->login->object.":".$this->action->password->object);
		curl_setopt($ch, CURLOPT_POSTFIELDS, array("candidate"=>$data_string , 'username'=>$this->action->login->object , 'password' => $this->action->password->object, 'cv' => $cFile));
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true); 
		curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);	
		curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);

		$result = curl_exec($ch);
		echo $result;
		$resultStatus = curl_getinfo($ch, CURLINFO_HTTP_CODE);
		curl_close($ch);
		if($resultStatus == 200)
			return true;
			
		return false;
	}
}



?>