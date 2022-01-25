<?php 

require_once(NX_XLIB.'lib/framework.inc');

class lib_recruitment_candidates_services_directory
{
	var $ctxt;

	function lib_recruitment_candidates_services_directory($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function loadRecord() {
		
	}
	
	function saveAssociations($candidatesOids, $vacancyOid) {
		
		if( trim($vacancyOid) == '?' || trim($candidatesOids) == '' ) {
			return false;
		}
		$oids = explode('|', $candidatesOids);
		$db = &$this->ctxt->getDB($this->error);
		
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
		
		$fileRecord = $this->ctxt->getRecord($dmlName,null,'db',false,null,null);
		
		$url = '/files/'.DOMAIN_NAME.'/packages/recruitment/candidates/directory/'.$candidateOid.'/';
		
		if( $type == 'cv' ) {
			$url = $url .'cv/'. $fileRecord->cv_path .'.swf';
		} else {
			$url = $url .'cl/'. $fileRecord->cl_path .'.swf';
		}
		
		$this->ctxt->setProperty('swfUrl', $url);
	}
	
	function download($candidateOid, $type) {
		
		// Nom du DML à utiliser
		$dmlName = 'rct_candidate.manage_'.$type;
		// Initialisation des properties
		$this->ctxt->setProperty('candidate_oid', $candidateOid);
		
		$fileRecord = $this->ctxt->getRecord($dmlName,null,'db',false,null,null);
		
		if( $type == 'cv' ) {
			$fileName = $fileRecord->cv_path;
			$filePath = $this->getFilesUploadPath($candidateOid) .'cv/'. $fileName;
		} else {
			$fileName = $fileRecord->cl_path;
			$filePath = $this->getFilesUploadPath($candidateOid) .'cl/'. $fileName;
		}
		
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

		if( $this->uploadFile('temp_cv_file', $uploadPath.'cv/') === true ) {
			// Enregistrement du nom du fichier dans la base de données			
			$this->storeInDB('cv', $candidateOid, $_FILES['temp_cv_file']['name']);
		}
		
		if( $this->uploadFile('temp_cl_file', $uploadPath.'cl/') === true ) {
			// Enregistrement du nom du fichier dans la base de données
			$this->storeInDB('cl', $candidateOid, $_FILES['temp_cl_file']['name']);
		}
	}
	
	function storeInDB($fileType, $candidateOid, $fileName) {
		
		// Nom du DML à utiliser
		$dmlName = 'rct_candidate.manage_'.$fileType;
		// Initialisation des properties
		$this->ctxt->setProperty('candidate_oid', $candidateOid);
		$this->ctxt->setProperty('file_name', addslashes($fileName));
		// Enregistrement dans la base de données
		$this->ctxt->putRecord($null=null, $dmlName, 'update', 'db', 'Object', null);	
	}
	
	function uploadFile($formName, $uploadPath) {
		
		if( ! empty($_FILES[$formName]['name']) ) {
			
			$fileName 		= $_FILES[$formName]['name'];
			$tempFileName 	= $_FILES[$formName]['tmp_name'];
			// Clear upload path
			$completePath	= $uploadPath.$fileName;
						
			move_uploaded_file($tempFileName, $completePath);
			chmod($completePath,0644);

			$this->convertToSwf($uploadPath, $fileName);
			
			return true;
		}
		
		return false;
	}
	
	function getFilesUploadPath($candidateOid) {
			
		$path = $this->ctxt->getProperty('pathUpload').'packages/recruitment/candidates/directory/'.$candidateOid;
		if( ! is_dir($path) ) {
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path .'/cv');
			$fs->createTree($path .'/cl');
		}
		return $path .'/';
	}
	
	function convertToSwf($folderPath, $fileName) {
		
		$filePath = $folderPath.$fileName;
		$pathParts = pathinfo($filePath);
		if( $pathParts['extension'] == 'pdf' ) {
			
			if( is_file($filePath.'.swf') ) {
				@unlink($filePath.'.swf');
			}
			
			// Chemin de l'exécutable (@todo : à mettre en property système)
			//$pPath = '/opt/local/bin/pdf2swf';
			$pPath = $GLOBALS["RECRUITMENT_PDF2SWF"];
			
			// Options de conversion (Par défaut)
			$options = '-q -t -T 9 -G -f';
			// On essaye de convertir le fichier en gardant un rendu optimal
			exec($pPath .' '.$options.' "'. $filePath .'" -o "'.$filePath.'.swf"');
			
			if( ! is_file($filePath.'.swf') ) {
				// Le fichier n'a pas été créé (Problème sous Mac/Linux). On essaye de le recréer en convertissant texte et images en bitmap
				$fOptions = $options . ' -O 2';
				exec($pPath .' '.$fOptions.' "'. $filePath .'" -o "'.$filePath.'.swf"');
			}
						
		}
				
	}
	
}