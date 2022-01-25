<div id="add_cv" onclick="window.stopEvent(event);"
title="Ajout d'un CV :
Le CV est envoyé pour analyse et une fiche est ensuite créée automatiquement si le candidat n'existe pas dans la base. 
Sinon la fiche candidat sera mise à jour avec le nouveau CV, sans modifier les informations de recrutement.">
	<form name="add_cv_form" id="add_cv_form" enctype="multipart/form-data" action="?nxo=candidates@recruitment:upload_cv" method="post" onsubmit="return window.checkAddCVform()">
		<input type="hidden" name="MAX_FILE_SIZE" value="100000000">
		<input type="hidden" name="_form_method_" value="POST">
		<input id="cv_file" type="file" name="temp_cv_file" style="display:none;">
		<input id="cv_submit" style="font-size: 13px;background: none repeat scroll 0% 0% rgb(76, 158, 217); border: medium none rgb(76, 158, 217); border-radius: 5px; color: rgb(255, 255, 255);margin-top:-4px;padding:7px;" value="Ajouter CV..." type="submit">
			
	</form>
</div>

<script>
window.checkAddCVform = function() {
	var frm = document.forms['add_cv_form'];
	if(frm.elements['cv_file'].value == '')
	{
		if($('cv_submit').value=="Envoyer CV")
		{
			$('cv_file').hide();
			$('cv_submit').value="Ajouter CV...";
		}
		else
		{
			$('cv_file').show();
			$('cv_submit').value="Envoyer CV";
		}
		return false;
	}

	return true;
}

</script>