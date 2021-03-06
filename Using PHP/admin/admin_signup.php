<!doctype html>
<html>
	<head>
		<title>Admin Signup</title>
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
                    margin-top:60px;
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
				.acc
            	{
               		margin-top:20px;
                	margin-left:43%;
            	}
                
                .acc a
                {
                    text-decoration:none;
                    font-size:20px;
                    color:white;
                }
            }
		</style>
	</head>

	<body>
	<div class="header">ADMIN SIGN UP</div>
		<div class="context">
		<form action="insertAdmin.php" method="post">
            <div id="fmID" style="color:white; font-size:20px;"></div>
            <input type="number" name="aid" onfocus="show(1)" placeholder="ID" required/><br><br>
            
            <div id="fmName" style="color:white; font-size:20px;"></div>
            <input type="text" name="name" onfocus="show(2)" placeholder="Name" required/><br><br>
            
            <div id="fmEmail" style="color:white; font-size:20px;"></div>
            <input type="email" name="email" onfocus="show(3)" placeholder="Email" required/><br><br>
            
            <div id="fmPassword" style="color:white; font-size:20px;"></div>
            <input type="password" onfocus="show(4)" name="password" placeholder="Password" required/><br><br> 
        
            <div id="fmCnt" style="color:white; font-size:20px;"></div>
            <input type="text" onfocus="show(5)" name="contact" placeholder="Contact" required/><br><br>
            
            <input type="submit" onfocus="show(6)" value="SIGN UP" />
		</form>
        </div>
        
        <script type="text/javascript">
            function show(c)
            {
                switch(c)
                {
                    case 1:
                        document.getElementById("fmID").innerHTML = "Enter ID";
                        document.getElementById("fmCnt").innerHTML = ""; 
                    break;

                    case 2:
                        document.getElementById("fmID").innerHTML = "";
                        document.getElementById("fmName").innerHTML = "Enter Name";
                    break;

                    case 3:
                        document.getElementById("fmName").innerHTML = "";
                        document.getElementById("fmEmail").innerHTML = "Enter Email";
                    break;

                    case 4:
                        document.getElementById("fmEmail").innerHTML = "";
                        document.getElementById("fmPassword").innerHTML = "Enter Password";
                    break;

                    case 5:
                        document.getElementById("fmPassword").innerHTML = "";
                        document.getElementById("fmCnt").innerHTML = "Enter Contact"; 
                    break;

                    case 6:
                        document.getElementById("fmCnt").innerHTML = "";
                    break;
                }
                
            }
        </script>
       
        <div class="acc">
            <a href="admin_signin.php">Already Exist? SIGN IN</a>
        </div>
	</body>
</html>