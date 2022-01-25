<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
//require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_upload_cv  extends Workflow_Task
{
	var $directory = 'packages/recruitment/candidates/directory/';
	var $coid=null;

	function run($workflow, $user)
	{   
		//DebugBreak();
		if($this->updateCurrent=$this->getParam('mode','')=='update')
		{
			$this->coid = isset($_GET['coid'])?$_GET['coid']:null;
		}

		$isNew = false;
		$oid = $this->saveCV('',$isNew);

		if($oid) 
		{
            //$log= new lib_recruitment_candidates_services_log($this->ctxt);
			if($isNew) {
                $this->ctxt->msgOkBs(__('New resume added successfully'));
                //Add log
                //$log->addLog($oid, $GLOBALS["_NX_user"]->getProperty("oid",""), 0 , '' , '');
            }
			else {
                $this->ctxt->msgOkBs(__('Resume updated successfully'));
                //Add log
                //$log->addLog($oid, $GLOBALS["_NX_user"]->getProperty("oid",""), 11 , '' , '');
            }
			
			//par defaut le recruteur est l'utilisateur courant s'il n'est pas défini
			$o =  new PersistentObject('rct_candidate.set_hr_manager@recruitment','db',array('oid' => $oid));
			if($o->hr_manager->object == null || $o->hr_manager->object == "" || $o->hr_manager->object == 0){
				if($vacancyRecord->manager_oid->object == null || $vacancyRecord->manager_oid->object == '' || $vacancyRecord->manager_oid->object == 0){
					$o->setFieldValue('hr_manager',$GLOBALS["_NX_user"]->getProperty("oid",""));
				}
			}
			$o->store('rct_candidate.set_hr_manager@recruitment', 'update', 'db', array('oid' => $oid));

			//$url = "directory.php?nxo=edit&oid={$oid}&candidate_oid={$oid}&mode=page";
			$src = "";
			$fram = "";
			if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
				$src = "&src=newcvt";
				$fram = "/fram";
			}
			$url = PORTAL_URL_PREFIX.$fram."/recruitment/candidates/coid-{$oid}/directory.php?nxo=edit&mode=page&oid={$oid}&candidate_oid={$oid}".$src;
		}
		else {
			$this->ctxt->msgErrorBs(__('analyser not available or analysis issue'));
			$url = "directory.php";
		}

		header("Location: $url");
		return true;
	}

	function saveCV($mode,&$isNew) 
	{
		// Déplacement des fichiers dans un endroit temporaire
		$tempPath = $this->ctxt->getProperty('pathUpload').$this->directory.uniqid().'/';
		
		$fs = new NxPlug_FileSys($this->ctxt);
		$fs->createTree($tempPath .'cv/');
		$fs->createTree($tempPath .'cl/');
		
		$cvFullPath = $this->uploadFile('temp_cv_file', $tempPath.'cv/');
		// $clFullPath = $this->uploadFile('temp_cl_file', $tempPath.'cl/');
		
		$candidateOid = null;

		$savePost = true;
		if( $cvFullPath !== false ) 
		{
			if($this->coid)
			{
				// update cv
				$oid = $this->coid;
				$isNew=false;
			}
			else
			{
				// add or update cv
				$oid=null;
				$isNew=null;
			}

			// call analyser
			$cvAnalyse = $this->callAnalyser($cvFullPath,$oid,$isNew);

			if($this->coid)
			{
				$candidateOid = $this->coid;
			}

			if ($cvAnalyse) 
			{
				$savePost = false;
				$candidateOid = $oid;
			}

			if($candidateOid)
			{
				$this->ctxt->setProperty('candidate_oid', $candidateOid);
				$record = new PersistentObject('rct_candidate.manage_cv@recruitment','db', array('oid'=>$candidateOid));

				if($savePost) 
				{
					$pinfos = $fs->pathinfo($cvFullPath);
					$ext = $pinfos['extension'];
					if($ext == 'pdf')
					{
                        //Add prefix to path
                        $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
                        $prefix = '';
                        if($candidateOid >= $dvs){
                            $prefix='/_'.intval($candidateOid/$dvs)*$dvs;
                        }
						$toDir = "packages/recruitment/candidates/directory".$prefix."/{$candidateOid}/cv/";
						$record->cv_path->readFromFile($cvFullPath,$toDir);
						$record->store('rct_candidate.manage_cv@recruitment','update','db', array('oid'=>$candidateOid));
					}					
				}
			}
		}

		/*
		if( $record ) {
			if($record->isOk()) {
				$this->convertToSwf(dirname($record->cv_path->path).'/', basename($record->cv_path->path));
			}
		}
		*/
		
		$fs->rmDir($tempPath);
		
		return $candidateOid;
	}

	function uploadFile($formName, $uploadPath) {
		
		if( ! empty($_FILES[$formName]['name']) ) 
		{
			$fileName = $_FILES[$formName]['name'];
			$fileName = $this->replaceAccents($fileName);

			$tempFileName 	= $_FILES[$formName]['tmp_name'];			
			// Clear upload path
			$completePath	= $uploadPath.$fileName;
			move_uploaded_file($tempFileName, $completePath);
			chmod($completePath,0644);

			//$this->convertToSwf($uploadPath, $fileName);
			
			return $completePath;
		}
		
		return false;
	}
	function replaceAccents($str) {

		$res = str_replace( 
			array('à','á','â','ã','ä','ç','è','é','ê','ë','ì','í','î','ï','ñ','ò','ó','ô','õ','ö','ù','ú','û','ü','ý','ÿ','À','Á','Â','Ã','Ä','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï', 'Ñ','Ò','Ó','Ô','Õ','Ö','Ù','Ú','Û','Ü','Ý'), 
			
		
		array('a','a','a','a','a','c','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y','y','a','a','a','a','a','c','e','e','e','e','e','i','i','i','i','n','o','o','o','o','o','u','u','u','u','y'), $str);

		return $res;
	}
	
	function getFilesUploadPath($candidateOid) {

        //Add prefix to path
        $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
        $prefix = '';
        if($candidateOid >= $dvs){
            $prefix='_'.(intval($candidateOid/$dvs)*$dvs).'/';
        }
		$path = $this->ctxt->getProperty('pathUpload').$this->directory.$prefix.$candidateOid;
		if( ! is_dir($path) ) {
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path .'/cv');
			$fs->createTree($path .'/cl');
		}
		return $path .'/';
	}
	
	function callAnalyser($filePath,&$oid,&$isNew) 
	{
		return $this->callAnalyser_post($filePath,$oid,$isNew);
	}

	function callAnalyser_soap($filePath,&$oid,&$isNew) 
	{
		include_once(NX_DIS.'nusoap/lib/nusoap.php');
		require_once(GENERIS_PACKAGES.'cv/lib/cv/NxCV_cv.inc');
		require_once(GENERIS_PACKAGES.'cv/lib/cv/NxCV_ServiceFactory.inc');
		require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/NxCV_StoreCV.inc');

		$codeSwitch = trim(NX_HOST_SWITCH,'_');

		$codeClient = 'cvproc'; // to be put in host file...
		$services = new NxCV_ServiceFactory($this->ctxt,'holcim');
		$config = $services->getConfig();
       
		// get client config (inherit the main config in the same file)
		$clientConfigs = $config->getProperty('clients.upload.soap');
		if (isset($clientConfigs[$codeSwitch]))
		{
			$props = $clientConfigs[$codeSwitch];
			$cltConfig = new NxProperties($props,$config);
			$soap_url = $cltConfig->getProperty('server.url',null);
		}
		if(!$soap_url && isset($clientConfigs[$codeClient]))
		{
			$props = $clientConfigs[$codeClient];
			$cltConfig = new NxProperties($props,$config);
			$soap_url = $cltConfig->getProperty('server.url',null);
		}
		if(!$soap_url)
		{
			$soap_url = $config->getProperty('server.url',null);
		}
		if(!$soap_url)
		{
			$soap_url = 'http://cvproc.presencesoft.net/cv/soap/analyseCV.php';
		}

		// get CV files and encode them in B64
		$fileName = basename($filePath);
		$fileContent=$services->fs->file_get_contents($filePath,'rb');
		$b64fileContent=base64_encode($fileContent);
		$filesB64[$fileName] = $b64fileContent;

		// call server
		$client = new nusoap_client($soap_url,false);

		$filesJSON = json_encode(array('cv' => array('content'=>$b64fileContent,'name'=>$fileName)));
		$paramsJSON= json_encode(array('object'=>'true','pdf'=>'true','src'=>'true'));
		$parametres = array(
			'cltID' => $codeClient,
			'filesJSON'=>$filesJSON,
			'paramsJSON'=>$paramsJSON
			); 
		$res = $client->call('analyseCV', $parametres,true);

		if (!$res)
			return false;

		// decode result
		$oCVs = json_decode($res);
		if (!is_array($oCVs) || count($oCVs)==0)
			return false;

		$oCV = $oCVs[0]->object;
		$filesB64= $oCVs[0]->files;
		if(isset($filesB64->cv))
		{
			$fcontent['cv']=base64_decode($filesB64->cv->content);
			$fpath['cv']=$filesB64->cv->name;
		}

		// decode CV and insert it in DB
		$store = new NxCV_StoreCV($cltConfig,$services->fs);

		// $oid=null;$isNew=null;
		return $store->storeCVObject($oCV,$fpath,$fcontent,$oid,$isNew, null, true);
	}

    function callAnalyser_post($filePath,&$oid,&$isNew)
	{
		//DebugBreak();
		
		require_once(GENERIS_PACKAGES.'cv/lib/cv/NxCV_cv.inc');
		require_once(GENERIS_PACKAGES.'cv/lib/cv/NxCV_ServiceFactory.inc');
		require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/NxCV_StoreCV.inc');

		$codeSwitch = trim(NX_HOST_SWITCH,'_');

		$codeClient = 'cvproc'; // to be put in host file...
		$services = new NxCV_ServiceFactory($this->ctxt,'holcim');
		$config = $services->getConfig();
       
		// get client config (inherit the main config in the same file)
		$clientConfigs = $config->getProperty('clients.upload.soap');
		if (isset($clientConfigs[$codeSwitch]))
		{
			$props = $clientConfigs[$codeSwitch];
			$cltConfig = new NxProperties($props,$config);
			$url = $cltConfig->getProperty('server.url',null);
		}
		if(!$url && isset($clientConfigs[$codeClient]))
		{
			$props = $clientConfigs[$codeClient];
			$cltConfig = new NxProperties($props,$config);
			$url = $cltConfig->getProperty('server.url',null);
		}
		if(!$url)
		{
			$url = $config->getProperty('server.url',null);
		}
		if(!$url)
		{
			$url = 'http://cvproc.presencesoft.net/cv/post/analyseCV.php';
		}

		// call WS : get site info and page
		require_once(NX_LIB.'curl/curl_http_client.php');
		$oCurl= new Curl_HTTP_Client(false);
		
		$postdata = array();
		$postdata['clientID'] = $codeClient;

		$file_field_array=array();
		$fname= basename($filePath);
		$file_field_array['file_cv']=$filePath;

		$res = $oCurl->send_multipart_post_data($url, $postdata, $file_field_array, $ip=null, $timeout=6000);
		
		if(!$res) {
			//self::trace('Exec callAnalyser_post : failed');
			///return false;
			//$oCVs[0]->object->person->firstName="-";
			$res = '{"object":{"person":{"firstName":"Abdelouahed","lastName":"Bamarjan"}}}';
		}

		// get result
		$oCVs = json_decode($res);
		if (!is_array($oCVs) || count($oCVs)==0)
			return false;
		
		// get cv object
		$oCV = $oCVs[0]->object;
		$filesB64= $oCVs[0]->files;
		$filesDesc=array();
		
		if(isset($filesB64->cv))
		{
			/*
			$fcontent['cv']=base64_decode($filesB64->cv->content);
			$fpath['cv']=$filesB64->cv->name;
			*/

			$filesDesc['cv']->src=base64_decode($filesB64->cv->content);
			$filesDesc['cv']->name=$filesB64->cv->name;
		}

		// decode CV and insert it in DB
		$store = new NxCV_StoreCV($cltConfig,$services->fs);

		// $oid=null;$isNew=null;
		return $store->storeCVObject($oCV,$filesDesc,$oid,$isNew);	
	}

	function convertToSwf($folderPath, $fileName) {

		$filePath = $folderPath.$fileName;
		
		$linuxExtension = ' > /dev/null 2>&1 ';
		if (substr(php_uname(), 0, 7) == "Windows")
		{
			$linuxExtension = '';
			$filePath = str_replace(array('/',"\\\\"), array("\\", "\\"), $filePath);
		}

		$pathParts = pathinfo($filePath);
		if( $pathParts['extension'] == 'pdf' ) {
			
			if( is_file($filePath.'.swf') ) {
				@unlink($filePath.'.swf');
			}
			
			// Chemin de l'exécutable (@todo : à mettre en property système)
			//$pPath = '/opt/local/bin/pdf2swf';
			$pPath = $GLOBALS["RECRUITMENT_PDF2SWF"];
			if (substr(php_uname(), 0, 7) == "Windows")
			{
				$pPath = str_replace(array('/',"\\\\"), array("\\", "\\"), $pPath);
			}
			// Options de conversion (Par défaut)
			$options = '-q -t -T 9 -G -f';
			// On essaye de convertir le fichier en gardant un rendu optimal
			shell_exec($pPath .' '.$options.' "'. $filePath .'" -o "'.$filePath.'.swf"'.$linuxExtension);
			if( ! is_file($filePath.'.swf') ) {
				// Le fichier n'a pas été créé (Problème sous Mac/Linux). On essaye de le recréer en convertissant texte et images en bitmap
				$fOptions = $options . ' -O 2';
				shell_exec($pPath .' '.$fOptions.' "'. $filePath .'" -o "'.$filePath.'.swf"'.$linuxExtension);
			}
						
		}
				
	}
}
?>