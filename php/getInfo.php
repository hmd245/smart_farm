<?php
include('db.php');
$conn = ConnectDatabase();
$arrContent = [];
$info = [];
$lastInfo = [];
$sql = 'SELECT ngay, nhiet_do, do_am, do_am_dat FROM thoitiet ORDER BY ngay DESC';
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $info[] = $row;
    }
}
$sql = 'SELECT nhiet_do, do_am, do_am_dat FROM thoitiet ORDER BY ngay DESC LIMIT 1';
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
    while ($row = mysqli_fetch_assoc($result)) {
        $lastInfo = $row;
    }
}
$arrContent = [
    'info'      => $info,
    'lastInfo'  => $lastInfo
];
echo json_encode($arrContent);
CloseDatabase($conn);
