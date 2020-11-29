<?php
	session_start();
	$aid = $_POST['sid'];
	$name = $_POST['name'];
	$email = $_POST['email'];
	$pass = $_POST['password'];
    $branch = $_POST['branch'];
    
	$con = mysqli_connect("localhost","root","");

	$sel = mysqli_select_db($con,'Library');
	$id = $_SESSION['active'];	
    $qry = "update student_detail set email='$email',sname='$name',password='$pass',branch='$branch' where email = '$id'";
    $_SESSION['active'] = $email;
	$x = mysqli_query($con,$qry);
	mysqli_close($con);
	header('location:dashboard.php')
?>
		