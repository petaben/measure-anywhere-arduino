#include <GSM.h>
#define PHONE_NUMBER "XXX"

const int buttonPin = 8;

GSM gsmAccess;
GSM_SMS sms;

void setup() {
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("SMS Messages Sender");
  boolean notConnected = true;
  while (notConnected) {
    if (gsmAccess.begin() == GSM_READY) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }
  Serial.println("GSM initialized");
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("pressed");
    send();
  }
  delay(1000);
}

void send(){
  sms.beginSMS(PHONE_NUMBER);
  sms.print("Hi, I'm arduino. Who are you?");
  sms.endSMS();
  Serial.println("\nsms sent!\n");
}
