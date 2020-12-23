<?php 

define("serverName", "localhost");
define("userName", "hmdphpmyadmin");
define("password", "hmd245");
define("dbName", "cambien");
define("TABLE", " thoitiet "); // need space between 'device'

// Create connection to database 'Cambien'
function ConnectDatabase() {
	$conn = mysqli_connect(serverName, userName, password, dbName);
	// Check connection
	if (!$conn)
	    die("Connection failed: " . mysqli_connect_error());
	else;
		// echo "Connection database success !\n";
	return $conn;
}
// Disconnect to database
function CloseDatabase($conn) {
	mysqli_close($conn);
}

// function create a table if not exist // tao bang neu khong ton tai
// thêm một cột mới vào bảng: ALTER TABLE thoitiet ADD COLUMN do_am_dat DECIMAL(10,2);
function CreateTable($conn, $table) {
	$tableName = $table;
	$sql = "CREATE TABLE IF NOT EXISTS $tableName (
		id INT(32) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
		ngay DATETIME,
        nhiet_do DECIMAL(10,2),
        do_am DECIMAL(10,2),
		do_am_dat DECIMAL(10,2)
	)";
	if (mysqli_query($conn, $sql)) {
	    echo "Table 'thotiet' created successfully\n";
	} else {
	    echo "Error creating table: " . mysqli_error($conn);
	}
}
?>