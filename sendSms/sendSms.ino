#include <SoftwareSerial.h>

SoftwareSerial gsmSerial(3, 2);

String phone_no = "+xxyyyzzzzzzz"; // "+923991234567"


void setup(){
  Serial.begin(9600);
  while(!Serial);
  
  gsmSerial.begin(9600);
  sendSMS("Hello from CYBR node!", phone_no);
}
void loop(){
  updateSerial();
}


void sendSMS(String sms, String ph){
  gsmSerial.println("AT");
  updateSerial();
  for (int i = 0; i < 3; i++){
    gsmSerial.println("AT+CMGF=1"); // Configuring TEXT mode
    updateSerial();
    gsmSerial.println("AT+CMGS=\"" + ph +"\"");
    updateSerial();
    gsmSerial.print(sms);
    updateSerial();
    gsmSerial.write(26);
    delay(60000);
  }
}


void updateSerial(){
  if (gsmSerial.available()){
    Serial.write(Serial.read());
  }
  if (Serial.available()){
    Serial.write(gsmSerial.read());
  }
}
