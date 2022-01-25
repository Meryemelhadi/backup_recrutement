<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');

class lib_recruitment_vacancies_services_directory
{
	var $ctxt;

	function lib_recruitment_vacancies_services_directory($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function loadRecord() {
		
	}
	
	function init_list_search() {

		// check if date is selected and if not default is current day
		if (!isset($_REQUEST['update_date_min'])) {
			$from = date('d/m/Y',strtotime('-10 days'));
			$_REQUEST['update_date_min'] = $from;
		}	
	}
	
	function download($oid, $objectOid, $path, $handler, $oidField) {

		$this->ctxt->setProperty('oid', $oid);
		$fileRecord = $this->ctxt->getRecord($handler,null,'db',false,null,null);
			
		$fileName = $fileRecord->file_name;
		$filePath = $this->getFilesUploadPath($fileRecord->$oidField, $path).$fileName;
			
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
	
	function removeFiles($objectOid, $handler, $path) 
	{
		if(!isset($_REQUEST['files_to_delete']))
			return;
		
		$uploadPath = $this->getFilesUploadPath($objectOid, $path);
		foreach($_REQUEST['files_to_delete'] as $key=>$value)
		{
			$this->ctxt->setProperty('oid', $value);
			$fileRecord = $this->ctxt->getRecord($handler,null,'db',false,null,null);
			@unlink($uploadPath.$fileRecord->file_name);			
			$this->ctxt->deleteRecords($handler,$this->ctxt->getRecords($handler,null,'db'),'db',true);
		}
	}	
	
	/*
		Gère l'upload des fichiers attachés au dossiers et aux interviews
	*/	
	function uploadAnnouncementFiles($objectOid, $handler, $path) {
		
		$path = $this->ctxt->getProperty('pathUpload').$path.'/'.$objectOid;
		if( ! is_dir($path) ) {
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path);
		}
		$uploadPath = $path .'/';
		$fieldName = 'file_attachement';
		$stack = array();
	
		if(isset($_FILES[$fieldName]['name']))
		foreach($_FILES[$fieldName]['name'] as $key=>$value) {
			if( empty($_FILES[$fieldName]['name'][$key]) ) {
				continue;
			}
			
			$fileName 		= $_FILES[$fieldName]['name'][$key];
			$tempFileName 	= $_FILES[$fieldName]['tmp_name'][$key];
			// Clear upload path
			$completePath	= $uploadPath.$fileName;
						
			move_uploaded_file($tempFileName, $completePath);
			chmod($completePath,0644);
			
			$this->ctxt->setProperty('object_oid', $objectOid);
			$this->ctxt->setProperty('file_name', addslashes($fileName));
			
			
			$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);
			
			array_push($stack, addslashes($fileName));
			
			
		}
		
		return $stack;
	}	
	
	
	/*
		Gère l'upload des fichiers attachés au dossiers
	*/	
	function uploadFiles($objectOid, $handler, $path) {

		$fieldName = 'file_attachement';
		$stack = array();

		if(isset($_FILES[$fieldName]['name']))
		{
			$uploadPath = $this->getFilesUploadPath($objectOid, $path);
			
			foreach($_FILES[$fieldName]['name'] as $key=>$value) {
				
				if( empty($_FILES[$fieldName]['name'][$key]) ) {
					continue;
				}
				
				$fileName 		= $_FILES[$fieldName]['name'][$key];
				$tempFileName 	= $_FILES[$fieldName]['tmp_name'][$key];
				// Clear upload path
				$completePath	= $uploadPath.$fileName;
							
				move_uploaded_file($tempFileName, $completePath);
				chmod($completePath,0644);
				
				$this->ctxt->setProperty('object_oid', $objectOid);
				$this->ctxt->setProperty('file_name', addslashes($fileName));
				
				$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);	
				
			}
		}
		
		return $stack;
	}

	/*
		Gère l'upload des fichiers attachés aux interviews
	*/
	function uploadInterviewFiles($objectOid, $handler_candidate, $handler_interviewer, $path) {

		//DebugBreak();

		$uploadPath_candidate = $this->getFilesUploadPath($objectOid."_candidate", $path);

		$uploadPath_interviewers = $this->getFilesUploadPath($objectOid."_interviewers", $path);

		$fieldName_array = array('_candidate'=>'file_attachement_candidate','_interviewer'=>'file_attachement_interviewers');
		$stack = array();
		$test=$_FILES;
        foreach($fieldName_array as $key_array=>$fieldName)
		{
			if(isset($_FILES[$fieldName]['name']))
				foreach($_FILES[$fieldName]['name'] as $key=>$value)
				{
					if( empty($_FILES[$fieldName]['name'][$key]) ) 
						continue;
					
					$fileName 		= $_FILES[$fieldName]['name'][$key];
					$tempFileName 	= $_FILES[$fieldName]['tmp_name'][$key];
					// Clear upload path
					$completePath	= ${'uploadPath'.$key_array}.$fileName;
								
					move_uploaded_file($tempFileName, $completePath);

					chmod($completePath,0644);
					
					$this->ctxt->setProperty('object_oid', $objectOid);
					$this->ctxt->setProperty('file_name', addslashes($fileName));
					
					$this->ctxt->putRecord($null=null, $test=${'handler'.$key_array}, 'insert', 'db', 'Object', null);
					
					
					array_push($stack, array($fieldName ,addslashes($fileName)));					
				}
		}
		
		return $stack;
	}
	
	/**
		Fonction utilisée pour la programmation d'interviews et l'envoi de mails de manière massive
		L'upload se fait pour le premier élément et on copie le dossier créé pour le reste des items
	*/
	function uploadNCopyInterview($inseredOids, $handler_candidate, $handler_interviewer, $path) 
	{
		$stack = array(); // Liste des fichiers pour enregistrement dans la base de données  
		$folderToCopy = ''; // Chemin du dossier à dupliquer
		for($i=0; $i<count($inseredOids); $i++) {			
					
			$dbOid = $inseredOids[$i][0]; // Liste des oids des entretiens ou des emails
			$candidateOid = $inseredOids[$i][1]; // pas besoin pour l'instant ...
				
			if( $i == 0 ) 
			{
				$stack = $this->uploadInterviewFiles($dbOid, $handler_candidate, $handler_interviewer, $path);
				//$folderToCopy = $this->getFilesUploadPath($dbOid, $path);
			} 
			else 
			{
				// Nomenclature du dossier créé
				$newFolder = $this->getFilesUploadPath($dbOid, $path);
				
				//$this->recurse_copy($folderToCopy, $newFolder);

				$fs = new NxPlug_FileSys($this->ctxt);	
				$fs->copyDir($folderToCopy,$newFolder,$mode=0777);

				// Enregistrement dans la base de données
				$this->ctxt->setProperty('object_oid', $dbOid);				
				
				for($j=0; $j<count($stack); $j++) 
				{
					$this->ctxt->setProperty('file_name', $stack[$j]);
					$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);	
				}
			}
		}
	}

	function uploadNCopy($inseredOids, $handler, $path) 
	{
		$stack = array(); // Liste des fichiers pour enregistrement dans la base de donnÃ©es  
		$folderToCopy = ''; // Chemin du dossier Ã  dupliquer

		for($i=0; $i<count($inseredOids); $i++) 
		{
			$dbOid = $inseredOids[$i][0]; // Liste des oids des entretiens ou des emails
			$candidateOid = $inseredOids[$i][1]; // pas besoin pour l'instant ...
				
			if( $i == 0 ) 
			{
				$stack = $this->uploadFiles($dbOid, $handler, $path);
				$folderToCopy = $this->getFilesUploadPath($dbOid, $path);
			} 
			else 
			{
				// Nomenclature du dossier crÃ©Ã©
				$newFolder = $this->getFilesUploadPath($dbOid, $path);
				
				$fs = new NxPlug_FileSys($this->ctxt);	
				$fs->copyDir($folderToCopy,$newFolder,$mode=0777);

				// Enregistrement dans la base de donnÃ©es
				$this->ctxt->setProperty('object_oid', $dbOid);				
				for($j=0; $j<count($stack); $j++) {
					$this->ctxt->setProperty('file_name', $stack[$j]);
					$this->ctxt->putRecord($null=null, $handler, 'insert', 'db', 'Object', null);	
				}
			}
			
		}
	}
	
	function getFilesUploadPath($objectOid, $path) 
	{
			
		$path = $this->ctxt->getProperty('pathUpload').'packages/recruitment/'.$path.'/'.$objectOid;
		if( ! is_dir($path) ) {
			$fs = new NxPlug_FileSys($this->ctxt);
			$fs->createTree($path);
		}
		return $path .'/';
	}
	
	function recurse_copy($src,$dst) 
	{ 
	    $dir = opendir($src); 
	    @mkdir($dst); 
	    while(false !== ( $file = readdir($dir)) ) { 
	        if (( $file != '.' ) && ( $file != '..' )) { 
	            if ( is_dir($src . '/' . $file) ) { 
	                $this->recurse_copy($src . '/' . $file,$dst . '/' . $file); 
	            } 
	            else { 
	                copy($src . '/' . $file,$dst . '/' . $file); 
	            } 
	        } 
	    } 
	    closedir($dir); 
	}
	
	function ftp_dir($url) 
	{ 
		 $FTP_HOST = "176.31.110.145" ; 
		 $FTP_USERNAME = "root" ; 
		 $FTP_PASSWD = "kQgRzZD2" ; 
		 $FTP_PORT = 22 ; 
		   
		 $con = ftp_connect($FTP_HOST) ; 
		 if (!$con) 
			return false ; 
		else nxlog("con faite");
		   
		 if (!ftp_login($con, $FTP_USERNAME, $FTP_PASSWD)) 
			return false ; 
		else nxlog("login  done");
		   
		  
		 if (ftp_site($con,"chmod 0777 ".$url))
		 nxlog("commande execut?e"); 
		  
		 ftp_close($con) ; 
		  
		 return true ; 
	 } 


function pdf_export_win($oid,$vacancy_oid,$interview_oid,$user_oid)
  {   
      
   $filePath=substr(GENERIS_PACKAGES,0,-1).'/recruitment/www/nx/controls/wkhtmltopdf/tmp/tmp_'.$oid.'.pdf';
   $login=$_SESSION[_NX_user]->props[user_id];
   $db = &$this->ctxt->getDB($this->ctxt->error);
   $password=$db->queryWithData("SELECT _password FROM _user WHERE _oid=".$_SESSION[_NX_user]->props[uoid]);
   // Cr?er le fichier PDF 
   
   $cmd = substr(GENERIS_PACKAGES,0,-1).'/recruitment/www/nx/controls/wkhtmltopdf/wkhtmltopdf.exe --collate --cookie-jar '.substr(GENERIS_PACKAGES,0,-1).'/recruitement/www/nx/controls/wkhtmltopdf/tmp/my.jar --post user_id '.$login.' --post password '.$password[0][_password].' "http://www.grecrute.local/user/login.php?nxo=login&nxs=process&page=%2Frecruitment%2Fvacancies%2Fadmin%2Fdirectory.php%3Fnxo%3Dpdf_interview_synthesis%26nxs%3D%26vacancy_oid%3D'.$vacancy_oid.'%26oid%3D'.$oid.'%26interview_oid%3D'.$interview_oid.'%26user_oid%3D'.$user_oid.'&from=/&uoid=" '.$filePath;
   
   nxLog("EXPORT PDF :" . $cmd);
   
   exec($cmd);
   

   //t?lecharger le fichier
   header('Content-Description: File Transfer');
   header('Content-Type: application/octet-stream');
   header('Content-Disposition: attachment; filename="Evaluation.pdf"');
   header('Content-Transfer-Encoding: binary');
   header('Expires: 0');
   header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
   header('Pragma: public');
   header('Content-Length: ' . filesize($filePath));
   ob_clean();
   flush();
   @readfile($filePath);
   
   //Supprimer le fichier pdf cr?e
   unlink($filePath);
  
  }
	
	//Extraction de la fiche d'evaluation en format PDF
	function pdf_export($oid,$vacancy_oid,$interview_oid,$user_oid)
		{   
			$cmd_path = GENERIS_PACKAGES.'converters/lib/wkhtmltopdf/linux/';
			$tmp_path = GENERIS_PACKAGES.'converters/lib/wkhtmltopdf/linux/tmp/';
		    	$this->ftp_dir($tmp_path);
nxlog("droit 777 test");
			//$filePath=substr(GENERIS_PACKAGES,0,-1).'/recruitment/www/nx/controls/wkhtmltopdf/tmp/tmp_'.$oid.'.pdf';
			$filePath=$tmp_path.'tmp_'.$oid.'.pdf';

			$login=$_SESSION[_NX_user]->props[user_id];
			$db = &$this->ctxt->getDB($this->ctxt->error);
			$password=$db->queryWithData("SELECT _password FROM _user WHERE _oid=".$_SESSION[_NX_user]->props[uoid]);
			/*
			// Creer le fichier PDF 		
			$cmd_path .= 'wkhtmltopdf-i386';
			// $cmd = $cmd_path . '--collate --cookie-jar /nx/controls/wkhtmltopdf/tmp/my.jar --post user_id '.$login.' --post password '.$password[0][_password].' '.DOMAIN_NAME.'"/user/login.php?nxo=login&nxs=process&page=%2Frecruitment%2Fvacancies%2Fadmin%2Fdirectory.php%3Fnxo%3Dpdf_interview_synthesis%26nxs%3D%26vacancy_oid%3D'.$vacancy_oid.'%26oid%3D'.$oid.'%26interview_oid%3D'.$interview_oid.'%26user_oid%3D'.$user_oid.'&from=/&uoid=" '.$filePath;
			$cmd = $cmd_path . ' --collate --cookie-jar '.$tmp_path.'my.jar --post user_id '.$login.' --post password '.$password[0][_password].' "'.DOMAIN_NAME.'/user/login.php?nxo=login&nxs=process&page=%2Frecruitment%2Fvacancies%2Fadmin%2Fdirectory.php%3Fnxo%3Dpdf_interview_synthesis%26nxs%3D%26vacancy_oid%3D'.$vacancy_oid.'%26oid%3D'.$oid.'%26interview_oid%3D'.$interview_oid.'%26user_oid%3D'.$user_oid.'&from=/&uoid=" '.$filePath;
			
			nxLog("EXPORT PDF :" . $cmd,'PDF');
			
			shell_exec($cmd);

			$cmd1=$cmd_path . ' --collate --cookie-jar '.$tmp_path.'my.jar  "'.DOMAIN_NAME.'/recruitment/vacancies/admin/directory.php?nxo=pdf_interview_synthesis&nxs=&vacancy_oid=1&interview_oid=4&oid=1&interview_oid=4&user_oid=1" '.$filePath;
			
			shell_exec($cmd1);
*/


			$cmd1=$cmd_path . ' --collate "www.google.com" '.$filePath;
			
			shell_exec($cmd1);

			
			
			
			//télecharger le fichier
			header('Content-Description: File Transfer');
			header('Content-Type: application/octet-stream');
			header('Content-Disposition: attachment; filename="Evaluation.pdf"');
			header('Content-Transfer-Encoding: binary');
			header('Expires: 0');
			header('Cache-Control: must-revalidate, post-check=0, pre-check=0');
			header('Pragma: public');
			header('Content-Length: ' . filesize($filePath));
			ob_clean();
			flush();
			@readfile($filePath);
			
			//Supprimer le fichier pdf crée
//			unlink($filePath);
exit();
		
		}

    //Extraction du calendrier en ICS
    function ics_export(){

        $db = &$this->ctxt->getDB($this->ctxt->error);
        $res=$db->queryWithData("SELECT _rct_interview._oid AS _oid ,_rct_interview._time_start AS _time_start, _rct_interview._time_end AS _time_end,
						_rct_interview._candidate_oid AS _candidate_oid, _rct_interview._comment as _comment, _rct_candidate._first_name as _first_name, _rct_candidate._last_name as _last_name FROM _rct_interview,_rct_interview_by, _rct_candidate WHERE
                        (_rct_interview_by._key=_rct_interview._oid AND _rct_interview._candidate_oid = _rct_candidate._oid AND (_rct_interview_by._val='".$_SESSION[_NX_user]->props[uoid]."' or _rct_interview_by._val in (select _oid from _user where `_interim` = '".$_SESSION[_NX_user]->props[uoid]."')))");

        $ics_data = "BEGIN:VCALENDAR\n";
        $ics_data .= "VERSION:2.0\n";
        $ics_data .= "PRODID:PHP\n";
        $ics_data .= "METHOD:PUBLISH\n";
        $ics_data .= "X-WR-CALNAME:Schedule\n";

        foreach ($res as $event)
        {
            $id = $event['_oid'];
            $ts = new DateTime($event['_time_start']);
            $start_date = $ts->format('Ymd');
            $start_time = $ts->format('His');
            $te = new DateTime($event['_time_end']);
            $end_date = $te->format('Ymd');
            $end_time = $te->format('His');
            $name = 'Candidat: '.$event['_first_name'].' '.$event['_last_name'];
            $location = 'Paris';
            $description = $event['_comment'];


            # Replace HTML tags
            $search = array("/<br>/","/&amp;/","/&rarr;/","/&larr;/","/,/","/;/");
            $replace = array("\\n","&","-->","<--","\\,","\\;");

            $name = preg_replace($search, $replace, $name);
            $location = preg_replace($search, $replace, $location);
            $description = preg_replace($search, $replace, $description);

            # Change TimeZone if needed
            $ics_data .= "BEGIN:VEVENT\n";
            $ics_data .= "DTSTART;TZID=Europe/Paris:".$start_date."T".$start_time."\n";
            $ics_data .= "DTEND;TZID=Europe/Paris:" . $end_date . "T" . $end_time . "\n";
            $ics_data .= "DTSTAMP;TZID=Europe/Paris:" . date('Ymd') . "T" . date('His') . "Z\n";
            //$ics_data .= "LOCATION:" . $location . "\n";
            $ics_data .= "DESCRIPTION:" . $description . "\n";
            $ics_data .= "SUMMARY:" . $name . "\n";
            $ics_data .= "UID:" . $id . "\n";
            $ics_data .= "SEQUENCE:0\n";
            $ics_data .= "END:VEVENT\n";

        }

        
        $ics_data .= "END:VCALENDAR\n";

        # Download the File
        $filename = "event_calendar.ics";
        header("Content-type:text/calendar");
        header("Content-Disposition: attachment; filename=$filename");
        echo $ics_data;
        exit;

    }

}