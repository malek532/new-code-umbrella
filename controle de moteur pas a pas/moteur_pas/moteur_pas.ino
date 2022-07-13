


const int dirPin = 4;  // Direction
const int stepPin = 2; // Step

 
void setup() {
  

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
void loop() {
  

  digitalWrite(dirPin,LOW); 
  

  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
// delay(50000);
  
 /* digitalWrite(dirPin,HIGH);
    for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }  
delay (5000); */
}
