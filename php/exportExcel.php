<?php
include '../plugins/PHPExcel-1.8/Classes/PHPExcel/IOFactory.php';
if (!isset($_POST["info"])) {
    return;
}

//Khởi tạo đối tượng
$excel = new PHPExcel();

//Chọn trang cần ghi (là số từ 0->n)
$excel->setActiveSheetIndex(0);

//Tạo tiêu đề cho trang. (có thể không cần)
$excel->getActiveSheet()->setTitle('Dữ liệu');

//Xét chiều rộng cho từng, nếu muốn set height thì dùng setRowHeight()
$excel->getActiveSheet()->getColumnDimension('A')->setWidth(30);
$excel->getActiveSheet()->getColumnDimension('B')->setWidth(30);
$excel->getActiveSheet()->getColumnDimension('C')->setWidth(30);
$excel->getActiveSheet()->getColumnDimension('D')->setWidth(30);

//Xét in đậm cho khoảng cột
$excel->getActiveSheet()->getStyle('A1:D1')->getFont()->setBold(true);

//Tạo tiêu đề cho từng cột
$excel->getActiveSheet()->setCellValue('A1', 'Ngày');
$excel->getActiveSheet()->setCellValue('B1', 'Nhiệt độ');
$excel->getActiveSheet()->setCellValue('C1', 'Độ ẩm không khí');
$excel->getActiveSheet()->setCellValue('D1', 'Độ ẩm đất');
//(&#176C)

// Thêm dữ liệu vào từng ô
$i = 2;
foreach ($_POST["info"] as $row) {
    $info = explode(",", $row);
    $excel->getActiveSheet()->setCellValue('A' . $i, $info[0]);
    $excel->getActiveSheet()->setCellValue('B' . $i, $info[1]);
    $excel->getActiveSheet()->setCellValue('C' . $i, $info[2]);
    $excel->getActiveSheet()->setCellValue('D' . $i, $info[3]);
    $i++;
}

// Đặt tên file
$fileName = "du_lieu_" . time() . '.xlsx';

//Khởi tạo đối tượng PHPExcel_IOFactory để thực hiện ghi file
header('Content-type: application/vnd.ms-excel');
header('Content-Disposition: attachment; filename="' . $fileName . '"');
PHPExcel_IOFactory::createWriter($excel, 'Excel2007')->save('php://output');
