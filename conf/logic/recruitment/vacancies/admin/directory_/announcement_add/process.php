<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/

require_once(NX_LIB.'module/NxPage.inc');
require_once(NX_LIB.'NxData_RecordInputSource.inc');

class recruitment_vacancies_admin_directory__announcement_add_process extends NxPage
{
	function recruitment_vacancies_admin_directory__announcement_add_process($props,&$parentDesc,$aspect)
	{
		$this->NxPage($props,$parentDesc,$aspect);
	}

	

	function run()
	{
					$this->setProperty("vacancy_oid",(isset($_REQUEST["vacancy_oid"])?$_REQUEST["vacancy_oid"]:""));
					$article=
						$this->getRecord('journal.add@recruitment','page.records','post',false,null,null);
					$this->putRecord($article,'journal.add@recruitment','insert','db','Object',null);
					$this->setProperty("lastInsertId",
						$this->getLastInsertID('db'));
					$path='journal';
					$handler='journal_file_attachements.add@recruitment';
					($tmp=
						(($__o=$this->getHandler('lib.recruitment.vacancies.services.directory','')) ? $__o->uploadAnnouncementFiles($this->getProperty("lastInsertId",""),$handler,$path) : null))!=null?$this->addProperties($tmp):null;
					$article_title=
						$article->getProperty('title','',false,'object','');
					$article_content=
						$article->getProperty('article_content','',false,'object','');
					$this->putRecord(
						$_nx_record_data2=array(
								'ann_title'=>$article_title,
								'ann_content'=>$article_content,
								'ref_oid'=>$this->getProperty("lastInsertId",""),),'rct_announcement.add','insert','db','Object',null);
					$this->setProperty("lastInsertId",
						$this->getLastInsertID('db'));
					$this->putRecord(
						$_nx_record_data3=array(
								'vacancy_oid'=>$this->getProperty("vacancy_oid",""),
								'user_oid'=>$GLOBALS["_NX_user"]->getProperty("oid",""),
								'action_oid'=>'30',
								'ref_oid'=>$this->getProperty("lastInsertId",""),
								'additional_infos'=>'',),'rct_vacancy_action.record','insert','db','Object',null);
		return true;
	}
}
?>