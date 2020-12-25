#include <SoftwareSerial.h>
SoftwareSerial loraSerial(2,3); // UART Rx-Tx

#include <DHT.h>
const int DHTPIN = 6;
const int DHTTYPE = DHT11;
int ledPin = 10;

DHT dht(DHTPIN, DHTTYPE);

float Tbd = 0;
float Hbd = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  loraSerial.begin(9600); 
  dht.begin();
  pinMode(A0, INPUT);
  Serial.println("lora hudimity sender: ");
}

void loop()
{
  float h = dht.readHumidity();    
  float t = dht.readTemperature();

  int mois = analogRead(A0);

  float s = (map(mois, 0, 1023, 100, 0)); // chuyen do am dat sang %

  String msg="";

  if(mois > 1023)
  {
    msg = "Not in the Soil or DISCONNECTED";
  }

  Serial.readString();      // đọc các ký tự từ bộ đệm nối tiếp vào một chuỗi ??
    String temp = String(t);
    String humi = String(h);
    String soil = String(s);
    String data = String(temp +","+ humi +","+ soil);
    Serial.println(data);   // test tren monitor cua Aduino

    // gửi thông tin đến lora gateway
      loraSerial.print(data);

      if(mois <= 1023 && mois >= 600) 
        {   
          msg= "DRY";
        }
      if(mois < 600 && mois >= 370) 
        {
          msg="HUMID"; 
        }
      if(mois < 370) 
        {  
          msg= "Very HUMID";
        }                                          
    Serial.println(msg);

    // nhan chuoi tra ve tu Ras_Pi
      if(loraSerial.available() > 0)            // kiểm tra data tới Uart mềm không, trả về số byte nhận được
        {
          String str = loraSerial.readString(); // Đọc dữ liệu chuỗi ký tự
          Serial.print("Received: ");
          Serial.println(str);
          if(str[1] == "N")
          {
            digitalWrite(ledPin,HIGH);
          }
          if(str[1] == "F")
          {
             digitalWrite(ledPin,LOW);
          }         
        }
    delay(10000);
}
//25/12/2020
////Nhiet do chenh 2°C moi gui
  // int dem = 0;
  // float Tht = t;
  // if(Tht - Tbd > 2 || Tbd - Tht > 2)
  //   {
  //     Tbd = Tht;
  //     dem++;
  //     Serial.print("Nhiet do: ");
  //     Serial.print(t);
  //     Serial.println("°C");             
  //     //Serial.print("Do am khong khi: ");
  //     //Serial.print(h);
  //     //Serial.println("%");
  //    }
  //  else
  //    {Tbd = Tht;}
     
  //  //Do am chenh nhau hon 10% moi gui
  //  if(s - Hbd >10 || Hbd - s > 10 )
  //   {
  //     Hbd = s;
  //     dem++;
  //     Serial.print("Do am dat: ");
  //     Serial.print(s);
  //     Serial.println("%");
  //    }
  //   else
  //   { Hbd = s; }

////gửi thông tin đến lora gateway nếu thỏa mãn 2 điều kiện trên
  // if(dem == 1 || dem == 2)
  //   {
  //     dem = 0;
  //     loraSerial.print(data);
  //     //delay(10000);
  //    }

    
