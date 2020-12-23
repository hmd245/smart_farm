var temperature;
var airHumidity;
var landHumidity;

$(document).ready(function () {
  $.ajax({
    url: "php/getInfo.php",
    type: "GET",
    dataType: "JSON",
    data: {},
  }).done(function (response) {
    temperature = [];
    airHumidity = [];
    landHumidity = [];
    let info = response.info;
    let lastInfo = response.lastInfo;
    $(".tempInfo").html("NHIỆT ĐỘ KHÔNG KHÍ : " + lastInfo.nhiet_do + "%");
    $(".airInfo").html("ĐỘ ẨM KHÔNG KHÍ : " + lastInfo.do_am + "%");
    $(".landInfo").html("ĐỘ ẨM ĐẤT : " + lastInfo.do_am_dat + "%");
    for (let i = 0; i < info.length; i++) {
      temperature.push([info[i].ngay, Number(info[i].nhiet_do)]);
      airHumidity.push([info[i].ngay, Number(info[i].do_am)]);
      landHumidity.push([info[i].ngay, Number(info[i].do_am_dat)]);
    }
    let today = new Date();
    let date =
      today.getFullYear() +
      "-" +
      (today.getMonth() + 1) +
      "-" +
      today.getDate();
    // let time = today.getHours() + ":" + today.getMinutes();
    // let dateTime = date + ' ' + time;
    let data = [temperature, airHumidity, landHumidity];
    let $option = {
      title: "Biểu đồ nhiệt độ, độ ẩm",
      height: "500px",
      highlighter: {
        show: true,
        tooltipOffset: 9,
        sizeAdjust: 10,
      },
      legend: {
        show: true,
      },
      grid: {
        background: "#eeeeee",
      },
      axes: {
        xaxis: {
          show: true,
          renderer: $.jqplot.DateAxisRenderer,
          rendererOptions: {
            tickRenderer: $.jqplot.CanvasAxisTickRenderer,
            tickInset: 0,
          },
          tickOptions: {
            formatString: "%d-%m-%Y",
            fontSize: "8pt",
            angle: -30,
          },
          max: date,
          numberTicks: 6,
        },
        yaxis: {
          show: true,
          min: 0,
          max: 100,
          numberTicks: 6,
          tickOptions: {
            showMark: false,
            formatString: "%d",
          },
        },
        /*y2axis: {
                      show: true,
                      min: 0,
                      max: 100,
                      numberTicks: 6,
                      tickOptions: {
                          showMark: false,
                          formatString: '%d'
                      },
                  },*/
      },
      series: [
        { yaxis: "yaxis", color: "#ff0000", label: "Nhiệt độ", lineWidth:1 },
        { yaxis: "yaxis", color: "#A183DE", label: "Độ ẩm không khí", lineWidth:1 },
        { yaxis: "yaxis", color: "#1f7edd", label: "Độ ẩm đất", lineWidth:1 },
      ],
    };
    if (info.length > 0) {
      let plot = $.jqplot("chart", data, $option);
    }
  });
});
