<?php
	session_start();
	$aid = $_POST['aid'];
	$name = $_POST['name'];
	$email = $_POST['email'];
	$pass = $_POST['password'];
    $cont = $_POST['contact'];
    
	$con = mysqli_connect("localhost","root","");

	$sel = mysqli_select_db($con,'Library');
	$id = $_SESSION['active'];	
    $qry = "update admin_detail set email='$email',aname='$name',password='$pass',contact='$cont' where email = '$id'";
    $_SESSION['active'] = $email;
	$x = mysqli_query($con,$qry);
	mysqli_close($con);
	header('location:dashboard.php')
?>
		