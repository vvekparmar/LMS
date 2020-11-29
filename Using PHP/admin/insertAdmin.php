<?php
	$aid = $_POST['aid'];
	$name = $_POST['name'];
	$email = $_POST['email'];
	$pass = $_POST['password'];
    $cont = $_POST['contact'];
    
	$con = mysqli_connect("localhost","root","");

	$sel = mysqli_select_db($con,'Library');
		
	$qry = "INSERT INTO admin_detail(aid,aname,email,password,contact)
			VALUES ('$aid','$name','$email','$pass','$cont')";
	
	$x = mysqli_query($con,$qry);
	mysqli_close($con);
	header('location:admin_signin.php')
?>
		