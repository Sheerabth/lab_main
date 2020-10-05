<html>
	<head>
		<title>16</title>
		<style>
			input[type=text],input[type=password]
			{
				margin-left:40px;
			}
			div
			{
				background: #e983ae ;
				border:solid black 1px;
				border-radius:5px;
				padding:10px;
				width:20%;
			}
		</style>
	</head>
	<body>
		<fieldset>
			<legend><h1>Log In</h1></legend>
			<form method="post">
				Username:<input type="text" name="name"><br><br>
				Password:&nbsp;<input type="password" name="password"><br><br>
				<input type="submit" value="Go" name="submit">
		</fieldset>
		<?php
			$username = "username";
			$password = "password";
			if(isset($_POST["submit"]))
			{
				if( (!empty($_POST["name"])) || (!empty($_POST["password"])) )
				{
					if($_POST["name"]==$username && $_POST["password"]==$password)
					{
						header("Location: http://www.geeksforgeeks.org"); 
					}
					else
					{
						die("<div>Invalid Username or Password</div>");
					}	
				}
			}
		?>
	</body>
</html>