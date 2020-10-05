<html>
	<head>
		<title>10</title>
	</head>
	<body>
		<fieldset>
			<legend><h1>Shopping Cart</h1></legend>
			<form method="post">
				<select name="list">
					<option>-select-</option>
					<option>Pen</option> 
					<option>Pencil</option> 
					<option>Rubber</option> 
					<option>Paper</option> 
				</select><br><br>
				<input type="submit" name="submit" value="Save">
				<button name="clear">Clear</button>
			</form>
		</fieldset>
		<h1>List:-</h1>
		<?php
			session_start();
			if(isset ($_POST["submit"]) && $_POST["list"]!="-select-")
			{
				if(!isset($_SESSION["list"]))
				{
					$_SESSION["list"]="";
				}
				$_SESSION["list"].="<br>".$_POST["list"];
				echo $_SESSION["list"];
			}
			if(isset($_POST["clear"]))
			{
				session_destroy();
			}
			
		?>
	</body>
</html>