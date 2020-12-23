<!DOCTYPE html>

<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  <title>farm_sensor</title>
  <!-- jquery -->
  <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
  <!-- Latest compiled and minified CSS -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">
  <!-- Optional theme -->
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
  <!-- Latest compiled and minified JavaScript -->
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
  <!-- font-awesome -->
  <link rel="stylesheet" href="https://pro.fontawesome.com/releases/v5.10.0/css/all.css" integrity="sha384-AYmEC3Yw5cVb3ZcuHtOA93w35dYTsvhLPVnYs9eStHfGJvOvKxVfELGroGkvsg+p" crossorigin="anonymous" />
  <!-- jquery -->
  <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
  <!-- jqplot -->
  <!-- <script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js"></script> -->
  <script type="text/javascript" src="plugins/jqplot/jquery.jqplot.js"></script>
  <script type="text/javascript" src="plugins/jqplot/plugins/jqplot.dateAxisRenderer.js"></script>
  <script type="text/javascript" src="plugins/jqplot/plugins/jqplot.canvasTextRenderer.js"></script>
  <script type="text/javascript" src="plugins/jqplot/plugins/jqplot.canvasAxisTickRenderer.js"></script>
  <link rel="stylesheet" type="text/css" href="plugins/jqplot/jquery.jqplot.css" />
  <script type="text/javascript" src="plugins/jqplot/plugins/jqplot.highlighter.js"></script>
  <!-- css -->
  <link rel="stylesheet" href="css/styles.css">
  <!-- js -->
  <script src="js/index.js"></script>
</head>
<html lang="en">

<body>
  <header>
    <div class="container">
      <img class="header-icon" src="img/icon_farm.png" alt="icon_farm">
      <h2>Hệ Thống Cảm Biến Giám Sát - Điều Khiển Thiết Bị Trong Nông Nghiệp</h2>
      <div class="clear-fix"></div>
    </div>
  </header>
  <section>
    <div class="container">
      <div class="nav-item">
        <a href="index.php" class="nav-depart active"><i class="fas fa-home"></i></a>
        <ul class="nav-menu">
          <li><a href="html/infoTable.html" class="tableTab">Bảng</a></li>
          <li><a href="html/averageTable.html" class="avgTab">Giá trị trung bình</a></li>
          <li><a href="html/controllTable.html" class="controllTab">Điều khiển</a></li>
        </ul>
      </div>
      <div class="content">
        <h2>Thông tin cảm biến</h2>
        <div class="row">
          <div class="info col-sm-4"><i class="fas fa-temperature-low"></i><span>NHIỆT ĐỘ KHÔNG KHÍ : 25°C</span></div>
          <div class="info col-sm-4"><i class="fas fa-tint"></i><span>ĐỘ ẨM KHÔNG KHÍ : 55%</span></div>
          <div class="info col-sm-4"><i class="fas fa-tint"></i><span>ĐỘ ẨM ĐẤT : 30%</span></div>
        </div>
        <div id="chart"></div>
      </div>
    </div>
  </section>
</body>

</html>