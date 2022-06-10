<?php
include 'db.php';
$conn = ConnectDatabase();
$arrContent = [];

$startDate = !empty($_POST["startDate"]) ? $_POST["startDate"] : '1970-01-01';
$endDate = !empty($_POST["endDate"]) ? $_POST["endDate"] : date('Y-m-d');

$sql = 'SELECT ngay, nhiet_do, do_am, do_am_dat
        FROM thoitiet 
        WHERE ngay BETWEEN "'.$startDate.'" AND "'.$endDate.'" 
        ORDER BY ngay DESC';
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $arrContent[] = $row;
    }
}
echo json_encode($arrContent);
CloseDatabase($conn);
