<!doctype html>
	<html>
	<head>
		<title>LMS</title>
		<style>
            body
            {
                background-image:url('image.png');
            }

            @media only screen and (min-width:200px)
            {
                .flex_form
                {
                    display:flex;
                    flex-direction:column;
                }

                .header
                {
                    background-color:grey;
                    margin:-15px;
                    height:23%;
                    text-align:center;
                    font-size:30px;
                    opacity:0.8;
                }

                .title
                {
                    float:left;
                    margin-left:3%;
                    font-size:100%;
                    color:white;
                    padding:1%;

                }

                .navbar
                {
                    padding-top:4%;
                    margin-left:40%;
                }

                .navbar a
                {
                    font-size:90%;
                    text-decoration:none;
                    color:white;
                    margin-left:1.5%;
                }

                .navbar a:hover
                {
                    color:grey;
                    background-color:white;
                    padding:0.5%;
                    border-radius:10%;
                }
                
            }
        </style>
	</head>
	
	<body>
        <div class="header">
		    <div class="title">Library Management System</div>
            <div class="navbar">
			    <a href="db.php">Dashboard</a>
                <a href="aboutSystem.php">About-System</a>
                <a href="admin/admin_signin.php">Admin_SIGN-IN</a>
                <a href="student/student_signin.php">Student_SIGN-IN</a>
            </div>
        </div>
	</body>
</html>