<?php
include('db.php');
$conn = ConnectDatabase();
$arrContent = [];
$sql = 'SELECT ngay, nhiet_do, do_am, do_am_dat FROM thoitiet ORDER BY ngay DESC LIMIT 15 ';
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $arrContent[] = $row;
    }
}
echo json_encode($arrContent);
CloseDatabase($conn);
