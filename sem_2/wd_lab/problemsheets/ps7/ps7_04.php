<html>
	<head>
		<title>4</title>
		<style>
			body
			{
				text-align:center;
			}
		</style>
	</head>
	<body>
		<?php 
			function Clock()
			{
				date_default_timezone_set("Asia/Calcutta");
				$t=time();
				echo(date("d-m-Y-l",$t))."<br>";
				echo(date("H:i:s",$t))."<br>";
				echo(date("h:i:sa",$t))."<br>";
			}
		?>
		<script type="text/javascript">
			var x="<?php echo Clock(); ?>";
			document.write(x);
		</script> 
	</body>
</html>