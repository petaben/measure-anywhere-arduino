#include <GSM.h>

// APN data
#define GPRS_APN       "uk.lebara.mobi"
#define GPRS_LOGIN     "wap"
#define GPRS_PASSWORD  "wap"

GSMClient client;
GPRS gprs;
GSM gsmAccess(true);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Starting Arduino web client.");
  boolean notConnected = true;

  while (notConnected) {
    if ((gsmAccess.begin() == GSM_READY) &
        (gprs.attachGPRS(GPRS_APN, GPRS_LOGIN, GPRS_PASSWORD) == GPRS_READY)) {
      notConnected = false;
    } else {
      Serial.println("Not connected");
      delay(1000);
    }
  }

  String content = "{\"api_key\":\"XXX\", \"field1\":100}";
  String lengthText = "Content-Length: ";
  Serial.println("connecting...");

  if (client.connect("api.thingspeak.com", 80)) {
    Serial.println("connected");
    client.println("POST /update.json HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Content-Type: application/json");
    client.println(lengthText += content.length());
    client.println("");
    client.print(content);
  } else {
    Serial.println("connection failed");
  }
}

void loop() {
  //output response from server if available
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
}

