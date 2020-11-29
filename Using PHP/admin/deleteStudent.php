<?php
	$conn = mysqli_connect("localhost","root","");
	mysqli_select_db($conn,'Library');
	if(isset($_GET['id']))
	{
		$qry = "DELETE FROM student_detail WHERE sid = $_GET[id]";
		mysqli_query($conn,$qry);
		header('Location:displayStudent.php');
	}
	mysqli_close($conn);
?>