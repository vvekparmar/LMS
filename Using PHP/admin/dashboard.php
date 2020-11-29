<!doctype html>
	<html>
	<head>
		<title>Admin Dashboard</title>
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
                    margin-left:5%;
                }

                .navbar a:hover
                {
                    color:grey;
                    background-color:white;
                    padding:1%;
                }

                .dropdown 
                {
                    position: relative;
                    display: inline-block;
                }

                .dropdown-content 
                {
                    display: none;
                    position: absolute;
                    background-color: gray;
                    min-width: 100%;
                    padding:10%;
                    z-index: 1;
                }

                .dropdown:hover .dropdown-content 
                {
                    display: block; 
                }
            }
        </style>
	</head>
	
	<body>
        <div class="header">
		    <div class="title">Admin  Dashboard</div>
            <div class="navbar">
			    <a href="addBook.php">AddBook</a>
                <div class="dropdown">
                    <a href="#" style="margin-left:12%;">DisplayDetails</a>
                    <div class="dropdown-content">
                        <a href="displayBook.php">Book Data</a>
                        <a href="displayStudent.php">Student Data</a>
                        <a href="displayIssuer.php">Issue Data</a>
                        <a href="displayRenuer.php">Renue Data</a>
                        <a href="displayReturner.php">Return Data</a>
                    </div>
                </div>
                <a href="profile.php">Profile</a>
            </div>
        </div>
	</body>
</html>