<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

class Workflow_Task_delete_interview extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $ctxt;
		$this->params = $params;
	}

	function run()
	{
						
		$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					
			
		$this->setProperty("interview_oid",(isset($_REQUEST["interview_oid"])?$_REQUEST["interview_oid"]:""));
		$this->deleteRecords('rct_interview_synthesis.delete@recruitment',$this->getRecords('rct_interview_synthesis.delete@recruitment',null,'db'),'db',true);
					
		
		$this->deleteRecords('rct_interview.delete@recruitment',
				$this->getRecords('rct_interview.delete@recruitment',null,'db'),'db',true);
		
		$log= new lib_recruitment_candidates_services_log($this->ctxt);
		$log->addLog((isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""), $GLOBALS["_NX_user"]->getProperty("oid",""), 6 , '' , '');
		
		/*$this->putRecord(
			$_nx_record_data8=array(
								
				'candidate_oid'=>(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""),
								
				'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
				'action_oid'=>'6',
				'ref_oid'=>'',
				'additional_infos'=>''
			),
			'rct_candidate_action.record','insert','db','Object',null);*/
			
		if(isset($_REQUEST["operation"]) && $_REQUEST["operation"]=="my_calendar"){
			if(isset($_REQUEST["from_vac"]) && $_REQUEST["from_vac"]==1)
			$u=$this->getProperty('site.url.noprefix','').PORTAL_URL_PREFIX.'/recruitment/vacancies/admin/void-'.$_REQUEST['vacancy_oid'].'/directory.php?nxo=calendar_vacancy&nxs=&oid='.$_REQUEST['vacancy_oid'].'&vacancy_oid='.$_REQUEST['vacancy_oid'].'&from_vac=1&mode=page';
			echo '<script>window.location.href="'.$u.'"</script>';
		}else{
			
			/** Source d'appel : La nouvelle cvthèque => Traiter les liens et le mode d'affichage des pages dans le frame **/
			$src = "";
			$fram = "";
			if(isset($_REQUEST["src"]) && $_REQUEST["src"] ===  'newcvt'){
				$src = "&src=newcvt";
				$fram = "/fram";
			}
			/** End **/
			$this->setProperty('redirect_url.url', PORTAL_URL_PREFIX.'/recruitment/interview/directory.php');
			$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);
			//header('Location:'.($u=$this->getProperty('site.url.noprefix','').$_SERVER["PHP_SELF"].'?nxo=edit&nxs=&mode=ajax&oid='.(isset($_REQUEST["candidate_oid"])?$_REQUEST["candidate_oid"]:""))."&src=".$src);
		}
		nxLog('redirect to '.$u,'redirect');
		return true;
	}
}
?>