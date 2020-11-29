<!doctype html>
	<html>
	<head>
		<title>Student Dashboard</title>
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
                    margin-left:50%;
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
		    <div class="title">Student  Dashboard</div>
            <div class="navbar">
			    <a href="issueBook.php">IssueBook</a>
                <a href="renueBook.php">RenueBook</a>
                <a href="returnBook.php">ReturnBook</a>
                <a href="profile.php">Profile</a>
            </div>
        </div>
	</body>
</html>