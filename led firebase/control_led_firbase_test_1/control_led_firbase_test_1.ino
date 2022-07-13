/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

#include <IOXhop_FirebaseESP32.h>
String  MyIncomingData;
#define FIREBASE_HOST "https://controle-led-e2026-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "CYEcg6emOfsHXBf2XHXrd9pWz4TvnVx0B1Hmyzzh"


void setup()
{
MyIncomingData = "";

Serial.begin(115200);

pinMode(4, OUTPUT);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("Molka","molka0000");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}


void loop()
{

    if (Firebase.getString( "/controleledavecfirebase/ControlString")) {
      MyIncomingData = (Firebase.getString( "/controleledavecfirebase/ControlString"));
      if (MyIncomingData == "1") {
        digitalWrite(4 ,HIGH);
        Serial.println("ON");

      }
      if (MyIncomingData == "0") {
        digitalWrite(4 ,LOW);
        Serial.println("OFF");

      }

    }


}
