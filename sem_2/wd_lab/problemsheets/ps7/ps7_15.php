<html>
	<head>
		<title>15</title>
		<style>
			input[type=text]
			{
				margin-left:53px;
			}
			textarea
			{
				margin-left:10px;
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
			<legend><h1>Input</h1></legend>
			<form method="post">
				URL:<input type="text" name="url"><br><br>
				Description:<textarea cols="16" rows="1" name="desc"></textarea><br><br>
				<input type="submit" value="Submit" name="submit">
		</fieldset>
		<?php
			$servername = "localhost";
			$username = "Daniel Davidraj";
			$password = "mohanraj123";
			// Create connection
			$conn = mysqli_connect($servername, $username, $password);
			// Check connection
			if (!$conn) 
			{
				die("Connection failed: " . mysqli_connect_error());
			}
			echo "Connected successfully";
			// Create database
			$sql = "CREATE DATABASE URL";
			if (mysqli_query($conn, $sql)) 
			{
				echo "Database created successfully";
			} 
			else 
			{
				echo "Error creating database: " . mysqli_error($conn);
			}
			$sql = "USE URL";
			mysqli_query($conn, $sql);
			// sql to create table
			$sql = "CREATE TABLE URLTable( URL VARCHAR(30),Description VARCHAR(50) )";
			if (mysqli_query($conn, $sql)) 
			{
				echo "Table URLTable created successfully";
			} 
			else 
			{
				echo "Error creating table: " . mysqli_error($conn);
			}
			$sql ="INSERT INTO URLTable(URL,Description) 
							   VALUES ('www.deitel.com','Cool site!');";
			$sql .="INSERT INTO URLTable(URL,Description) 
							   VALUES ('www.php.net','The official PHP')";
			if (mysqli_multi_query($conn, $sql)) 
			{
				echo "New records created successfully";
			}
			else 
			{
				echo "Error: " . $sql . "<br>" . mysqli_error($conn);
			}
			mysqli_close($conn); 
		?>
	</body>
</html>