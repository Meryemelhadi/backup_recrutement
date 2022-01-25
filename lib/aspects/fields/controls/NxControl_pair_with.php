<?php
/*
COPYRIGHT NxFrontier Ltd
www.nxfrontier.com
This code may not be copied, modified or redistributed without the written consent of NxFrontier Limited, UK company number 04462961. 
*/
class NxControl_pair_with
{
	function toHTML(&$value,&$f)
	{
		return $value;
	}
	
	function toForm(&$value,&$f)
	{
		$desc=&$f->desc;		
		$fname = $f->getAlias();

		$inputVal = eregi_replace("[<]br[ /]*[>]", "", $value);

		$with = $desc->getProperty("with");

		if ($desc->isHidden())
		{
			return "<input type=\"hidden\" name=\"".$fname."\" value=\"".$inputVal."\" />";
		}

		if (!$desc->isEdit())
			return $this->toHTML()."<input type=\"hidden\" name=\"".$fname."\" value=\"".$inputVal."\" />";

		$colsMaxBox= intval($desc->getProperty("colsMaxBox",30));

		$multiLines = $desc->getProperty("multiLines","auto",false);
		$size=intval($desc->getProperty("size",$colsMaxBox));
		$maxLength = intval($desc->getProperty("maxLength",$size));
		$filterChars = $desc->getProperty("onInput",null);		
		if(($evh = $desc->getProperty("onclick",''))!='')
		{
			$evh=" onclick=\"$evh\" ";
		}
		
		$arValues = explode('|', $inputVal);	
		$minValue = $arValues[0];
		$maxValue = $arValues[1];		
		
		if (!isset($filterChars))
			$filterChars = "";
		else
			$filterChars = " onkeypress=\"".$filterChars."\" onpaste=\"".$filterChars."\"";
		
		$res = '<div class="nx_control_range clear-both">';
				
		$res .= '<div class="nx_control_range_min"><div class="ncr-wrapper"><div>';
		$res .= "<input class=\"text\" type=\"text\" name=\"".$fname."_min\" size=\"$size\" maxlength=\"$maxLength\" value=\"".$minValue."\"".$filterChars."$evh/>";
		$res .= '</div></div></div>';
		
		$res .= '<div class="nx_control_range_max"><div class="ncr-wrapper"><div>';
		$res .= "<input class=\"text\" type=\"text\" name=\"".$fname."_max\" size=\"$size\" maxlength=\"$maxLength\" value=\"".$maxValue."\"".$filterChars."$evh/>";
		$res .= '</div></div></div>';
		
		$res .= '</div>';

		return $res;
	}

	function readForm(&$recData,&$f)
	{
		// $fname = $desc->name;
		$fname = $f->getAlias();
		
		$minValue = $f->getFieldData($recData,$fname."_min",TC_NO_SELECTION);
		$maxValue = $f->getFieldData($recData,$fname."_max",TC_NO_SELECTION);
		
		if( ( isset($minValue) && trim($minValue) != '' ) || ( isset($maxValue) && trim($maxValue) != '' ) ) {
			return nl2br(htmlspecialchars($minValue.'|'.$maxValue,ENT_QUOTES));
		}
		
		if( isset($recData[$fname]) && $recData[$fname] != ''  ) {
			return nl2br(htmlspecialchars($recData[$fname],ENT_QUOTES));
		}
			
		return null;
	}
}

?>