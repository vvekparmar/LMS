<?php
	$conn = mysqli_connect("localhost","root","");
	mysqli_select_db($conn,'Library');
	$qry = "select * from book_detail WHERE bid = $_GET[id]";
    $x = mysqli_query($conn,$qry);
    $result = mysqli_fetch_assoc($x);
?>

<!doctype html>
<html>
	<head>
		<title>updateBook</title>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
		<style>
			body
            {
                background-image:url('image.png');
            }

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

            @media only screen and (min-width:200px)
            {
                .flex_form
                {
                    display:flex;
                    flex-direction:column;
                }

                .context
                {
                    background-color:grey;
                    margin-left:38%;
                    margin-top:40px;
                    height:50%;
                    width:23%;
                    padding:30px;
                    opacity:0.8;
                }
                .context input
			    {
                    height:40px;
                    width:98%;
                    font-family:inherit;
                    font-size:18px;
                    text-align:center;
                    background-color:white;
			    }
            }
		</style>
	</head>

	<body>
	<div class="header">Update Book</div>
		<div class="context">
		<form action="updateBookDetail.php" method="post">
			<input type="number" name="bid" value="<?php echo $result['bid'] ?>" placeholder="ID" /><br><br>
			<input type="text" name="name" value="<?php echo $result['bname'] ?>" placeholder="Book Name" /><br><br>
			<input type="text" name="author" value="<?php echo $result['author'] ?>" placeholder="Author" /><br><br> 
			<input type="text" name="publication" value="<?php echo $result['publication'] ?>" placeholder="Publication" /><br><br> 
			<input type="number" name="quantity" value="<?php echo $result['quantity'] ?>" placeholder="Quantity" /><br><br> 
            <input type="number" name="price" value="<?php echo $result['price'] ?>" placeholder="Price" /><br><br>
			<input type="submit" value="Update Book" />
		</form>
		</div>
	</body>
</html>