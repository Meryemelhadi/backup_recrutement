<?php 

require_once(NX_XLIB.'lib/framework.inc');
require_once(NX_LIB.'NxData_ArrayRecords.inc');

class lib_recruitment_candidates_services_directory
{
	var $ctxt;
	var $directory = 'packages/recruitment/candidates/directory/';

	function lib_recruitment_candidates_services_directory($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function loadRecord() {
		
	}
	
	function insertReadState($userOid, $candidateOid) {
		
		$db = &$this->ctxt->getDB($this->error);
		// insert read state
		$db->queryWithData("INSERT INTO _rct_candidate_read_state (_user_oid, _candidate_oid) SELECT '$userOid', '$candidateOid' FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_read_state WHERE _user_oid='$userOid' AND _candidate_oid='$candidateOid')");
		
		// get flag state
		
	}
	
	function saveCategoryAssociations($candidatesOids, $categoryOid) {
	
		if( trim($categoryOid) == '?' || trim($candidatesOids) == '' ) {
			return false;
		}

		$oids = explode('|', trim($candidatesOids, '|'));
		$db = &$this->ctxt->getDB($this->error);
		$inseredOids = array();
		
		for($i=0; $i<count($oids); $i++) {
			$oid = $oids[$i];
			
			$lastInsertId = '';
			
			$db->queryWithData("INSERT INTO _rct_candidate_category_assoc (_key, _val) SELECT '$oid', '$categoryOid' FROM DUAL WHERE NOT EXISTS (SELECT * FROM _rct_candidate_category_assoc WHERE _key='$oid' AND _val='$categoryOid')");
			
			$added = false;
			$db->getLastInsertID($lastInsertId);
			if( trim($lastInsertId) != '' ) {
				$added = true;
				$inseredOids[] = $oid;
			}
		}
		
		if( count($inseredOids) > 0 ) {
			
			$oids = implode(',', $inseredOids);
			
			// Cas ou il y a déjà des valeurs stockées dans le champ
			$db->queryWithData("UPDATE _rct_candidate SET _category_oid = CONCAT(_category_oid, '$categoryOid|') WHERE _category_oid <> '' AND _oid IN ($oids)");
			// Cas ou le champ est vide
			$db->queryWithData("UPDATE _rct_candidate SET _category_oid = CONCAT(_category_oid, '|$categoryOid|') WHERE _category_oid == '' AND _oid IN ($oids)");			
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
		
		// Nom du DML à utiliser
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
		
		// Nom du DML à utiliser
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

		// Lancement du téléchargement
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
	
	function uploadFiles($candidateOid) {

		$uploadPath = $this->getFilesUploadPath($candidateOid);
		$this->ctxt->setProperty('candidate_oid', $candidateOid);
		
		$cvPath = $this->directory.$candidateOid.'/cv/';
		$clPath = $this->directory.$candidateOid.'/cl/';
		
		
		$cvFullPath = $this->uploadFile('temp_cv_file', $uploadPath.'cv/');
		$clFullPath = $this->uploadFile('temp_cl_file', $uploadPath.'cl/');
		
		
		if( $cvFullPath !== false ) {	
		
			nxLog('Nadir: cvFullPath '. $cvFullPath);
			
			$record = new PersistentObject('rct_candidate.manage_cv@recruitment','db', array('oid'=>$candidateOid));
			if($record->isOk()) {			
				$record->cv_path->readFromFile('cv.pdf',$this->directory.$candidateOid.'/cv/',false,file_get_contents($cvFullPath));
				$record->store('rct_candidate.manage_cv@recruitment','update','db', array('oid'=>$candidateOid));
			}
			$this->convertToSwf(dirname($record->cv_path->path).'/', basename($record->cv_path->path));
			unlink($cvFullPath);
		}
		
		if( $clFullPath !== false ) {
		
			nxLog('Nadir: clFullPath '. $clFullPath);
		
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
			// Enregistrement du nom du fichier dans la base de données			
//			$this->storeInDB('cv', $candidateOid, $_FILES['temp_cv_file']['name'], $uploadPath);
//		}
//		
//		if( $this->uploadFile('temp_cl_file', $uploadPath.'cl/') === true ) {
			// Enregistrement du nom du fichier dans la base de données
//			$this->storeInDB('cl', $candidateOid, $_FILES['temp_cl_file']['name'], $uploadPath);
//		}
	}
	
//	function storeInDB($fileType, $candidateOid, $fileName, $uploadPath) {
//		
		// Nom du DML à utiliser
//		$dmlName = 'rct_candidate.manage_'.$fileType;
		// Initialisation des properties
//		$this->ctxt->setProperty('candidate_oid', $candidateOid);
//		$this->ctxt->setProperty('file_name', addslashes($fileName));
		// Enregistrement dans la base de données
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