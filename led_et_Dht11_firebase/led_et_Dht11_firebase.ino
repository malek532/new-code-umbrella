#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 

 
#include <WiFi.h>
#include <IOXhop_FirebaseESP32.h>
#include "DHT.h"
#define DHTPIN 14
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

String  MyIncomingData;

// Set these to run example.
#define FIREBASE_HOST "https://controle-led-e2026-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "CYEcg6emOfsHXBf2XHXrd9pWz4TvnVx0B1Hmyzzh"
#define WIFI_SSID "Molka"
#define WIFI_PASSWORD "molka0000"

void setup() {
  Serial.begin(115200);
// LCD
lcd.init();                      
  lcd.init();
  // LED
MyIncomingData = "";
 pinMode(4, OUTPUT); 
 // DHT11
  Serial.println("DHT11 test!");
  dht.begin();
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;

void loop() {
 lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Smart umbrella ");
  
 // controle led 

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
  
  //Lire les capteur de températrue 
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
  // set value
  Firebase.setFloat("/controleledavecfirebase/temperature", t);
  // erreur de manipulation
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  Firebase.setFloat("/controleledavecfirebase/humidity", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.println ("Temperature and Humidity Data Sent Successfully");
  delay(1000);
}
