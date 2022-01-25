PMDH.registerNS('Generis.Recruitment');
Generis.Recruitment = {
	// Vars
	availableVacanciesControl : document.getElementById('available_vacancies-control'),
	
	// Functions
	init : function() {
		alert('dedans');
		var form = PMDH.getParentElementByTagName(document.getElementById('available_vacancies-control'),'form');
		var select = form.elements['available_vacancies'];
		select.onchange = function() {
			alert('test');
		}
	}
}