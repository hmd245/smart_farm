# farm_sensor
<!-- clone code from github -->
Clone code from github
    git init
    git clone Link

<!-- push code on github -->
Push code on github:
    git add * : thêm file mới
    git commit -m " nội dung commit"
    git push origin main(--force)

<!--fatal: Unable to create 'D:/Electronic_IT/Đồ án/farm_sensor/.git/index.lock': File exists.-->
<!-- xóa  tệp index.lock trong .git
rm -f .git/index.lock -->

<!-- set ip tĩnh trên raspi -->
Set ip tĩnh trên raspi
    sudo nano /etc/dhcpcd.conf
    sudo reboot

<!-- creat name DB, table -->
<!-- CREATE DATABASE cambien;
CREATE TABLE thoitiet (
    id INT(32) UNSIGNED AUTO_INCREMENT PRIMARY KEY, 
    ngay DATETIME,
    nhiet_do DECIMAL(10,2),
    do_am DECIMAL(10,2),
    do_am_dat DECIMAL(10,2)
    );
 -->
 
21/12/2020: Hoàn thành vẽ biểu đồ

<!-- Cài đặt Nginx, Php, MariaDB-->
Cài đặt Nginx, Php, MariaDB

    sudo systemctl status mysql.service

    sudo mysql -uroot

    MariaDb > CREATE USE 'username'@'localhost' IDENTIFIED BY 'password'

    > grant all privileges on cambien.*to 'username'@'localhost' with grant option;

    sudo apt install php7.4-mysqli

    sudo apt install php7.4-common php7.4-cuse php7.4-intl php7.4-json php7.4-mys

    sudo systemctl restart php7.r4-fpm

    php-m

    sudo systemctl restart nginx-service

    sudo apt install php7.4-xml

<!--Truy cập Database trên terminal:-->
Truy cập Database trên terminal:
    sudo mysql -uroot
    use cambien;
    show tables;
    slelct * from thoitiet;

Chọn thư mục chứa project:
    cd/var/www/smart-farm/R tab
    
Xem địa chỉ Id: 
    hostname - I

Kết nối Uart Pi-Arduino
    Bước 1 : Disable Login Shell over Serial 
                  (PL2303, Hercules, Serial Monitor - Arduino, 115200 )
    Bước 2 : Enable Serial Port Hardware 

    * Lưu ý : Với Raspberry Pi 2 tới bước này các bạn Reboot là có thể sử dụng được UART trên Pi 2. Với Pi 3 các bạn thực hiện thêm Bước 3.

    Bước 3 : Disable Bluetooth and Stop Bluetooth Service 
    + Disable Bluetooth 
          $ sudo nano /boot/config.txt
          $ dtoverlay=pi3-disable-bt
    + Stop Bluetooth Service 
          $ sudo systemctl disable hciuart

    * Lưu ý : Nếu muốn Bluetooth hoạt động trở lại thì các bạn chỉ cần thực hiện Bước 3 này , và thay đổi disable = enable trong các câu lệnh ở Bước 3 này. 

    Bước 4 : Reboot 
    $ sudo reboot

    Bước 5 : Test giao tiếp UART với Arduino























