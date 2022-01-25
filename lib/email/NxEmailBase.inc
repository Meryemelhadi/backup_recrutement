<?php

require_once(NX_LIB.'plugins/NxPlug_FileSys.inc');
include_once(NX_LIB.'ds/email/NxMail_MIME.inc');

class NxEmailBase {

	function __construct($ctxt) {
		$this->ctxt = $ctxt;
	}

	function getMimeMessage($from,$to,$subject,$body,$dsID)
	{
		if( defined('EMAIL_CATCH_TO') ) {
			$to = EMAIL_CATCH_TO;
		}
		if( defined('EMAIL_CATCH_FROM') ) {
			$from = EMAIL_CATCH_FROM;
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

	function getEmailBody($view,$props) {
		ob_start();
		$props['fmethod'] = 'toHTML';
		$this->ctxt->runView($view,$props,null);
		$_nx_ret0=ob_get_contents();
		ob_end_clean();
		return $_nx_ret0;
	}

	function attachHTML($mime,$html)
	{
		$mime->attach($this->accentsToEntities($html), 'HTML message', HTML, BASE64);
	}

	function accentsToEntities($string) {

		return $this->accentsToEntities2(
			str_replace(array('é','è','à','ë','ê','û','ü','ù','î','ï', 'ô', 'ö'),array('&eacute;', '&egrave;', '&agrave;', '&euml;', '&ecirc;', '&ucirc;', '&uuml', '&ugrave;', '&icirc;', '&iuml;', '&ocirc;', '&ouml;'),$string)
			);
	} 

	function accentsToEntities2($string) {
		$accents = str_split(utf8_decode('éèàëêûüùîïôö'));

		return str_replace($accents,array('&eacute;', '&egrave;', '&agrave;', '&euml;', '&ecirc;', '&ucirc;', '&uuml', '&ugrave;', '&icirc;', '&iuml;', '&ocirc;', '&ouml;'),$string);
	} 

	function attachMeetingRequest($mime, $organiser, $attendees, $summary, $description, $dateStr, $startDateTime, $endDateTime )
	{
		$event = "BEGIN:VCALENDAR\r\n
PRODID:-//PresenceSoft//Sourcing\r\n
VERSION:2.0\r\n
CALSCALE:GREGORIAN\r\n
METHOD:REQUEST\r\n
BEGIN:VEVENT\r\n";

		if($organiser)
		{
			$event .= "ORGANIZER;CN={$organiser['name']}:MAILTO:{$organiser['email']}\r\n";
		}

		if($attendees) foreach($attendees as $attendee)
		{
			$event .= "ATTENDEE;ROLE=REQ-PARTICIPANT;PARTSTAT=NEEDS-ACTION;RSVP=TRUE;CN={$attendee['name']}:mailto:{$attendee['email']}\r\n";
		}

		$description = $this->strToICS($description);
		$event .= "DESCRIPTION:{$description}\r\n";

		$summary = $this->strToICS($summary);
		$event .= "SUMMARY:{$summary}\r\n";

		$dateStr=$date;

		$dtstart=$dateStr.'T'.date('His',$startDateTime).'Z';
		$event .= "DTSTART:{$dtstart}\r\n";

		$dtend=$dateStr.'T'.date('His',$endDateTime).'Z';
		$event .= "DTEND:{$dtend}\r\n";

		$uid = date('Ymd').'T'.date('His')."-".rand()."-presencesoft.com";
		$event .= "UID:{$uid}\r\n";

		$now=date('Ymd').'T'.date('His').'Z';

		$event .= 
"CLASS:PUBLIC\r\n
PRIORITY:5\r\n
DTSTAMP:{$now}\r\n
TRANSP:OPAQUE\r\n
STATUS:CONFIRMED\r\n
SEQUENCE:0\r\n
LOCATION: NONE \r\n
BEGIN:VALARM\r\n
ACTION:DISPLAY\r\n
DESCRIPTION:REMINDER\r\n
TRIGGER;RELATED=START:-PT15M\r\n
END:VALARM\r\n
END:VEVENT\r\n
END:VCALENDAR\r\n";

		$mime->attach($event, '', 'text/calendar; name=calendar.ics; charset="utf-8"; method=REQUEST', BASE64);
	}

	function strToICS($str) {
		return str_replace('&#039;','\'',$str);
	}

	function mapMacros($text,$recruiter, $candidate /* ,$meetingRequest,$cvnames,$proposed_to=null */) 
	{
		$this->user = $recruiter;

		$map = array();
		$map['candidats']  = $map['candidat']  = $map[utf8_decode('nom:prénom')] = $map['nom:prénom'] = $map['nom:pr&eacute;nom'] = $map['nom'] = $candidate->first_name->string.' '.$candidate->last_name->string;
		$map['recruteur']  = $recruiter->first_name->string.' '.$recruiter->last_name->string;

		$text2= preg_replace(
			array
            (
				'@[#{]<strong>(recruteur|candidat|date|nom|nom[:]pr(?:é|&eacute;|e)nom|heure|lieu)?</strong>[}#]@ie',
				'@[#{]&lt;strong&gt;(recruteur|candidat|date|nom|nom[:]pr(?:é|&eacute;|e)nom|heure|lieu)?&lt;/strong&gt;[}#]@ie',
                '/[#{](recruteur|candidat|date|nom|nom[:]pr(?:é|&eacute;|e)nom|heure|lieu)[}#]/ie',

                '@[#{]<strong>(?:signature|mon|my):(nom|(?:first|last)_?name|pr(?:é|&eacute;|e)nom|email|t.l.phone|mobile|gsm|fax|photo|groupe?|r.le|f.nction)?</strong>[}#]@ie',
				'@[#{]&lt;strong&gt;(?:signature|mon|my):(nom|(?:first|last)_?name|pr(?:é|&eacute;|e)nom|email|t.l.phone|mobile|gsm|fax|photo|groupe?|r.le|f.nction)?&lt;/strong&gt;[}#]@ie',
                '/[#{](?:signature|mon|my)(?:\s*:\s*|\s+)(nom|(?:first|last)_?name|pr(?:é|&eacute;|e)nom|email|t(?:é|&eacute;|e)l(?:é|&eacute;|e)phone|mobile|gsm|fax|photo|groupe?|r.le|f.nction)?[}#]/ie',
                '#\{debut_video_lien}((?:[^[]|\)|(?R))+)\{fin_video_lien}#',
			),
			array
            (
                '"<strong>".$this->getMacro($map,"$1","$2")."</strong>"',
                '"<strong>".$this->getMacro($map,"$1","$2")."</strong>"',
                '$this->getMacro($map,"$1","$2")',

                '"<strong>".$this->getUserMacro("$1")."</strong>"',
                '"<strong>".$this->getUserMacro("$1")."</strong>"',
                '$this->getUserMacro("$1")',
                '',

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
			
			);


	function getUserMacro($name)
	{
		$user = $this->user;
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
}

?>