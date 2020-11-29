<?php

	$conn = mysqli_connect("localhost","root","");
	mysqli_select_db($conn,'Library');
	if(isset($_GET['id']))
	{
		$qry = "DELETE FROM book_detail WHERE bid = $_GET[id]";
		mysqli_query($conn,$qry);
		header('Location:displayBook.php');
	}
	mysqli_close($conn);
?>