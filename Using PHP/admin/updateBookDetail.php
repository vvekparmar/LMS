<?php
	$bid = $_POST['bid'];
	$name = $_POST['name'];
	$author = $_POST['author'];
	$publication = $_POST['publication'];
    $quantity = $_POST['quantity'];
    $price = $_POST['price'];
	
	$con = mysqli_connect("localhost","root","");

	$sel = mysqli_select_db($con,'Library');
		
	$qry = "update book_detail set bname='$name', author='$author', publication='$publication', quantity='$quantity', price='$price' where bid='$bid'";
	$x = mysqli_query($con,$qry);
    mysqli_close($con);
    header('location:dashboard.php');
?>
		