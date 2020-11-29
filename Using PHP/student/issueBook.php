<?php	
	$con = mysqli_connect("localhost","root","");
	$sel = mysqli_select_db($con,'Library');	
	$qry = "select * from book_detail";
	$result = mysqli_query($con,$qry);
?>

<!doctype html>
<html>
	<head>
		<title>Book Data</title>
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
        <div class="header">Book Data</div>
        <table border="1px" cellpadding="7px" align="center" style="margin-top:60px;">
			<th>ID</th>
			<th>Name</th>
			<th>Author</th>
			<th>Publication</th>
			<th>Quantity</th>
            <th>Price</th>
            <th>Issue Book</th>
    	<?php 
			while($rows = mysqli_fetch_assoc($result))
			{
		?>
				<tr>
					<td><?php echo $rows['bid']?></td>
					<td><?php echo $rows['bname']?></td>
					<td><?php echo $rows['author']?></td>
					<td><?php echo $rows['publication']?></td>
					<td><?php echo $rows['quantity']?></td>
                    <td><?php echo $rows['price']?></td>
                    <td><a href="issueSelectedBook.php?id=<?php echo("$rows[bid]"); ?>"><center>ISSUE</center></a></td>
				</tr>
		<?php
			}
		?>
		</table>
		</body>
</html>