<?php
    $con = mysqli_connect("localhost","root","");
    $sel = mysqli_select_db($con,'Library');
    
    $qry = "select * from issueBook where bid = '$_GET[id]'";
    $a = mysqli_query($con,$qry);
    $result = mysqli_fetch_assoc($a);

    $bid = $result['bid'];
    $bname = $result['bname'];
    $semail = $result['email'];
    $sid = $result['sid'];
    $sname = $result['sname'];

    $query = "insert into renueBook(bid,bname,sid,sname,email) values('$bid','$bname','$sid','$sname','$semail')";
    mysqli_query($con,$query);

    $qy = "delete from issueBook where bid = '$bid'";
    mysqli_query($con,$qy);
    header('location:dashboard.php');
?>