/******************************************************
* sendSMS
* 
* This code was made public by CYBR node on January 21, 2020.
* It is free to use and is inteded for educational purposes only.
* CYBR node will not be responsible for any misuse of the code provided below.
* 
* Hardware used:
*       -Arduino Uno
*       -SIM800C 
*
* The Function:
* sendSMS("Message", "Phone Number");
*
* You can also do this:
* sendSMS("Hello from CYBR node!", "+921234567890");
*******************************************************/

#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(3, 2); // Rx, Tx
String phone_no = "add your phone number here"; // Example format "+921234567890"

void setup(){
  Serial.begin(9600);
  while(!Serial);
  gsmSerial.begin(9600);
  
  sendSMS("Hello from CYBR node!", phone_no);
}

void loop(){
  updateSerial();
}

//SendSMS function
void sendSMS(String sms, String ph){
  gsmSerial.println("AT");
  updateSerial();
  
  gsmSerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  
  gsmSerial.println("AT+CMGS=\"" + ph +"\"");
  updateSerial();
  
  gsmSerial.print(sms);
  updateSerial();
  
  gsmSerial.write(26);
  delay(60000);
}

//Sending command and Getting response from SIM800C
void updateSerial(){
  if (gsmSerial.available()){
    Serial.write(Serial.read());
  }
  
  if (Serial.available()){
    Serial.write(gsmSerial.read());
  }
}
