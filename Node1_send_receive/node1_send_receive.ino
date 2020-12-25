#include <SoftwareSerial.h>
SoftwareSerial loraSerial(2,3); // UART Rx-Tx

#define RELAY 4
#include <DHT.h>
const int DHTPIN = 6;
const int DHTTYPE = DHT11;
int ledPin = 13;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  loraSerial.begin(9600); 
  dht.begin();
  pinMode(A0, INPUT);
  pinMode(RELAY, OUTPUT);
  Serial.println("lora hudimity sender: ");
}

void loop()
{
  float h = dht.readHumidity();    
  float t = dht.readTemperature();

  int mois = analogRead(A0);

  float s = (map(mois, 0, 1023, 100, 0)); // change analog to %

  String msg="";

  if(mois > 1023)
  {
    // test connect sensor soil
    msg = "Not in the Soil or DISCONNECTED";
  }

  Serial.readString();      //  read characters from serial buffer into a string ??
    String temp = String(t);
    String humi = String(h);
    String soil = String(s);
    String data = String(temp +","+ humi +","+ soil);
    Serial.println(data);   // test data on Aduino

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

    // send data to lora gateway
      loraSerial.print(data);

    // receive string from Ras_Pi
      if(loraSerial.available() > 0)            // Check data to soft Uart ?, return byte received
        {
          String str = loraSerial.readString(); // read string data 
          Serial.print("Received: ");
          Serial.println(str);
          if(str[1] == "N")
          {
            digitalWrite(ledPin,HIGH);
            // use relay turn on the led
          if(t > 25)
            {
              digitalWrite(RELAY, LOW); turn the relay ON
            }
            
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
  // float Tbd = 0;
  // float Hbd = 0;
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

  // Serial.readString();      //  đọc các ký tự từ bộ đệm nối tiếp vào một chuỗi ??
  // loraSerial.available() > 0  // kiểm tra data tới Uart mềm không, trả về số byte nhận được

    
