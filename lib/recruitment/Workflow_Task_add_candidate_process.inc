<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');
require_once(GENERIS_PACKAGES.'recruitment/lib/recruitment/candidates/services/log.inc');

//require_once('candidates/services/directory.inc');
//require_once('candidates/services/denormalisation.inc');


class Workflow_Task_add_candidate_process extends NxPage
{
	function __construct($ctxt,$params,$taskID)
	{
		$this->NxPage($params,$ctxt,null);
		$this->ctxt = $this;
	}
	
	function run()
	{
		$candidateOid=(($__o=$this->getHandler('lib.recruitment.candidates.services.directory','')) ? $__o->saveNewCV() : null);
		if(isset($_POST['vacancies_oid']) && $_POST['vacancies_oid']!='?') $this->attachVacancy($_POST['vacancies_oid'] , $candidateOid );

        //Add log
        $log= new lib_recruitment_candidates_services_log($this->ctxt);
        $log->addLog($candidateOid, $GLOBALS["_NX_user"]->getProperty("oid",""), 0 , '' , '');

		(($__o=$this->getHandler('lib.recruitment.candidates.services.denormalisation','')) ? $__o->partial($candidateOid) : null);


        //$entry->store('rct_candidate_action.record@recruitment','insert');

		$editUrl = dirname($_SERVER["PHP_SELF"]).
			'/coid-'.$candidateOid.'/directory.php?nxo=edit&nxs=&oid='.$candidateOid.'&candidate_oid='.$candidateOid.'&filterKey='.urlencode((isset($_REQUEST["filterKey"])?$_REQUEST["filterKey"]:""));

        //header('Location:'.$editUrl);
        //return true;
        

		/*$this->setProperty('edit.url',$editUrl);
		$this->runView('/recruitment/candidates/directory__redirect',array(
						'fmethod' => 'toHTML',
						),null);
		return true;*/
		
		$this->setProperty('redirect_url.url',$editUrl);
			
		$this->runView('common.redirect@recruitment',array('fmethod' => 'toHTML',),null);

	}
	
	function attachVacancy($vacancy_oid,$candidate_oid) {
		

		$this->setProperty('candidate_oid',$candidate_oid);
        $this->setProperty('oid',$candidate_oid);
		$this->setProperty('vacancy_oid',$vacancy_oid);

		$candidateVacancyRecord = $this->getRecord('rct_candidate_vacancy.get_assoc@recruitment','page.record','db',false,null,null);

		// On crée l'association si elle n'existe pas
		if( !$candidateVacancyRecord) 
		{
			nxLog("candidate bound to vacancy",'CV');

			$candidateVacancyRecord = new PersistentObject('rct_candidate_vacancy.add_assoc@recruitment','empty');	
			$candidateVacancyRecord->store('rct_candidate_vacancy.add_assoc@recruitment','insert','db');
            $vacancyRecord = $this->ctxt->getRecord('rct_vacancy.record_manager@recruitment','page.record','db',false,null,null);
            $o =  new PersistentObject('rct_candidate.set_hr_manager@recruitment','db',array('oid' => $candidate_oid));
			if($o->hr_manager->object == null || $o->hr_manager->object == "" || $o->hr_manager->object == 0){
				if($vacancyRecord->manager_oid->object != null && $vacancyRecord->manager_oid->object != '' && $vacancyRecord->manager_oid->object != 0){
					$o->setFieldValue('hr_manager',$vacancyRecord->manager_oid->object);
				}else{
					$o->setFieldValue('hr_manager',$vacancyRecord->creator->object);
				}
			}
			$o->setFieldValue('establishment',$vacancyRecord->establishment->object);
			$o->store('rct_candidate.set_hr_manager@recruitment', 'update', 'db', array('oid' => $candidate_oid));
			
			//Change vacancy progress level (M.E)
			$this->setProperty("progress_level",'3');
			$this->putRecord($null=null,'rct_vacancy.change_progress_level@recruitment','update','db','Object',null);
			$cRecord=$this->getRecord('rct_vacancy.get_current_progress_level@recruitment','page.record','db',false,null,null);
			$progress_level_meta=$cRecord->getProperty('progress_level_meta','',false,'html','');
			$this->putRecord(
				$_nx_record_data7=array(
						'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
						'progress_level'=>$this->getProperty("progress_level",""),
						'progress_level_meta'=>$progress_level_meta,),'rct_vacancy_history.record@recruitment','insert','db','Object',null);

            
		}
		else 
		{
			nxLog("candidate already bound to vacancy...",'CV');
		}
		return true;
	}
}
?>