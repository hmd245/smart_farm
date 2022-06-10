// $(document).ready(function () {
//     $('#quickForm').validate({
//         rules: {
//             startDate: {
//                 required: true,
//             },
//             endDate: {
//                 required: true,
//             },
//         },
//         messages: {
//             startDate: {
//                 required: "Vui lòng chọn ngày bắt đầu",
//             },
//             endDate: {
//                 required: "Vui lòng chọn ngày kết thúc",
//             },
//         },
//         errorElement: 'span',
//         errorPlacement: function (error, element) {
//             error.addClass('invalid-feedback');
//             element.closest('.form-group').append(error);
//         },
//         highlight: function (element, errorClass, validClass) {
//             $(element).addClass('is-invalid');
//         },
//         unhighlight: function (element, errorClass, validClass) {
//             $(element).removeClass('is-invalid');
//         },
//         submitHandler: function (form) {

//         }
//     });
// })
$(document).on("click", ".filterBtn", function(e) {
    e.preventDefault();
    var data = $(this).closest('form').serializeArray();
    $.ajax({
        url: "../php/averageTable.php",
        type: "POST",
        dataType: "JSON",
        data: data,
    }).done(function(response) {
        let i, html;
        let tempSum = [],
            airSum = [],
            landSum = [];
        let tempAvg, airAvg, landAvg;
        const reducer = (a, b) => a + b;
        if (response.length == 0) {
            html = '<p style="text-align:center">Không có dữ liệu cần tìm</p>';
            $(".filterTable").html(html);
            return;
        }
        html = '<div class="row">' +
            '<table class="table table-bordered">' +
            '<thead class="thead-light"><tr>' +
            '<th scope="col">STT</th>' +
            '<th scope="col">Ngày</th>' +
            '<th scope="col">Nhiệt độ</th>' +
            '<th scope="col">Độ ẩm không khí</th>' +
            '<th scope="col">Độ ẩm đất</th>' +
            '</tr></thead><tbody class="infoTable">';
        for (i = 0; i < response.length; i++) {
            tempSum.push(parseInt(response[i].nhiet_do));
            airSum.push(parseInt(response[i].do_am));
            landSum.push(parseInt(response[i].do_am));
            html += '<tr><th scope="row">' + (parseInt(i) + 1) + '</th>' +
                '<td>' + response[i].ngay + '</td>' +
                '<td>' + response[i].nhiet_do + '</td>' +
                '<td>' + response[i].do_am + '</td>' +
                '<td>' + response[i].do_am_dat + '</td></tr>';
        }
        tempAvg = parseFloat(tempSum.reduce(reducer) / tempSum.length).toFixed(2);
        airAvg = parseFloat(airSum.reduce(reducer) / airSum.length).toFixed(2);
        landAvg = parseFloat(landSum.reduce(reducer) / landSum.length).toFixed(2);

        html += '</tbody></table></div>';
        html += ' <div class="row">' +
            '<div class="infoAvg col-sm-4"><i class="fas fa-temperature-low"></i><span>NHIỆT ĐỘ TB : ' + tempAvg + '°C</span></div>' +
            '<div class="infoAvg col-sm-4"><i class="fas fa-tint"></i><span>ĐỘ ẨM KHÔNG KHÍ TB : ' + airAvg + '%</span></div>' +
            '<div class="infoAvg col-sm-4"><i class="fas fa-tint"></i><span>ĐỘ ẨM ĐẤT TB : ' + landAvg + '%</span></div>' +
            '</div>';
        $(".filterTable").html(html);
    })
})