#include <DHT.h>
#include <SoftwareSerial.h>

#define RELAY1 5
#define RELAY2 6
#define RELAY3 7
#define RELAY4 8
#define RELAY5 9
#define RELAY6 10

String arrReceive[4];
const int DHTPIN = 4;
const int DHTTYPE = DHT11;

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial loraSerial(2,3); // UART Rx-Tx

void setup()
{
  dht.begin();
  Serial.begin(9600);
  loraSerial.begin(9600); 
  pinMode(A0, INPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  pinMode(RELAY5, OUTPUT);
  pinMode(RELAY6, OUTPUT);
  Serial.println("lora hudimity sender: ");
}

void loop()
{
  int r=0, j=0;
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  int mois = analogRead(A0);

  float s = (map(mois, 0, 1023, 100, 0)); // change analog to %

  String msg="";

  // test connect sensor soil
  if(mois > 1023)
  {
    msg = "Not in the Soil or DISCONNECTED";
  }
  // status soil moisture(humi land)
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

  Serial.readString();      //  read characters from serial buffer into a string ??
    String temp = String(t);
    String humi = String(h);
    String soil = String(s);
    String data = String(temp +","+ humi +","+ soil);
    Serial.println(data);   // test data on Aduino

    // send data to lora gateway
    loraSerial.print(data);

    // receive string dataRespond from Ras_Pi
    if(loraSerial.available() > 0)                    // Check data to soft Uart ?, return byte received
      {
        String dataReceive = loraSerial.readString(); // Serial read string data
        Serial.print("Received: ");
        Serial.println(dataReceive);                  // stringRespond = "ON1,OF34,ON5,"

        for (int i=0; i < dataReceive.length(); i++)
          {
            if(dataReceive.charAt(i) == ',') 
              {
                arrReceive[j] = dataReceive.substring(r, i);
                Serial.println(arrReceive[j]);
                r=(i+1);
                j++;
              }
          }

        String tempReceive = arrReceive[0];
        String airReceive = arrReceive[1];
        String soilReceive = arrReceive[2];

        //  Temp
        if(tempReceive == "ON1")
        {
          digitalWrite(RELAY1,HIGH);
          Serial.println("congratulations1");
        }
        if(tempReceive == "ON2")
        {
          digitalWrite(RELAY2,HIGH);
          Serial.println("congratulations2");
        }
        if(tempReceive == "OF12")
        {
          digitalWrite(RELAY1,LOW);
          digitalWrite(RELAY2,LOW);
          Serial.println("congratulations3");
        }

        // Air
        if(airReceive == "ON3")
        {
          digitalWrite(RELAY3,HIGH);
          Serial.println("congratulations4");
        }
        if(airReceive == "ON4")
        {
          digitalWrite(RELAY4,HIGH);
          Serial.println("congratulations5");
        }
        if(airReceive == "OF34")
        {
          digitalWrite(RELAY3,LOW);
          digitalWrite(RELAY4,LOW);
          Serial.println("congratulations6");
        }
        // Soil
        if(soilReceive == "ON5")
        {
          digitalWrite(RELAY5,HIGH);
          Serial.println("congratulations7");
        }
        if(soilReceive == "ON6")
        {
          digitalWrite(RELAY6,HIGH);
          Serial.println("congratulations8");
        }
        if(soilReceive == "OF56")
        {
          digitalWrite(RELAY5,LOW);
          digitalWrite(RELAY6,LOW);
          Serial.println("congratulations9");
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

    
