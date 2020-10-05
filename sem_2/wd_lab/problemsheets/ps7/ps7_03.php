<html>
	<head>
		<title>3</title>
	</head>
	<body>
		<?php 
			session_start();
			if (!isset($_SESSION["intVar"]) )
			{
				$_SESSION["intVar"] = 1;
			} 
			else 
			{
				$_SESSION["intVar"]++;
			}
			echo "<p>Number of Visitors:".$_SESSION["intVar"]."</p>";
		?>
	</body>
</html>