<?php
    session_start();

    $con = mysqli_connect("localhost","root","");
    $sel = mysqli_select_db($con,'Library');
    
    $qry = "select * from book_detail where bid = '$_GET[id]'";
    $a = mysqli_query($con,$qry);
    $result = mysqli_fetch_assoc($a);

    $bid = $result['bid'];
    $bname = $result['bname'];
    $semail = $_SESSION['active'];
    
    $qry = "select sid,sname from student_detail where email = '$semail'";
    $b = mysqli_query($con,$qry);
    $rs = mysqli_fetch_assoc($b);
    $sid = $rs['sid'];
    $sname = $rs['sname'];

    $query = "insert into issueBook(bid,bname,sid,sname,email) values('$bid','$bname','$sid','$sname','$semail')";
    mysqli_query($con,$query);

    $z = $result['quantity']-1; 
    $qy = "update book_detail set quantity = '$z' where bid = '$_GET[id]'";
    mysqli_query($con,$qy);
    header('location:dashboard.php');
?>