<?php
    session_start();
    $email = $_POST['email'];
    $pass = $_POST['password'];

    $con = mysqli_connect("localhost","root","");
    $sel = mysqli_select_db($con,'Library');

    $qry = "select * from student_detail where email = '$email'";
	$arr = mysqli_fetch_assoc(mysqli_query($con,$qry));

    if($arr['email'] == $email && $arr['password'] == $pass)
    {
        $_SESSION['active'] = $email;
        header('location:dashboard.php');
    }
    else
    {
        echo "Invalid Email or Password.";
    }
?>