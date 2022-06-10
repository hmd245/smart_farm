-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Máy chủ: 127.0.0.1
-- Thời gian đã tạo: Th12 23, 2020 lúc 02:27 PM
-- Phiên bản máy phục vụ: 10.4.16-MariaDB
-- Phiên bản PHP: 7.4.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Cơ sở dữ liệu: `cambien`
--

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `thoitiet`
--

CREATE TABLE `thoitiet` (
  `id` int(32) UNSIGNED NOT NULL,
  `ngay` datetime DEFAULT NULL,
  `nhiet_do` decimal(10,2) DEFAULT NULL,
  `do_am` decimal(10,2) DEFAULT NULL,
  `do_am_dat` decimal(10,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `thoitiet`
--

INSERT INTO `thoitiet` (`id`, `ngay`, `nhiet_do`, `do_am`, `do_am_dat`) VALUES
(1, '2022-04-18 08:34:48', '26.00', '57.00', '30.00'),
(2, '2022-04-23 08:34:48', '24.00', '54.00', '70.00'),
(3, '2022-04-26 08:34:48', '27.00', '52.00', '37.00'),
(4, '2022-04-29 08:34:48', '22.00', '59.00', '82.00'),
(5, '2022-05-02 08:34:49', '23.00', '52.00', '35.00'),
(6, '2022-05-05 08:34:49', '28.00', '57.00', '65.00'),
(7, '2022-05-07 08:34:49', '21.00', '54.00', '33.00'),
(8, '2022-05-09 08:34:49', '22.00', '55.00', '80.00'),
(9, '2022-05-10 08:34:49', '29.00', '58.00', '37.00'),
(10, '2022-05-13 08:34:49', '23.00', '53.00', '74.00'),
(11, '2022-05-15 08:34:49', '27.00', '51.00', '36.00'),
(12, '2022-05-17 08:34:49', '20.00', '58.00', '80.00'),
(13, '2022-05-19 08:34:49', '26.00', '54.00', '44.00'),
(14, '2022-05-20 08:34:49', '29.00', '59.00', '87.00'),
(15, '2022-05-21 08:34:49', '24.00', '55.00', '34.00'),
(16, '2022-05-22 08:34:49', '26.00', '57.00', '68.00'),
(17, '2022-05-23 08:34:49', '28.00', '53.00', '85.00');

--
-- Chỉ mục cho các bảng đã đổ
--

--
-- Chỉ mục cho bảng `thoitiet`
--
ALTER TABLE `thoitiet`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT cho các bảng đã đổ
--

--
-- AUTO_INCREMENT cho bảng `thoitiet`
--
ALTER TABLE `thoitiet`
  MODIFY `id` int(32) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
