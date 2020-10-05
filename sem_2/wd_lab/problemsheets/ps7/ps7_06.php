<html>
	<head>
		<title>6</title>
	</head>
	<body>
		<h1>Enter the Text</h1>
		<form method="post">
		<input type="text" name="string"><br><br>
		<input type="submit" name="submit" value="Remove">
		</form>
		<?php 
			if(isset($_POST["submit"]))
			{
				$str=$_POST["string"];
				if(!empty($str))
				{
					echo "<h1>Entered Text</h1>";
					echo $str;
					$str=str_replace(' ','',$str);
					echo "<h1>Output</h1>";
					echo $str;
				}
			}
		?> 
	</body>
</html>