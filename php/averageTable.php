<?php
include 'db.php';
$conn = ConnectDatabase();
$arrContent = [];
if(isset($_POST["startDate"]) && isset($_POST["endDate"])) {
    $startDate = $_POST["startDate"];
    $endDate = $_POST["endDate"];
}
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
