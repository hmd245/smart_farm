<?php
include 'db.php';

// Create connection
$conn = ConnectDatabase();

// Create a new database
$sql = 'CREATE DATABASE IF NOT EXISTS ' . dbName .'';
if (mysqli_query($conn, $sql))
    echo "Database 'Cambien' created successfully" . PHP_EOL;
else
    echo "Error creating database: " . mysqli_error($conn) . PHP_EOL;

// Select database
$sql = 'USE ' . dbName . '';
if ( !mysqli_query($conn, $sql))
    echo "Error use database: " . mysqli_error($conn) . PHP_EOL;

// sql to create table
CreateTable($conn, "thoitiet");
CloseDatabase($conn);

?>