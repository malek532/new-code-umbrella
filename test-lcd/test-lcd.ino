#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  
void setup() {
Serial.begin (115200);
  lcd.init();                      
  lcd.init();
}

void loop() { 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Smart umbrella ");
  
}
