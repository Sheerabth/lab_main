<html>
	<head>
		<title>7</title>
	</head>
	<body>
		<h1>Enter the Text</h1>
		<form method="post">
		<input type="text" name="string"><br><br>
		<input type="submit" name="submit" value="Check">
		</form>
		<?php 
			if(isset ($_POST["submit"]) )
			{
				$str=$_POST["string"];
				if(!empty($str))
				{
					echo "<h1>Entered Text</h1>";
					echo $str;
					$strrev=strrev($str);
					if($str==$strrev)
					{
						echo "<h3>".$str." is a palindrome</h3>";
					}	
					else
					{
						echo "<h3>".$str." is a not palindrome</h3>";
					}	
				}
			}
		?> 
	</body>
</html>