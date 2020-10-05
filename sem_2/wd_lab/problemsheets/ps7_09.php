<html>
	<head>
		<title>9</title>
	</head>
	<body>
		<?php 
			session_start();
			$_SESSION["intVar"] = 10;
			if(!$_SESSION['intVar']) 
			{
				echo "Session variable has not been set<br>";
			}
			$_SESSION["dog"] ="A talking dog";
			if(!$_SESSION["dog"]) 
			{
				echo "Session variable has not been set<br>";
			}
			echo $_SESSION["intVar"]."<br>";
			echo $_SESSION["dog"];
			
			unset($_SESSION["intVar"]);
			unset($_SESSION["dog"]);
			session_destroy();
		?>
	</body>
</html>