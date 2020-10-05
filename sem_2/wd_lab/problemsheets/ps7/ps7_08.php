<html>
	<head>
		<title>8</title>
	</head>
	<body>
		<?php 
			$age=array("Sophia"=>"31","Jacob"=>"41","William"=>"39","Ramesh"=>"40");
			echo "<h1>Original Array</h1>";
			foreach($age as $x => $x_value) 
			{
				echo "Key=".$x.", Value=".$x_value;
				echo "<br>";
			}
			echo "<h1>Ascending order sort by value</h1>";
			asort($age);
			foreach($age as $x => $x_value) 
			{
				echo "Key=".$x.", Value=".$x_value;
				echo "<br>";
			}
			echo "<h1>Ascending order sort by key</h1>";
			ksort($age);
			foreach($age as $x => $x_value) 
			{
				echo "Key=" . $x . ", Value=" . $x_value;
				echo "<br>";
			}
			echo "<h1>Descending order sort by value</h1>";
			arsort($age);
			foreach($age as $x => $x_value) 
			{
				echo "Key=" . $x . ", Value=" . $x_value;
				echo "<br>";
			}
			echo "<h1>Descending order sort by value</h1>";
			krsort($age);
			foreach($age as $x => $x_value) 
			{
				echo "Key=" . $x . ", Value=" . $x_value;
				echo "<br>";
			}
		?> 
	</body>
</html>