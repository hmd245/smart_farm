# farm_sensor
<!-- clone code from github -->
git init
git clone Link

<!-- push code on github -->
git add * : thêm file mới
git commit -m " nội dung commit"
git push origin main(--force)

<!--fatal: Unable to create 'D:/Electronic_IT/Đồ án/farm_sensor/.git/index.lock': File exists.-->
xóa  tệp index.lock trong .git
rm -f .git/index.lock

<!-- ip tinh -->
sudo nano /etc/dhcpcd.conf
sudo reboot

<!-- creat name DB, table -->
CREATE DATABASE cambien;
CREATE TABLE thoitiet (
    id INT(32) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
    ngay DATETIME,
    nhiet_do DECIMAL(10,2),
    do_am DECIMAL(10,2),
    do_am_dat DECIMAL(10,2)
    );

21/12/2020: Hoàn thành vẽ biểu đồ
