<?php	
	$con = mysqli_connect("localhost","root","");
	$sel = mysqli_select_db($con,'Library');	
	$qry = "select * from issueBook";
	$result = mysqli_query($con,$qry);
?>

<!doctype html>
<html>
	<head>
		<title>Issue Data</title>
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
        <div class="header">Issue Data</div>
        <table border="1px" cellpadding="7px" align="center" style="margin-top:60px;">
			<th>Book_ID</th>
			<th>Book Name</th>
			<th>Student_ID</th>
			<th>Student_Name</th>
            <th>Email</th>
    	<?php 
			while($rows = mysqli_fetch_assoc($result))
			{
		?>
				<tr>
					<td><?php echo $rows['bid']?></td>
					<td><?php echo $rows['bname']?></td>
					<td><?php echo $rows['sid']?></td>
					<td><?php echo $rows['sname']?></td>
					<td><?php echo $rows['email']?></td>
             	</tr>
		<?php
			}
		?>
		</table>
		</body>
</html>