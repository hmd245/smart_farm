#!/usr/bin/python3
import time
import serial
from time import sleep
from datetime import datetime

import mysql.connector
mydb = mysql.connector.connect(
    host = "127.0.0.1",
    user = "hmdphpmyadmin",
    password = "hmd245",
    database = "cambien"
)
mycursor = mydb.cursor()

ser = serial.Serial(				# Thiet lap serial
	port = '/dev/ttyAMA0',
	baudrate = 9600,
	parity = serial.PARITY_NONE,
	stopbits = serial.STOPBITS_ONE,
	bytesize = serial.EIGHTBITS,
	timeout = 1
)

print("Raspberry's receiving : ")

try:
    while True:
        # Pi receive data
        s = ser.readline()			# doc du lieu
        data = s.decode()			# decode s    //?
        data = data.rstrip()		# cut "\r\n" at last of string
        if(len(data) > 10):
            print(data)				# print data = "24.00 , 55.00 , 60" => xu ly chuoi, boc tach roi gan vao tung bien de them vao CSDL

        sensor = data.split(',' , 2)

        if(len(sensor) == 3):
            temp = sensor[0]
            air = sensor[1]
            soil = sensor[2]
            # print(type(temp))
            # print(temp)
            # print(air)
            # print(soil)

            # ep kieu string sang float
            Temp = float(temp)
            Air = float(air)
            Soil = float(soil)

            # Pi Respond:
            #Temp:
            if (Temp > 30 ):
                tempRespond = "ON1"
            elif(Temp < 15 ):
                tempRespond = "ON2"
            else:
                tempRespond = "OF12"
            # print(tempRespond)

            #Air:
            if( Air > 80 ):
                airRespond = "ON3"
            elif( Air < 50 ):
                airRespond = "ON4"
            else:
                airRespond = "OF34"

            #Soil:
            if( Soil > 80 ):
                soilRespond = "ON5"
            elif( Soil < 60 ):
                soilRespond = "ON6"
            else:
                soilRespond = "OF56"

            add = ","

            #stringRespond = (tempRespond +","+ airRespond +","+ soilRespond +","+ ) # stringRespond = "ON1,OF34,ON5,"
            stringRespond = ''.join([tempRespond , add , airRespond , add , soilRespond , add])
            ser.write(stringRespond)
            ser.flush() # xoa sach hoac chuyen ra ngoai bo dem (buffer)

            Ngay = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            # print(Ngay)

            #chen du lieu cam bien vao bang thoitiet
            mycursor.execute("INSERT INTO thoitiet(ngay,nhiet_do,do_am, do_am_dat) VALUES(%s,%s,%s,%s)",(Ngay,Temp,Air,Soil))
            mydb.commit()

            #Chon bang trong Mysql
            mycursor.execute("SELECT * FROM thoitiet")
            myresult = mycursor.fetchall() #phuong thuc fetchall tim nap tat ca cac hang tu cau lenh thuc thi cuoi cung
            for x in myresult:
                print(x)
            # time.sleep(10)
except KeyboardInterrupt:
	ser.close()						# dong serial
#finally:
#	GPIO.cleanup()					# cleanup all port