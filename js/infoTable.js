$(document).ready(function () {
    $.ajax({
        url: "../php/infoTable.php",
        type: "GET",
        dataType: "JSON",
        data: {},
    }).done(function (response) {
        let i, html, input;
        if (response.length == 0) {
            html = '<tr><td colspan="5" style="text-align:center">Không có dữ liệu</td></tr>';
            $(".infoTable").append(html);
            $(".btn-excel").attr("disabled", "disabled");
        }
        for (i = 0; i < response.length; i++) {
            html = '<tr><th scope="row">' + (parseInt(i) + 1) + '</th>' +
                '<td class="attrDate">' + response[i].ngay + '</td>' +
                '<td class="attrTemp">' + response[i].nhiet_do + '</td>' +
                '<td class="attrAir">' + response[i].do_am + '</td>' +
                '<td class="attrLand">' + response[i].do_am_dat + '</td></tr>';
            input = '<input type="hidden" name="info[]" value="' + [response[i].ngay, response[i].nhiet_do, response[i].do_am, response[i].do_am_dat] + '">';
            $(".infoTable").append(html);
            $(".exportForm").append(input);
        }
    })
})
// $(document).on("click", ".btn-excel", function (e) {
//     e.preventDefault();
//     let data = [];
//     $(".infoTable tr").each(function (a, b) {
//         let date = $(".attrDate", b).text();
//         let temp = $(".attrTemp", b).text();
//         let airHumidity = $(".attrAir", b).text();
//         let landHumidity = $(".attrLand", b).text();
//         data.push({
//             date: date,
//             temp: temp,
//             airHumidity: airHumidity,
//             landHumidity: landHumidity
//         })
//     })
//     $.ajax({
//         url: "../php/exportExcel.php",
//         type: "POST",
//         dataType: "JSON",
//         data: { info: data }
//     }).done(function (response) {
//         if (response == false) {
//             console.log(false)
//         } else {
//             console.log(response)
//         }
//     })
// })