{records:interviews.records}
<table style="width:100%">
	{record}
		<tr><td>Entretien <b>{field:interview_type}
			</b> avec&nbsp;&nbsp;  <b>{field:_candidate_oid}
			</b> &nbsp;&nbsp;
		</td><td>Effectué par <b>{field:_interviewer_oid}
			</b> &nbsp;&nbsp;
		</td><td>De: <b>{field:_time_start}
			</b> A <b>{field:_time_end}
			</b>
		</td>
	</tr>
	{/record}

</table>
{/records}
<script type="text/javascript">
window.date_interview = '{string:"other_interviews"}';

</script>