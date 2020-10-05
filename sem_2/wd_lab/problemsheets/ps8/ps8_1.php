<?php
	$conn = new mysqli("localhost", "root", "root", "Contacts");
	if ($conn->connect_error) 
	{
 		die("Connection failed: " . $conn->connect_error);
	} 
	//echo "PHP";
	if($_GET)
	{
		//echo "GET";
		if(isset($_GET["lname"])) //trying to retrieve the full details of a partiular last name
		{
			$lname = $_GET['lname'];
			$res = $conn->query("SELECT address, telephone FROM list WHERE lastname='$lname'");
			$table = [];
			echo json_encode($res->fetch_assoc());
		}
		if(isset($_GET['search']))
		{
			$sstr = $_GET['search'];
			$res = $conn->query("SELECT * FROM list WHERE lastname LIKE '$sstr%'");
			$table = [];
			while($row = $res->fetch_assoc())
			{
				array_push($table, $row);
			}
			echo json_encode($table);
		}
	}
	else if ($_POST) //handling POST requests
	{
		$firstname = $_POST["fname"];
		$lastname = $_POST["lname"];
		$address = $_POST["city"] . ", " . $_POST["state"] . ", " . $_POST["zip"];
		$telephone = $_POST["tel"];
		$conn->query("INSERT INTO list (firstname, lastname, address, telephone) VALUES ('$firstname', '$lastname', '$address', '$telephone')");
		echo $conn->error;
		echo "Got post";
	}
	else
	{
		$res = $conn->query("SELECT * FROM list");
		$table = [];
		while($row = $res->fetch_assoc())
		{
			array_push($table, $row);
		}
		echo json_encode($table);
	}
?>
