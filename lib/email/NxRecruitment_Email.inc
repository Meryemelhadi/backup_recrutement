<?php 

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');

class NxRecruitment_Email
{
	var $ctxt;
	var $user = null;

	function NxRecruitment_Email($ctxt) {
		Framework::setContext($this->ctxt = $ctxt);
	}

	function getCurrentUser() {
		if($this->user)
			return $this->user;

		$user = Framework::getUser();
		if(!$user)
			return null;

		$oid = $user->getProperty('oid');

		$user2 = new PersistentObject('user.get_infos@recruitment','db',array('oid'=>$oid));
		if(!$user2->isOk())
			return null;

		return $this->user = $user2;
	}
	
	function getEmailBody($view) {
		ob_start();
		$this->ctxt->runView($view,array('fmethod' => 'toHTML',),null);
		$_nx_ret0=ob_get_contents();
		ob_end_clean();
		return $_nx_ret0;
	}
	
	function accentsToEntities($string) {
		$accentsUTF8 = array('é','è','à','ë','ê','û','ü','ù','î','ï', 'ô', 'ö');
		$res = 
			str_replace(
				$accentsUTF8,
				array('&eacute;', '&egrave;', '&agrave;', '&euml;', '&ecirc;', '&ucirc;', '&uuml', '&ugrave;', '&icirc;', '&iuml;', '&ocirc;', '&ouml;'),
			$string);

		$accentsISO = str_split(utf8_decode('éèàëêûüùîïôö'));
		$res = 
			str_replace(
				$accentsISO,
				array('&eacute;', '&egrave;', '&agrave;', '&euml;', '&ecirc;', '&ucirc;', '&uuml', '&ugrave;', '&icirc;', '&iuml;', '&ocirc;', '&ouml;'),
			$res);

		return $res;
	} 
	
	function send($message, $filesPath = '', $dsID='register_email',$cvnames=null,$libFiles=null)
	{
		$mime = $this->createMessage($message,$dsID);

		// body
		$html = $this->mapMacros($message->body->string,$message, $macros=array(),$cvnames);	
		$this->attachHTML($mime,$html);

		//subject
		$message->subject=$this->mapMacros($message->subject->string,$message, $macros=array(),$cvnames);
		
		// other files
		$this->attachFiles($mime, $message, $filesPath,$cvnames);

		if($libFiles)
		{
			$fs = Framework::fs();

			// attach files from doc library
			foreach($libFiles as $fileName => $path)
			{
				$fileContent = $fs->file_get_contents($path);
				if($fileContent)
					$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fileName\"");
			}
		}

		return $this->send_mail($mime);
	}

	function sendWithCV($message, $filesPath = '',$cvnames=null,$proposed_to=null, $dsID='register_email')
	{
		$mime = $this->createMessage($message,$dsID);

		// body
		$html = $this->mapMacros($message->body->string,$message, $macros=array(),$cvnames,$proposed_to);	
		$this->attachHTML($mime,$html);

		//subject
		$message->subject=$this->mapMacros($message->subject->string,$message, $macros=array(),$cvnames);

		// CV
		$candidateOid = $message->candidate_oid->object = $_POST['candidate_oid'];
		if($candidateOid && $candidateOid!='?')
		{
			$this->attachCV($candidateOid,$message->candidate->object,$mime, $message);
		}
		
		// other files
		$this->attachFiles($mime, $message,$filesPath,$cvnames);

		return $this->send_mail($mime);
	}

	function sendWithManyCV($message, $filesPath = '', $dsID='register_email',$cvnames=null,$cvFiles=null,$candidateOids=null,$proposed_to=null,$libFiles=null)
	{
		// create message
		$mime = $this->createMessage($message,$dsID);

		// map macros in body
		$html = $this->mapMacros($message->body->string,$message, $macros=array(),$cvnames,$proposed_to);	
		$this->attachHTML($mime,$html);

		//subject
		$message->subject=$this->mapMacros($message->subject->string,$message, $macros=array(),$cvnames,$proposed_to);

		// attach CVs
		for($i=0;$i<count($candidateOids);$i++)
		{
			$candidateOid = $candidateOids[$i];
			$cvname = $cvnames[$i];
			if($candidateOid && $candidateOid!='?')
			{
				$this->attachCV($candidateOid,$cvname,$mime, $message);
			}
		}

		if($libFiles)
		{
			$fs = Framework::fs();

			// attach files from doc library
			foreach($libFiles as $fileName => $path)
			{
				$fileContent = $fs->file_get_contents($path);
				if($fileContent)
					$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fileName\"");
			}
		}

		// $this->attachFiles($mime, $message,$cvnames);
		return $this->send_mail($mime);
	}

    function sendInvite($message, $meetingRequest, $filesPath = '', $dsID='register_email',$cvnames=null, $proposed_to = null,$libFiles=null , $video_link = null)
    {
		if(isset($meetingRequest['organiser']['email']))
			$from = $meetingRequest['organiser']['email'];
		else
			$from = null;

		// map macros in body
		$body = '';
        $html = $this->mapMacros($message->body->string,$message, $meetingRequest,$cvnames,$proposed_to,$video_link);    

		// create message
        $mime = $this->createMessage($message,$dsID,$body,$from);
        $this->attachHTML($mime,$html);
        
		//subject
		$message->subject=$this->mapMacros($message->subject->string,$message, $macros=array(),$cvnames,$proposed_to, $video_link);

		// other files
        $this->attachFiles($mime, $message,$filesPath,$cvnames);

		if($libFiles)
		{
			$fs = Framework::fs();

			// attach files from doc library
			foreach($libFiles as $fileName => $path)
			{
				$fileName = basename($path);
				$fileContent = $fs->file_get_contents($path);
				if($fileContent)
					$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fileName\"");
			}
		}

        return $this->send_mail($mime);
    }
	
	function sendMeetingRequest($uid,$message, $meetingRequest, $filesPath = '', $proposed_to = null, $dsID='register_email',$cvnames=null,$libFiles=null)
	{
		if(isset($meetingRequest['organiser']['email']))
			$from = $meetingRequest['organiser']['email'];
		else
			$from = null;

		// subject
		$subject=$this->mapMacros($meetingRequest['summary'],$message, $meetingRequest,$cvnames,$proposed_to);
		$message->subject = $subject;
		$meetingRequest['summary']=$subject;

		// body
		$html = $this->mapMacros($message->body->string,$message, $meetingRequest,$cvnames,$proposed_to);	
		// $body = $this->html2Text($html);
		$body = '';

		$mime = $this->createMessage($message,$dsID,$body,$from);
		$this->attachHTML($mime,$html);

		// ICS meeting request
		$this->attachMeetingRequest($uid,$mime, $message, $meetingRequest);

		// attach CVs
		if(isset($meetingRequest['candidateOid']))
		{
			$candidateOid = $meetingRequest['candidateOid'];
			$this->attachCV($candidateOid,$meetingRequest['candidateName'],$mime, $message);
		}

		// other files
		$this->attachFiles($mime, $message,$filesPath,$cvnames);

		if($libFiles)
		{
			$fs = Framework::fs();

			// attach files from doc library
			foreach($libFiles as $fileName => $path)
			{
				$fileName = basename($path);
				$fileContent = $fs->file_get_contents($path);
				if($fileContent)
					$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fileName\"");
			}
		}

		return $this->send_mail($mime);
	}

	function sendMeetingCancel($uid,$message, $meetingRequest, $proposed_to = null, $dsID='register_email',$cvnames=null)
	{
		if(isset($meetingRequest['organiser']['email']))
			$from = $meetingRequest['organiser']['email'];
		else
			$from = null;

		// subject
		$subject=$this->mapMacros($meetingRequest['summary'],$message, $meetingRequest,$cvnames,$proposed_to);
		$message->subject = $subject;
		$meetingRequest['summary']=$subject;

		// body
		$body = '';

		$mime = $this->createMessage($message,$dsID,$body,$from);

		// ICS meeting request
		$this->attachMeetingCancel($uid,$mime, $message, $meetingRequest);

		return $this->send_mail($mime);
	}

	function sendMeetingUpdate($uid,$message, $meetingRequest, $proposed_to = null, $dsID='register_email',$cvnames=null)
	{
		if(isset($meetingRequest['organiser']['email']))
			$from = $meetingRequest['organiser']['email'];
		else
			$from = null;

		// subject
		$subject=$this->mapMacros($meetingRequest['summary'],$message, $meetingRequest,$cvnames,$proposed_to);
		$message->subject = $subject;
		$meetingRequest['summary']=$subject;

		// body
		$body = '';

		$mime = $this->createMessage($message,$dsID,$body,$from);

		// ICS meeting request
		$this->attachMeetingUpdate($uid,$mime, $message, $meetingRequest);

		return $this->send_mail($mime);
	}

	function mapMacros($text,$message, $meetingRequest,$cvnames,$proposed_to=null , $video_link=null) 
	{
		$map = $meetingRequest;
		if(isset($meetingRequest['name']))
		{
			$map['nom'] = $meetingRequest['name'];
			$map[utf8_decode('nom:prénom')] = $map['nom:prénom'] = $map['nom:pr&eacute;nom'] = $meetingRequest['name'];
			$map['heure'] = date('H:i',$meetingRequest['startDateTime']);
			$map['date']  = $meetingRequest['date_str'];
			$map['candidats']  = $map['candidat']  = $meetingRequest['candidateName'];
		}
		else
		{		
			$map['candidats']  = $map['candidat']  = $map[utf8_decode('nom:prénom')] = $map['nom:prénom'] = $map['nom:pr&eacute;nom'] = $map['nom'] = $message->candidate_full_name->object;

			$map['heure'] = '';
			$map['date']  = '';
		}
		
		if($proposed_to)
			$map['recruteur']  = $proposed_to->first_name->string.' '.$proposed_to->last_name->string;
		
		if((isset($meetingRequest['video_link']) && $meetingRequest['video_link'] != null) || $video_link){
			$text = preg_replace_callback('#\{debut_video_lien}((?:[^[]|\)|(?R))+)\{fin_video_lien}#', function ($matches) {
            return $matches[1];}, $text);
		
			if(isset($meetingRequest['video_link']) && $meetingRequest['video_link'] != null)
				$map['video_lien']  = '<a href="'.$meetingRequest['video_link'].'">'.__("Lien téléconférence").'</a>';
			else if($video_link) $map['video_lien'] = '<a href="'.$video_link.'">'.__("Lien téléconférence").'</a>';
		}else{
			$text = preg_replace_callback('#\{debut_video_lien}((?:[^[]|\)|(?R))+)\{fin_video_lien}#', function ($matches) {
            return '';}, $text);
		}
		

		$text2= preg_replace(
			array
            (
				'@[#{]<strong>(recruteur|candidat|date|nom|nom[:]pr(?:é|&eacute;|e)nom|heure|lieu|video_lien|evaluation_url|entretien_url)?</strong>[}#]@ie',
				'@[#{]&lt;strong&gt;(recruteur|candidat|date|nom|nom[:]pr(?:é|&eacute;|e)nom|heure|lieu|video_lien|evaluation_url|entretien_url)?&lt;/strong&gt;[}#]@ie',
                '/[#{](recruteur|candidat|date|nom|nom[:]pr(?:é|&eacute;|e)nom|heure|lieu|video_lien|evaluation_url|entretien_url)[}#]/ie',

                '@[#{]<strong>(?:signature|mon|my):(nom|(?:first|last)_?name|pr(?:é|&eacute;|e)nom|email|t.l.phone|mobile|gsm|fax|photo|video_lien|evaluation_url|entretien_url|groupe?|r.le|f.nction)?</strong>[}#]@ie',
				'@[#{]&lt;strong&gt;(?:signature|mon|my):(nom|(?:first|last)_?name|pr(?:é|&eacute;|e)nom|email|t.l.phone|mobile|gsm|fax|photo|video_lien|evaluation_url|entretien_url|groupe?|r.le|f.nction)?&lt;/strong&gt;[}#]@ie',
                '/[#{](?:signature|mon|my)(?:\s*:\s*|\s+)(nom|(?:first|last)_?name|pr(?:é|&eacute;|e)nom|email|t(?:é|&eacute;|e)l(?:é|&eacute;|e)phone|mobile|gsm|fax|photo|video_lien|evaluation_url|entretien_url|groupe?|r.le|f.nction)?[}#]/ie',
			),
			array
            (
                '"<strong>".$this->getMacro($map,"$1","$2")."</strong>"',
                '"<strong>".$this->getMacro($map,"$1","$2")."</strong>"',
                '$this->getMacro($map,"$1","$2")',

                '"<strong>".$this->getUserMacro("$1")."</strong>"',
                '"<strong>".$this->getUserMacro("$1")."</strong>"',
                '$this->getUserMacro("$1")',

            ),              
                    $text);
                  
		return $text2;
	}


	function getMacro($meta,$name,$default)
	{
		if (isset($meta[$name]))
			$v=$meta[$name];
		elseif ($default)
			$v=$default;
		else
		{
			return $name;
		}
        return $v;
	}

	var $signatureMap = array(
			'nom' => 'last_name',
			'name' => 'last_name',
			'last name' => 'last_name',
			'last_name' => 'last_name',

			'prénom' => 'first_name',
			'pr&eacute;nom' => 'first_name',
			'prenom' => 'first_name',
			'first name' => 'first_name',
			'first_name' => 'first_name',

			'email' => 'email',
			'phone' => array('direct_phone','local_phone'),
			'telephone' => array('direct_phone','local_phone'),
			
			'portable' => 'mobile_phone',
			'mobile' => 'mobile_phone',
			'gsm' => 'mobile_phone',
			'fax' => 'fax',

			'photo' => 'photo',

			'groupe' => 'group',
			'group' => 'group',

			'role' => 'role',
			'rôle' => 'role',
			'fonction' => 'role',
			'function' => 'role',
			'video_link' => 'video_link' ,
			'evaluation_url' => 'evaluation_url' , 			
			'entretien_url' => 'entretien_url'
			
			);


	function getUserMacro($name)
	{
		$user = $this->getCurrentUser();
		if(!$user)
			return '';

		$name = strtolower($name);
		if(isset($this->signatureMap[$name]))
			$key = $this->signatureMap[$name];
		else
			return '';

		if(is_array($key))
		{
			foreach($key as $k)
			{
				$v = $user->$k->string;
				if($v)
					return $user->$k->string;
			}
			return '';
		}
		else
			return $user->$key->string;
	}

	function createMessage($message,$dsID,$body='',$from=null)
	{	
		if(!$from)
			$from = $this->ctxt->getProperty('email.from');

		return $this->getMimeMessage($from,$message->to->string,$message->subject->string,$body,$dsID);
	}

	function getMimeMessage($from,$to,$subject,$body,$dsID)
	{
		if( defined('EMAIL_CATCH_TO') ) {
			$message->to->db = EMAIL_CATCH_TO;
		}
		
		$ctxt = $this->ctxt;
		
		$ctxt->loadResource('ds/'.$dsID.NX_HOST_SWITCH,$ctxt->error,true);

		if (!$to)
			$to = $ctxt->getProperty($dsID.'.to');

		if (!$from)
			$from = $ctxt->getProperty($dsID.'.from');

		// send email
		$mime = new NxMail_MIME(
			$from, 
			$to, 
			$ctxt->getProperty($dsID.'.cc'), 
			$ctxt->getProperty($dsID.'.bcc'),
			$subject,
			$body, 
			$ctxt->getProperty($dsID.'.smtp.headers'),
			$ctxt->getProperty($dsID.'.smtp.servers'),
			$ctxt->getProperty($dsID.'.log')
		);

		return $mime;
	}


	function send_mail($mime)
	{		
		if (!$mime->send_mail()) {
			nxLog('Failed: LOG:<pre>'.$mime->getLog('html').'</pre>','EMAIL');
			return false;
		}
		return $mime->getLog('html');		
	}

	function attachHTML($mime,$html)
	{
		$mime->attach($this->accentsToEntities($html), 'HTML message', HTML, BASE64);
	}

	function strToICS($str) {
		return str_replace(array(',','&#039;'),array('\,','\''),$str);
	}

	function attachMeetingRequest($uid,$mime, $message, $request)
	{

$TZ = "TZID:Europe/Paris\r\n
TZOFFSETFROM:+1\r\n";

		$event = "BEGIN:VCALENDAR\r\n".
"PRODID:-//PresenceSoft//Sourcing\r\n".
"VERSION:2.0\r\n".
"CALSCALE:GREGORIAN\r\n".
"METHOD:REQUEST\r\n".
"BEGIN:VTIMEZONE\r\n".
"TZID:Romance Standard Time\r\n".
"BEGIN:STANDARD\r\n".
"DTSTART:16010101T030000\r\n".
"TZOFFSETFROM:+0200\r\n".
"TZOFFSETTO:+0100\r\n".
"RRULE:FREQ=YEARLY;INTERVAL=1;BYDAY=-1SU;BYMONTH=10\r\n".
"END:STANDARD\r\n".
"BEGIN:DAYLIGHT\r\n".
"DTSTART:16010101T020000\r\n".
"TZOFFSETFROM:+0100\r\n".
"TZOFFSETTO:+0200\r\n".
"RRULE:FREQ=YEARLY;INTERVAL=1;BYDAY=-1SU;BYMONTH=3\r\n".
"END:DAYLIGHT\r\n".
"END:VTIMEZONE\r\n".
"BEGIN:VEVENT\r\n";

		if(isset($request['organiser']))
		{
			$name = trim($request['organiser']['name']);
			if(!$name)
				$name = 'Resp. Recrutement';

			$event .= "ORGANIZER;CN=\"{$name}\":mailto:{$request['organiser']['email']}\r\n";
		}

		$i=0;
		if($request['attendees']) foreach($request['attendees'] as $attendee)
		{
			$event .= "ATTENDEE;ROLE=REQ-PARTICIPANT;PARTSTAT=NEEDS-ACTION;RSVP=TRUE;CN={$attendee['name']}:mailto:{$attendee['email']}\r\n";
		}

		$description = $this->strToICS($request['description']);
		$event .= "DESCRIPTION:{$description}\r\n";

		$summary = $this->strToICS($request['summary']);
		$event .= "SUMMARY:{$summary}\r\n";
//		$event .= "SUMMARY:RDV entretien\r\n";

		$dateStr=$request['date'];

		$startDateTime=$request['startDateTime'];
		$dtstart=$dateStr.'T'.date('His',$startDateTime);
		$event .= "DTSTART;TZID=Romance Standard Time:{$dtstart}\r\n";

		$endDateTime=$request['endDateTime'];
		$dtend=$dateStr.'T'.date('His',$endDateTime);
		$event .= "DTEND;TZID=Romance Standard Time:{$dtend}\r\n";

		//$uid = date('Ymd').'T'.date('His')."-".rand()."-presencesoft.com";
		$nameID=str_replace(array(' ','.'),array('',''),$name);
		//$uid = $dtstart.'-'.$nameID."@presencesoft.com";	
		$uidX = $uid.'-'.$nameID.'@'.$_SERVER['SERVER_NAME'];	
		$event .= "UID:{$uidX}\r\n";

		$now=date('Ymd').'T'.date('His').'Z';

		$location = isset($request['location'])?$request['location']:'';

		$event .= 
"CLASS:PUBLIC\r\n".
"PRIORITY:5\r\n".
"DTSTAMP:{$now}\r\n".
"TRANSP:OPAQUE\r\n".
"STATUS:CONFIRMED\r\n".
"SEQUENCE:0\r\n".
"LOCATION:{$location}\r\n".
"BEGIN:VALARM\r\n".
"ACTION:DISPLAY\r\n".
"DESCRIPTION:{$summary}\r\n".
"TRIGGER;RELATED=START:-PT15M\r\n".
"END:VALARM\r\n".
"END:VEVENT\r\n".
"END:VCALENDAR\r\n";

		$mime->attach($event, '', 'text/calendar; name=calendar.ics; charset="utf-8"; method=REQUEST', BASE64);
	}


	function attachMeetingCancel($uid,$mime, $message, $request)
	{

$TZ = "TZID:Europe/Paris\r\n
TZOFFSETFROM:+1\r\n";

		$event = "BEGIN:VCALENDAR\r\n".
"PRODID:-//PresenceSoft//Sourcing\r\n".
"VERSION:2.0\r\n".
"CALSCALE:GREGORIAN\r\n".
"METHOD:CANCEL\r\n".
"BEGIN:VTIMEZONE\r\n".
"TZID:Romance Standard Time\r\n".
"BEGIN:STANDARD\r\n".
"DTSTART:16010101T030000\r\n".
"TZOFFSETFROM:+0200\r\n".
"TZOFFSETTO:+0100\r\n".
"RRULE:FREQ=YEARLY;INTERVAL=1;BYDAY=-1SU;BYMONTH=10\r\n".
"END:STANDARD\r\n".
"BEGIN:DAYLIGHT\r\n".
"DTSTART:16010101T020000\r\n".
"TZOFFSETFROM:+0100\r\n".
"TZOFFSETTO:+0200\r\n".
"RRULE:FREQ=YEARLY;INTERVAL=1;BYDAY=-1SU;BYMONTH=3\r\n".
"END:DAYLIGHT\r\n".
"END:VTIMEZONE\r\n".
"BEGIN:VEVENT\r\n";

		if(isset($request['organiser']))
		{
			$name = trim($request['organiser']['name']);
			if(!$name)
				$name = 'Resp. Recrutement';

			$event .= "ORGANIZER;CN=\"{$name}\":mailto:{$request['organiser']['email']}\r\n";
		}

		$i=0;
		if($request['attendees']) foreach($request['attendees'] as $attendee)
		{
			$event .= "ATTENDEE;ROLE=REQ-PARTICIPANT;PARTSTAT=NEEDS-ACTION;RSVP=TRUE;CN={$attendee['name']}:mailto:{$attendee['email']}\r\n";
		}

		$description = $this->strToICS($request['description']);
		$event .= "DESCRIPTION:{$description}\r\n";

		$summary = $this->strToICS($request['summary']);
		$event .= "SUMMARY:{$summary}\r\n";
//		$event .= "SUMMARY:RDV entretien\r\n";

		$dateStr=$request['date'];
		$startDateTime=$request['startDateTime'];
		$dtstart=$dateStr.'T'.date('His',$startDateTime);
		$event .= "DTSTART;TZID=Romance Standard Time:{$dtstart}\r\n";

		$endDateTime=$request['endDateTime'];
		$dtend=$dateStr.'T'.date('His',$endDateTime);
		$event .= "DTEND;TZID=Romance Standard Time:{$dtend}\r\n";

		//$uid = date('Ymd').'T'.date('His')."-".rand()."-presencesoft.com";
		$nameID=str_replace(array(' ','.'),array('',''),$name);
		$uidX = $uid.'-'.$nameID.'@'.$_SERVER['SERVER_NAME'];	
		$event .= "UID:{$uidX}\r\n";

		$now=date('Ymd').'T'.date('His').'Z';

		$location = isset($request['location'])?$request['location']:'';

		$event .= 
"CLASS:PUBLIC\r\n".
"DTSTAMP:{$now}\r\n".
"TRANSP:OPAQUE\r\n".
"SEQUENCE:1\r\n".
"STATUS:CANCELLED\r\n".
"LOCATION:{$location}\r\n".
"END:VEVENT\r\n".
"END:VCALENDAR\r\n";

		$mime->attach($event, '', 'text/calendar; name=calendar.ics; charset="utf-8"; method=REQUEST', BASE64);
	}

	function attachMeetingUpdate($uid,$mime, $message, $request)
	{

$TZ = "TZID:Europe/Paris\r\n
TZOFFSETFROM:+1\r\n";

		$event = "BEGIN:VCALENDAR\r\n".
"PRODID:-//PresenceSoft//Sourcing\r\n".
"VERSION:2.0\r\n".
"CALSCALE:GREGORIAN\r\n".
"METHOD:REQUEST\r\n".
"BEGIN:VTIMEZONE\r\n".
	"TZID:Romance Standard Time\r\n".
	"BEGIN:STANDARD\r\n".
		"DTSTART:16010101T030000\r\n".
		"TZOFFSETFROM:+0200\r\n".
		"TZOFFSETTO:+0100\r\n".
		"RRULE:FREQ=YEARLY;INTERVAL=1;BYDAY=-1SU;BYMONTH=10\r\n".
	"END:STANDARD\r\n".
	"BEGIN:DAYLIGHT\r\n".
		"DTSTART:16010101T020000\r\n".
		"TZOFFSETFROM:+0100\r\n".
		"TZOFFSETTO:+0200\r\n".
		"RRULE:FREQ=YEARLY;INTERVAL=1;BYDAY=-1SU;BYMONTH=3\r\n".
	"END:DAYLIGHT\r\n".
"END:VTIMEZONE\r\n".
"BEGIN:VEVENT\r\n";

		if(isset($request['organiser']))
		{
			$name = trim($request['organiser']['name']);
			if(!$name)
				$name = 'Resp. Recrutement';

			$event .= "ORGANIZER;CN=\"{$name}\":mailto:{$request['organiser']['email']}\r\n";
		}

		$i=0;
		if($request['attendees']) foreach($request['attendees'] as $attendee)
		{
			$event .= "ATTENDEE;ROLE=REQ-PARTICIPANT;PARTSTAT=NEEDS-ACTION;RSVP=TRUE;CN={$attendee['name']}:mailto:{$attendee['email']}\r\n";
		}

		$description = $this->strToICS($request['description']);
		$event .= "DESCRIPTION:{$description}\r\n";

		$summary = $this->strToICS($request['summary']);
		$event .= "SUMMARY:{$summary}\r\n";
//		$event .= "SUMMARY:RDV entretien\r\n";

		$dateStr=$request['date'];
		$startDateTime=$request['startDateTime'];
		$dtstart=$dateStr.'T'.date('His',$startDateTime);
		$event .= "DTSTART;TZID=Romance Standard Time:{$dtstart}\r\n";

		$endDateTime=$request['endDateTime'];
		$dtend=$dateStr.'T'.date('His',$endDateTime);
		$event .= "DTEND;TZID=Romance Standard Time:{$dtend}\r\n";

		//$uid = date('Ymd').'T'.date('His')."-".rand()."-presencesoft.com";
		$nameID=str_replace(array(' ','.'),array('',''),$name);
		// $uid = $dtstart.'-'.$nameID."@presencesoft.com";	
		$uidX = $uid.'-'.$nameID.'@'.$_SERVER['SERVER_NAME'];	
		$event .= "UID:{$uidX}\r\n";

		$now=date('Ymd').'T'.date('His').'Z';

		$location = isset($request['location'])?$request['location']:'';
		$seq = $message->ical_seq->object;

		$event .= 
"CLASS:PUBLIC\r\n".
"PRIORITY:5\r\n".
"DTSTAMP:{$now}\r\n".
"TRANSP:OPAQUE\r\n".
"STATUS:CONFIRMED\r\n".
"SEQUENCE:0\r\n".
"LOCATION:{$location}\r\n".
"BEGIN:VALARM\r\n".
"ACTION:DISPLAY\r\n".
"DESCRIPTION:{$summary}\r\n".
"TRIGGER;RELATED=START:-PT15M\r\n".
"END:VALARM\r\n".
"END:VEVENT\r\n".
"END:VCALENDAR\r\n";

		$mime->attach($event, '', 'text/calendar; name=calendar.ics; charset="utf-8"; method=REQUEST', BASE64);
	}

	function attachFiles($mime, $message,$filesPath,$cvnames)
	{
	
		if( trim($message->files->string) != '' ) 
		{
			$files = explode('|||', $message->files->string);

			for($i=0; $i<count($files); $i++) 
			{
				$fileName = $files[$i];
				$filePath = $filesPath.$fileName;
						
				$file = fopen($filePath, 'rb');
				$fileContent = fread($file, filesize($filePath));
				fclose($file);

				if (isset($cvnames))
				{
					if(is_array($cvnames))
						$fname='cv_'.$cvnames[$i].'_'.$i.'.pdf';
					else
						$fname='cv_'.$cvnames.'_'.$i.'.pdf';
				}
				else
					$fname='cv_'.$i.'.pdf';				

				$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fileName\"");
			}			
		}
	}

	function attachCV($candidateOid,$cname,$mime, $message)
	{
		// get CV path
		$basePath = $this->ctxt->getProperty('pathUpload',NX_DOC_ROOT.'files/');

        $dvs = $this->ctxt->getProperty('recruitement.cv.org',10000);
        $prefix = '';
        if($candidateOid >= $dvs){
            $prefix='/_'.intval($candidateOid/$dvs)*$dvs;
        }

		$fpath = $basePath. "packages/recruitment/candidates/directory".$prefix."/{$candidateOid}/cv/";
		$fpath .= 'cv.pdf';
		$fname="CV_{$cname}.pdf";
		if(!is_file($fpath))
			return;

		// read cv
		$file = fopen($fpath, 'rb');
		$fileContent = fread($file, filesize($fpath));
		fclose($file);

		// attach to message
		$mime->attach($fileContent, 'file', OCTET, BASE64, "attachment; filename=\"$fname\"");
	}

	function html2Text($src) {
		include_once (NX_LIB.'tools/class.html2text.inc');
		$src = html_entity_decode($src);
		if ($this->is_utf8($src)) {
			$src = utf8_decode($src);
		}
		$html2text = new html2text($src);
		$src = $html2text->get_text();
		$src = html_entity_decode($src);
		return $src;
	}
	
	function is_utf8($string) {
		// From http://w3.org/International/questions/qa-forms-utf-8.html
		return preg_match('%(?:
        [\xC2-\xDF][\x80-\xBF]        # non-overlong 2-byte
        |\xE0[\xA0-\xBF][\x80-\xBF]               # excluding overlongs
        |[\xE1-\xEC\xEE\xEF][\x80-\xBF]{2}      # straight 3-byte
        |\xED[\x80-\x9F][\x80-\xBF]               # excluding surrogates
        |\xF0[\x90-\xBF][\x80-\xBF]{2}    # planes 1-3
        |[\xF1-\xF3][\x80-\xBF]{3}                  # planes 4-15
        |\xF4[\x80-\x8F][\x80-\xBF]{2}    # plane 16
        )+%xs', $string);
	} 
}

?>