<html>
	<head>
		<title>14</title>
	</head>
	<body>
		<?php
			$servername= "localhost:3306";
			$username = "Daniel Davidraj";
			$password = "mohanraj123";
			$dbname= "daniel davidraj";
			// Create connection
			$conn= mysqli_connect($servername, $username, $password, $dbname);
			// Check connection
			if (!$conn)
			{
				die("Connection failed: " . mysqli_connect_error());	
			}
			echo "Connected sucessfully<br><br>" ;
			$sql="SELECT * FROM `table` ORDER BY Marks ASC";			//ORDER BY Marks DESC
			$result=mysqli_query($conn,$sql);
			if (!$result)
			{
				die("Error:".$sql."<br>".mysqli_error($conn));	
			}
			if (mysqli_num_rows($result) > 0) 
			{
				// output data of each row
				while($row = mysqli_fetch_assoc($result)) 
				{
					echo "Name:".$row["Name"]."&emsp;Marks:".$row["Marks"]."<br>";
				}
			}
			else 
			{
				echo "0 results\n <br>";
			}
			echo "<br>Fetched data successfully\n";
			mysqli_close($conn);
		?>
	</body>
</html>