<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');

class lib_recruitment_vacancies_services_annonce
{
	var $ctxt;

	function lib_recruitment_vacancies_services_annonce($ctxt)
	{
		$this->ctxt = $ctxt;
		Framework::setContext($this->ctxt = $ctxt);
	}
	
	function loadRecord() {
		
	}

	function getConfig() {
		if ($this->config)
			return $this->config;

		include_once(NX_LIB.'NxConfig.inc');
		$this->config = NxConfig::getConfig($this->ctxt,'recruitment',$instance='default');
	}
	
	
	function postJobBoard($record)
	{
		$providerName = $record->provider_oid->string;
		echo ' llllllllllllllllllllllllll '.$providerName;
		
		// get section for our provider
		$mainConf = $this->getConfig();
		if (!($providersConf = $conf->getSection('providers'))
			return false;

		if(!($conf = $providersConf->getSection($providerName)))
			return false;

		// check if account is active
		if (!$conf->getProperty('active',true))
			return false;

		$salt = md5(time());
		$path = $conf->getProperty('jobs_board.files.tmp_path',GENERIS_PACKAGES.'recruitment/tmp/');

		// generate XML file
		$xmlType = $conf->getProperty('job_board.xml_format','rekrute');
		$fxml = 'getXML_'.$xmlType;
		$fpath = $this->fxml($conf,$path, $record);
        $str= explode("/",$fpath);
		$fname=$str[count($str)-1];
		switch($conf->getProperty('job_board.method','ftp'))
		{
			case 'ftp':
				$this->upload_ftp($conf,$fpath,$fname);
				break;
		}
	}

	function getXML_reckrute($conf,$path, $record) {
		$title=$record->title->html;
		$content=$record->article_content->html;

		$docXML=new DomDocument('1.0','utf8');     

		$annonce=$docXML->createElement("Annonce");     

		$titre=$docXML->createElement("Titre"); 

		$titre->nodeValue="".$title;

		$contenu=$docXML->createElement("Contenu"); 

		$contenu->nodeValue="".$content;

		$docXML->appendChild($annonce);                  

		$annonce->appendChild($titre);

		$annonce->appendChild($contenu);

		$fpath = $path."annonce_{$title}_{$salt}.xml";

		$docXML->save($fpath);

		return $fpath;
	}

	function upload_ftp($conf,$fpath,$fname) {
		if (
			!($host =  $conf->getProperty('job_board.ftp.host')) ||
			!($user =  $conf->getProperty('job_board.ftp.user')) ||
			!($password =  $conf->getProperty('job_board.ftp.password'))
			)
			{
				nxError('param missing in recruitment job posting','RECRUITMENT');
				return false;
			}
			
			$port =  $conf->getProperty('job_board.ftp.port','21');
			$dir =  $conf->getProperty('job_board.ftp.dir','/');
			
			$conn_id = ftp_connect($host);

			ftp_login($conn_id, $user, $password);

			ftp_nb_put($conn_id, $fpate ,$dir."".$fname,FTP_BINARY);

		}
	}

}