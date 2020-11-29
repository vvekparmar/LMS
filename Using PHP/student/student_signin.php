<!doctype html>
<html>
	<head>
		<title>Student Signin</title>
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
                    margin-top:80px;
                    height:30%;
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
		<div class="header">STUDENT SIGN IN</div>

        <div class="context">
		<form action="verified.php" method="post">
            <div id="fmEmail" style="color:white; font-size:20px;"></div>
            <input type="email" onfocus="show(1)" name="email" placeholder="Email Address" required/><br><br>     
            
            <div id="fmPassword" style="color:white; font-size:20px;"></div>
            <input type="password" onfocus="show(2)" name="password" placeholder="Password" required/><br><br>
                
            <input type="submit" onfocus="show(3)" value="SIGN IN" />    
        </form>
        </div>
        
        <script type="text/javascript">
            function show(c)
            {
                switch(c)
                {
                    case 1:
                        document.getElementById("fmPassword").innerHTML = "";
                        document.getElementById("fmEmail").innerHTML = "Enter Email";
                    break;

                    case 2:
                        document.getElementById("fmEmail").innerHTML = "";
                        document.getElementById("fmPassword").innerHTML = "Enter Password";
                    break;

                    case 3:
                        document.getElementById("fmPassword").innerHTML = "";
                    break;
                }
            }
        </script>
        <div class="acc">
            <a href="student_signup.php">Create new one? SIGN UP</a>
        </div>
	</body>
</html>