<?php	
	$con = mysqli_connect("localhost","root","");
	$sel = mysqli_select_db($con,'Library');	
	$qry = "select * from student_detail";
	$result = mysqli_query($con,$qry);
?>

<!doctype html>
<html>
	<head>
		<title>Student Data</title>
		<style>
            .header
            {
                background-color:grey;
				margin:-20px;
				padding-top:30px;
                height:70px;
				color:white;
                text-align:center;
                font-size:30px;
                opacity:0.8;
            }
        </style>
    </head>
    <body>
        <div class="header">Student Data</div>
        <table border="1px" cellpadding="7px" align="center" style="margin-top:60px;">
			<th>ID</th>
			<th>Name</th>
			<th>Email</th>
			<th>Branch</th>
            <th>DeleteBook</th>
    	<?php 
			while($rows = mysqli_fetch_assoc($result))
			{
		?>
				<tr>
					<td><?php echo $rows['sid']?></td>
					<td><?php echo $rows['sname']?></td>
					<td><?php echo $rows['email']?></td>
                    <td><?php echo $rows['branch']?></td>
					<td><a href="deleteStudent.php?id=<?php echo("$rows[sid]"); ?>"><center>DELETE</center></a></td>
				</tr>
		<?php
			}
		?>
		</table>
		</body>
</html>