int capteur=8;
int dirPin = 3;  // Direction
int stepPin = 2;
void setup() {
 
  pinMode(capteur , INPUT);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
  
}
void tourne(void){
    digitalWrite(dirPin,HIGH); 
  // Spin motor one rotation slowly
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    //while(1);
  }
}
  void stoped (void){
    digitalWrite(dirPin,HIGH); 
  // Spin motor one rotation slowly
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
  }
  
void loop() {
  delay(100);
  stoped();

  int valeur = analogRead(capteur);
  int pct=map(valeur,0,1023,0,100);
  Serial.print("valeur:");
  Serial.println(pct);
  delay(100);
  if (pct<7){
    tourne();
  }
}
