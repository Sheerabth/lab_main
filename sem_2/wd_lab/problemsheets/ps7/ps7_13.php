<html>
	<head>
		<title>13</title>
	</head>
	<body>
		<form method="post">
			<input type="text" name="email"><br><br>
			<input type="submit" name="submit" value="Test">
		</form>
		<?php
			if(isset($_POST["submit"]))
			{
				if(empty($_POST["email"])) 
				{
					echo "Email is required"; 
				}
				else
				{
					echo "<h3>Entered email</h3>";
					echo $_POST["email"];
					echo "<h3>Result</h3>";
					//$email=test_input($_POST["email"]);
					if(!filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)) 
					{
						echo "Invalid email format";
					}
					else
					{
						echo "Valid email format";
					}
				}
			}
		?>
	</body>
</html>