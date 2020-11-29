<?php

    $con = mysqli_connect("localhost","root","");
    $sel = mysqli_select_db($con,'Library');
    
    $qry = "select * from issueBook where bid = '$_GET[id]'";
    $a = mysqli_query($con,$qry);
    $result = mysqli_fetch_assoc($a);

    if($result == NULL)
    {
        $qry = "select * from renueBook where bid = '$_GET[id]'";
        $a = mysqli_query($con,$qry);
        $result = mysqli_fetch_assoc($a);
    }

    $bid = $result['bid'];
    $bname = $result['bname'];
    $semail = $result['email'];
    $sid = $result['sid'];
    $sname = $result['sname'];

    $query = "insert into returnBook(bid,bname,sid,sname,email) values('$bid','$bname','$sid','$sname','$semail')";
    mysqli_query($con,$query);

    $qy = "select * from book_detail where bid = '$_GET[id]'";
    $b = mysqli_query($con,$qy);
    $result = mysqli_fetch_assoc($b);

    $z = $result['quantity']+1; 
    $q = "update book_detail set quantity = '$z' where bid = '$_GET[id]'";
    mysqli_query($con,$q);
    
    $s = "delete from renueBook where bid = '$bid'";
    mysqli_query($con,$s); 
    header('location:dashboard.php');
?>