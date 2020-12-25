#!/usr/bin/python3
import time
import serial
from time import sleep
from datetime import date

import mysql.connector
mydb = mysql.connector.connect(
    host = "127.0.0.1",
    user = "hmdphpmyadmin",
    password = "hmd245",
    database = "sensor"
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
        s = ser.readline()			# doc du lieu
        data = s.decode()			# decode s    //?
        data = data.rstrip()		# cut "\r\n" at last of string
        if(len(data) > 10):
            print(data)					# print string co dang 

        #data = "24.00 , 55.00 , 60" => xu ly chuoi, boc tach roi gan vao tung bien de them vao CSDL
        sensor = data.split(',' , 2)

        if(len(sensor) == 3):
            temp = sensor[0]
            humi = sensor[1]
            soil = sensor[2]
            print(temp)
            print(humi)
            print(soil)

            # ep kieu string sang float
            Temp = float(temp)
            Humi = float(humi)
            Soil = float(soil)

            # Pi respond if soil > 30%
            if( Soil > 30 ):
                ser.write(b"OND1!") # Device 1
                ser.flush()         # bo dem
            else:
                ser.write(b"OFD1!")
                ser.flush()

            # Pi respond if temp >25%
            if( Temp > 25 ):
                ser.write(b"OND2!") # Divice 2
                ser.flush()
            else:
                ser.write(b"OFD2!")
                ser.flush()

            Ngay = date.today()


            #chen du lieu cam bien vao bang thoitiet
            mycursor.execute("INSERT INTO thoitiet(Ngay,NhietDo, DoAm) VALUES(%s,%s,%s)",(Ngay,Temp, Soil))
            mydb.commit()

            #Chon bang trong Mysql
            mycursor.execute("SELECT * FROM thoitiet")
            myresult = mycursor.fetchall() #phuong thuc fetchall tim nap tat ca cac hang tu cau lenh thuc thi cuoi cung
            for x in myresult:
                print(x)
            time.sleep(10)
except KeyboardInterrupt:
	ser.close()						# dong serial
#finally:
#	GPIO.cleanup()					# cleanup all port