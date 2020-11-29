<?php
	$sid = $_POST['sid'];
	$sname = $_POST['name'];
    $email = $_POST['email'];
    $pass = $_POST['password'];
    $branch = $_POST['branch'];
    
	$con = mysqli_connect("localhost","root","");

	$sel = mysqli_select_db($con,'Library');
		
	$qry = "INSERT INTO student_detail(sid,sname,email,password,branch)
			VALUES ('$sid','$sname','$email','$pass','$branch')";
	
	$x = mysqli_query($con,$qry);
	mysqli_close($con);
	header('location:student_signin.php')
?>
		