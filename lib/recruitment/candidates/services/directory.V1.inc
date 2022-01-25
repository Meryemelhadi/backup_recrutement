<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');

class lib_recruitment_candidates_services_directory
{
	var $ctxt;
	var $directory = 'packages/recruitment/candidates/directory/';

	function lib_recruitment_candidates_services_directory($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	function init_list_search() {

		if(isset($_REQUEST['town_oid']))
			$_REQUEST['town_oid'] = $this->replaceAccents($_REQUEST['town_oid']);

		if(isset($_REQUEST['full_text_search']))
			$_REQUEST['full_text_search'] = $this->replaceAccents($_REQUEST['full_text_search']);

		return;


		if(isset($_REQUEST['cancel']) && $_REQUEST['cancel']='true')
			return;

		// check if date is selected and if not default is current day
		if (!isset($_REQUEST['update_date_min'])) {
			$from = date('d/m/Y',strtotime('-10 days'));
			$_REQUEST['update_date_min'] = $from;
		}	
	}
	function loadRecord() {
		
	}

	function replaceAccents($str,$noquote=false) 
	{
        global $NX_CHARSET;
        if ($NX_CHARSET!='ISO-8859-1') {
			$str = utf8_decode($str);
		}

		$tofind = "¿¡¬√ƒ≈‡·‚„‰Â“”‘’÷ÿÚÛÙıˆ¯»… ÀËÈÍÎ«ÁÃÕŒœÏÌÓÔŸ⁄€‹˘˙˚¸ˇ—Ò'";
		$replac = "AAAAAAaaaaaaOOOOOOooooooEEEEeeeeCcIIIIiiiiUUUUuuuuyNn ";
		return(strtr($str,$tofind,$replac));	
	}
	
	function insertReadState($userOid, $candidateOid) {
		
		$db = &$this->ctxt->getDB($this->ctxt->error);

		// insert read state
		$db->query("INSERT INTO _rct_candidate_read_state (_user_oid, _candidate_oid, _read_time) SELECT '$userOid','$candidateOid' , NOW() FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_read_state WHERE _user_oid='$userOid' AND _candidate_oid='$candidateOid')");

		// get flag state
		
	}
	
	function saveCategoryAssociations($candidatesOids, $categoryOid) {
	
		if( trim($categoryOid) == '?' || trim($candidatesOids) == '' ) {
			return false;
		}

		$oids = explode('|', trim($candidatesOids, '|'));
		$db = &$this->ctxt->getDB($this->ctxt->error);
		$inseredOids = array();
		
		for($i=0; $i<count($oids); $i++) {
			$oid = $oids[$i];
			
			$lastInsertId = '';
			
			$db->queryWithData("INSERT INTO _rct_candidate_category_assoc (_key, _val) (SELECT '$oid', '$categoryOid' FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_category_assoc WHERE _key='$oid' AND _val='$categoryOid'))");
			
			$added = false;
			$db->getLastInsertID($lastInsertId);
			if( trim($lastInsertId) != '' ) {
				$added = true;
				$inseredOids[count($inseredOids)]= $oid;
			}
		}

		if( count($inseredOids) > 0 ) {
			
			$oids = implode(',', $inseredOids);

			// Cas ou il y a dÈj‡ des valeurs stockÈes dans le champ
			$db->queryWithData("UPDATE _rct_candidate SET _category_oid = CONCAT(_category_oid, '$categoryOid|') WHERE _category_oid <> '' and _oid IN ($oids)");
			// Cas ou le champ est vide
			$db->queryWithData("UPDATE _rct_candidate SET _category_oid = CONCAT(_category_oid, '|$categoryOid|') WHERE  _category_oid = '' AND _oid IN ($oids)");			
		}
		
		return $inseredOids;	
	}
	
	function saveAssociations($candidatesOids, $vacancyOid) {
		
		if( trim($vacancyOid) == '?' || trim($candidatesOids) == '' ) {
			return false;
		}
		$oids = explode('|', $candidatesOids);
		
		$errorCB=new NxErrorCB();
		$db = &$this->ctxt->getDB($errorCB);
		
		$inseredOids = array();
		
		for($i=0; $i<count($oids); $i++) {
			$oid = $oids[$i];
			
			$lastInsertId = '';
			
			$db->queryWithData("INSERT INTO _rct_candidate_vacancy (_candidate_oid, _vacancy_oid, _add_date) SELECT '$oid', '$vacancyOid', NOW() FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_vacancy WHERE _candidate_oid='$oid' AND _vacancy_oid='$vacancyOid')");
			
			$db->getLastInsertID($lastInsertId);
			
			if( trim($lastInsertId) != '' ) {
				$inseredOids[] = $oid;
			}
		}
		
		return $inseredOids;
	}
	
	function preview($candidateOid, $type) {
		
		// Nom du DML √† utiliser
		$dmlName = 'rct_candidate.manage_'.$type;
		// Initialisation des properties
		$this->ctxt->setProperty('candidate_oid', $candidateOid);
		// $url = '/files/'.DOMAIN_NAME.'/packages/recruitment/candidates/directory/'.$candidateOid.'/';
		
		$fileRecord = $this->ctxt->getRecord($dmlName,null,'db',false,null,null);

		if( $type == 'cv' ) {
			$fName = 'cv_path';
		}
		else {
			$fName = 'cl_path';
		}

		$path = $fileRecord->$fName->path;
		$url = $fileRecord->$fName->url;
		// check if SWF exists
		$pathSWF = $path.'.swf';

		if(!is_file($pathSWF))
		{
			// doesnt => generate it
			$folderPath=dirname($path).'/';
			$fileName=basename($path);
			$this->convertToSwf($folderPath, $fileName);
		}

		// if ok use SWF (else PDF)
		if(is_file($pathSWF))
		{
			$url .= '.swf';
			$this->ctxt->setProperty('swfUrl', $url);
		}
		else
		{
			$this->ctxt->setProperty('pdfUrl', $url);
		}
	}
	
	function download($candidateOid, $type) {
		
		// Nom du DML √† utiliser
		$dmlName = 'rct_candidate.manage_'.$type;
		// Initialisation des properties
		$this->ctxt->setProperty('candidate_oid', $candidateOid);
		
		$fileRecord = $this->ctxt->getRecord($dmlName,null,'db',false,null,null);

		$fileRecord = $this->ctxt->getRecord($dmlName,null,'db',false,null,null);

		if( $type == 'cv' ) {
			$fName = 'cv_path';
		}
		else {
			$fName = 'cl_path';
		}

		$filePath = $fileRecord->$fName->path;
		$fileName = basename($filePath);

		$url = $fileRecord->$fName->url;

		// Lancement du t√©l√©chargement
		header("Content-Type: application/octet-stream");
		header('Content-Disposition: attachment; filename="'.$fileName.'"');
		header("Content-Length: " .(string)(filesize($filePath)) );

		if(preg_match('/msie|(microsoft internet explorer)/i', $_SERVER['HTTP_USER_AGENT'])) {
			header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
			header('Pragma: public');
		} else {
		  header('Pragma: no-cache');
		}
		@readfile($filePath);		
	}
	
	
	/**		
		@todo: Invoquer le service de conversion en pdf pour les CV n'ayant pas pu √™tre analys√©s et pour les lettres de motivation
		Pour l'instant, la m√©thode g√®re l'ajout & l'√©dition, scinder s'il y a lieu pour g√©rer des traitements sp√©cifiques
	*/
	
	function saveNewCV() {
		return $this->saveCV('add');
	}
	
	function saveExistingCV() {
		return $this->saveCV('edit');
	}
	
	function saveCV($mode) {
		// D√©placement des fichiers dans un endroit temporaire
		$tempPath = $this->ctxt->getProperty('pathUpload').$this->directory.uniqid().'/';
		
		$fs = new NxPlug_FileSys($this->ctxt);
		$fs->createTree($tempPath .'cv/');
		$fs->createTree($tempPath .'cl/');
		
		$cvFullPath = $this->uploadFile('temp_cv_file', $tempPath.'cv/');
		$clFullPath = $this->uploadFile('temp_cl_file', $tempPath.'cl/');
		
		$candidateOid = null;

		$savePost = true;
		if( $cvFullPath !== false ) {
		
			// call analyser
			$oid=null;
			$isNew=null;
			$cvAnalyse = $this->callAnalyser($cvFullPath,$oid,$isNew);

			if ($cvAnalyse) {
				$savePost = false;
				$candidateOid = $oid;
				$this->ctxt->setProperty('candidate_oid', $candidateOid);
				$record = new PersistentObject('rct_candidate.manage_cv@recruitment','db', array('oid'=>$candidateOid));
			}
		}
		
		// Echec de l'analyse ou pas de CV, on sauvegarde la fiche avec les donn√©es re√ßues en post
		if( $savePost === true ) {

			if( $mode == 'add' ) {
				
				$this->ctxt->putRecord($this->ctxt->getRecord('rct_candidate.add@recruitment','page.records','post',false,null,null),'rct_candidate.add@recruitment','insert','db','Object',null);
				// @todo: remplacer par un select max suite au bug framework avec les ss-formulaires
				$candidateOid = $this->ctxt->getLastInsertID('db');
				
				
			} else if ( $mode == 'edit' ) {
			
				$this->ctxt->putRecord($this->ctxt->getRecord('rct_candidate.edit@recruitment','page.records','post',false,null,null),'rct_candidate.edit_process@recruitment','update','db','Object',null);
				$candidateOid = isset($_REQUEST["oid"])?$_REQUEST["oid"]:"";
			
			}
			$this->ctxt->setProperty('candidate_oid', $candidateOid);

			// Enregistrement du chemin de la pi√®ce jointe transmise
			if( $cvFullPath !== false ) {
				$record = new PersistentObject('rct_candidate.manage_cv@recruitment','db', array('oid'=>$candidateOid));
				if($record->isOk()) {
					// @todo: Appeler le webservice de conversion vers pdf
					$record->cv_path->readFromFile('cv.pdf',$this->directory.$candidateOid.'/cv/',false,file_get_contents($cvFullPath));
					$record->store('rct_candidate.manage_cv@recruitment','update','db', array('oid'=>$candidateOid));
				}
			}
		}

		if( $record ) {
			if($record->isOk()) {
				$this->convertToSwf(dirname($record->cv_path->path).'/', basename($record->cv_path->path));
			}
		}
		

		// upload cover letter
		if( $clFullPath !== false && !is_null($candidateOid) ) {
		
			$record = new PersistentObject('rct_candidate.manage_cl@recruitment','db', array('oid'=>$candidateOid));
			if($record->isOk()) {
				$record->cl_path->readFromFile('cl.pdf',$this->directory.$candidateOid.'/cl/',false,file_get_contents($clFullPath));
				$record->store('rct_candidate.manage_cl@recruitment','update','db', array('oid'=>$candidateOid));
				$this->convertToSwf(dirname($record->cl_path->path).'/', basename($record->cl_path->path));
			}
		}
		
		//$fs->rmDir($tempPath);
		
		return $candidateOid;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	function uploadFiles($candidateOid=null) {

		
		
		/*
		if( $cvFullPath !== false ) {
			
			// call analyser
			$oid=null;
			$isNew=null;
			$cvAnalyse = $this->callAnalyser($cvFullPath,$oid,$isNew);
			
			if (!$cvAnalyse)
			{
				// echec analyse => stocker le CV en attachement simple.				
				$record = new PersistentObject('rct_candidate.manage_cv@recruitment','db', array('oid'=>$candidateOid));
				if($record->isOk()) {			
					$record->cv_path->readFromFile('cv.pdf',$this->directory.$candidateOid.'/cv/',false,file_get_contents($cvFullPath));
					$record->store('rct_candidate.manage_cv@recruitment','update','db', array('oid'=>$candidateOid));
				}
				$this->convertToSwf(dirname($record->cv_path->path).'/', basename($record->cv_path->path));
			}
			unlink($cvFullPath);
		}
		*/




/*
		$uploadPath = $this->getFilesUploadPath($candidateOid);
		
		
		$cvPath = $this->directory.$candidateOid.'/cv/';
		$clPath = $this->directory.$candidateOid.'/cl/';
		
		
		$cvFullPath = $this->uploadFile('temp_cv_file', $uploadPath.'cv/');
		$clFullPath = $this->uploadFile('temp_cl_file', $uploadPath.'cl/');
*/		
		
		if( $cvFullPath !== false )
		{
			// call analyser
			$oid=null;
			$isNew=null;

			$cvAnalyse = $this->callAnalyser($cvFullPath,$oid,$isNew);

			if (!$cvAnalyse) {
				$candidateOid = $oid;
			}
			
			if( !is_null($candidateOid) ) {
				
				$this->ctxt->setProperty('candidate_oid', $candidateOid);				
				$record = new PersistentObject('rct_candidate.manage_cv@recruitment','db', array('oid'=>$candidateOid));
				if($record->isOk()) {			
					$record->cv_path->readFromFile('cv.pdf',$this->directory.$candidateOid.'/cv/',false,file_get_contents($cvFullPath));
					$record->store('rct_candidate.manage_cv@recruitment','update','db', array('oid'=>$candidateOid));
				}
				$this->convertToSwf(dirname($record->cv_path->path).'/', basename($record->cv_path->path));
			}
			
			
			
			
			
			
			
			
			unlink($cvFullPath);
		}
		
		if( $clFullPath !== false ) {

			if ($cvAnalyse)
			{
				// si analyse ok, utiliser l'oid resultant de l'analyse, pour attacher la LM sur la meme fiche...
				$candidateOid = $oid;
			}

			$record = new PersistentObject('rct_candidate.manage_cl@recruitment','db', array('oid'=>$candidateOid));
			if($record->isOk()) {
				$record->cl_path->readFromFile('cl.pdf',$this->directory.$candidateOid.'/cl/',false,file_get_contents($clFullPath));
				$record->store('rct_candidate.manage_cl@recruitment','update','db', array('oid'=>$candidateOid));
			}
			$this->convertToSwf(dirname($record->cl_path->path).'/', basename($record->cl_path->path));
			unlink($clFullPath);
		}


//
//		if( $this->uploadFile('temp_cv_file', $uploadPath.'cv/') === true ) {
			// Enregistrement du nom du fichier dans la base de donn√©es			
//			$this->storeInDB('cv', $candidateOid, $_FILES['temp_cv_file']['name'], $uploadPath);
//		}
//		
//		if( $this->uploadFile('temp_cl_file', $uploadPath.'cl/') === true ) {
			// Enregistrement du nom du fichier dans la base de donn√©es
//			$this->storeInDB('cl', $candidateOid, $_FILES['temp_cl_file']['name'], $uploadPath);
//		}
	}
	
	
	
	
	
	
	
	
//	function storeInDB($fileType, $candidateOid, $fileName, $uploadPath) {
//		
		// Nom du DML √† utiliser
//		$dmlName = 'rct_candidate.manage_'.$fileType;
		// Initialisation des properties
//		$this->ctxt->setProperty('candidate_oid', $candidateOid);
//		$this->ctxt->setProperty('file_name', addslashes($fileName));
		// Enregistrement dans la base de donn√©es
//		
//		
//
//		
//		
//		/*
//		$fromPath  = $fpath;
//		$toDir = $uploadPath.$fileType.'/';
//		if ($fileContent)
//			$cvRec->cv_path->readFromFile($fromPath,$toDir,false,$fileContent);
//		*/	
//			
//			
//			
//			
//			
//		
//		
//		$this->ctxt->putRecord($null=null, $dmlName, 'update', 'db', 'Object', null);	
//	}
	
	function uploadFile($formName, $uploadPath) {
		
		if( ! empty($_FILES[$formName]['name']) ) {
			
			$fileName 		= $_FILES[$formName]['name'];
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
	
	function getFilesUploadPath($candidateOid) {
			
		$path = $this->ctxt->getProperty('pathUpload').$this->directory.$candidateOid;
		if( ! is_dir($path) ) {
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path .'/cv');
			$fs->createTree($path .'/cl');
		}
		return $path .'/';
	}
	
	function callAnalyser($filePath,&$oid,&$isNew) {
		include_once(NX_DIS.'nusoap/lib/nusoap.php');
		require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
		require_once(GENERIS_ROOT.'nx/conf/packages/cv/lib/cv/NxCV_cv.inc');
		require_once(GENERIS_ROOT.'nx/conf/packages/cv/lib/cv/NxCV_ServiceFactory.inc');
		require_once(GENERIS_ROOT.'nx/conf/packages/recruitment/lib/recruitment/NxCV_StoreCV.inc');

		$codeClient = 'cvproc'; // to be put in host file...
		$services = new NxCV_ServiceFactory($this,'holcim');
		$config = $services->getConfig();

		// get client config (inherit the main config in the same file)
		$clientConfigs = $config->getProperty('clients.upload.soap');
		if (isset($clientConfigs[$codeClient]))
		{
			$props = $clientConfigs[$codeClient];
			$cltConfig = new NxProperties($props,$config);
		}
		else
			$cltConfig = $config;

		// get CV files and encode them in B64
		$fileName = basename($filePath);

		$fileContent=$services->fs->file_get_contents($filePath,'rb');
		$b64fileContent=base64_encode($fileContent);
		$filesB64[$fileName] = $b64fileContent;

		nxLog('------ NAdir : '.$filePath);
		// call server
		$soap_url = $cltConfig->getProperty('server.url','http://cvproc.presencemedia.ma/cv/soap/analyseCV.php');
		$client = new nusoap_client($soap_url,false);

		$filesJSON = json_encode(array('cv' => array('content'=>$b64fileContent,'name'=>$fileName)));
		$paramsJSON= json_encode(array('object'=>'true','pdf'=>'true','src'=>'true'));
		$parametres = array(
			'cltID' => $codeClient,
			'filesJSON'=>$filesJSON,
			'paramsJSON'=>$paramsJSON
			); 
		$res = $client->call('analyseCV', $parametres,true);
		
		nxLog('------- -Nadir ');
		nxLog($res);
		
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

		$oid=null;$isNew=null;
		return $store->storeCVObject($oCV,$fpath,$fcontent,$oid,$isNew);
	}

	function convertToSwf($folderPath, $fileName) {

		$filePath = $folderPath.$fileName;
		
		$linuxExtension = ' > /dev/null 2>&1 &';
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
			
			// Chemin de l'ex√©cutable (@todo : √† mettre en property syst√®me)
			//$pPath = '/opt/local/bin/pdf2swf';
			$pPath = $GLOBALS["RECRUITMENT_PDF2SWF"];
			if (substr(php_uname(), 0, 7) == "Windows")
			{
				$pPath = str_replace(array('/',"\\\\"), array("\\", "\\"), $pPath);
			}
			// Options de conversion (Par d√©faut)
			$options = '-q -t -T 9 -G -f';
			// On essaye de convertir le fichier en gardant un rendu optimal
			shell_exec($pPath .' '.$options.' "'. $filePath .'" -o "'.$filePath.'.swf"'.$linuxExtension);
			if( ! is_file($filePath.'.swf') ) {
				// Le fichier n'a pas √©t√© cr√©√© (Probl√®me sous Mac/Linux). On essaye de le recr√©er en convertissant texte et images en bitmap
				$fOptions = $options . ' -O 2';
				shell_exec($pPath .' '.$fOptions.' "'. $filePath .'" -o "'.$filePath.'.swf"'.$linuxExtension);
			}
						
		}
				
	}
	
}