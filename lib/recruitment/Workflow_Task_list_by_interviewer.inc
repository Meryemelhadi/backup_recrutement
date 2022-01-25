<?php

require_once(NX_LIB.'framework.inc');
require_once(NX_LIB.'module/NxPage.inc');

class Workflow_Task_list_by_interviewer extends Workflow_Task
{
	/*function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
	}*/

	function run($workflow, $user)
	{
		$interviewers = explode(',' , (isset($_REQUEST["interviewers"])?$_REQUEST["interviewers"]:""));
		$i="";
		foreach($interviewers as $interview) {
             $i .="'".$interview."' , " ;
        }
		$i.="'0'";
		$this->ctxt->setProperty("date_interview1" , (isset($_REQUEST["date_interview"])?$_REQUEST["date_interview"]:""));
		$date_interview = explode('/' ,(isset($_REQUEST["date_interview"])?$_REQUEST["date_interview"]:""));
		$_REQUEST["interviewers"] = $i;
		$_REQUEST["date_interview"] = $date_interview[2].'-'.$date_interview[1].'-'.$date_interview[0];
		
		if(isset($_REQUEST['interview_oid'])){
			$interviews= $this->ctxt->getRecords('rct_interview.by_interviewer_day_interview_oid','interviews.records','db',false,null,null);
		}else{
			$interviews= $this->ctxt->getRecords('rct_interview.by_interviewer_day','interviews.records','db',false,null,null);
		}
		
		if(sizeof($interviews->records) > 0){
			$this->ctxt->runView('recruitment.candidates.components.calendar.interviews',array(
			'fmethod' => 'toHTML',
			'interviews.records' => $interviews , 
			),null);
		}
		
	}
}
?>