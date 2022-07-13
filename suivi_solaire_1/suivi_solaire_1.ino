 const int dirPin = 2;  // Direction
const int stepPin = 3; // Step
int capteur0=A0;
int capteur1= A1; 
// Motor steps per rotation
const int STEPS_PER_REV = 200;
int valeur0;
int valeur1;

int difference;
//bool a= true;

 
void tourned250(void){
  digitalWrite(dirPin,LOW); 
  
  for(int x = 0; x < 1000; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW);   
    delayMicroseconds(1000);
     }
 }

void tourneg250(void){
      digitalWrite(dirPin,HIGH); 
  
  for(int x = 0; x < 1000 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
}

  void tourned400(void){
  digitalWrite(dirPin,LOW); 
  for(int x = 0; x < 2500; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000);
     }
 }
 
  void tourneg400(void){
      digitalWrite(dirPin,HIGH); 
  for(int x = 0; x < 2500 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
   }
  }
  
   void tourned800(void){
      digitalWrite(dirPin,LOW); 
  for(int x = 0; x < 5000 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
   }
   
     void tourneg800(void){
      digitalWrite(dirPin,HIGH); 
  for(int x = 0; x < 5000 ; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
  }
}

 void stope (void)
    {
     for(int x = 0; x < 50; x++) {
    digitalWrite(stepPin, LOW); 
    delayMicroseconds(1000); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(1000); 
      }
    }
    
void setup() {

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(capteur0,INPUT);
  pinMode(capteur1,INPUT);
  Serial.begin(115200);
}

 

void loop() {
 delay(5000);
  
  valeur0= analogRead(capteur0);
  valeur1= analogRead(capteur1);
  

  
  difference = (abs(valeur0- valeur1));
     Serial.print("valeur1=:");
     Serial.println(valeur0);
     Serial.print("valeur2=:");
     Serial.println(valeur1);
     Serial.print("la difference =");
      Serial.print(difference );
    
    if (( difference < 25 ))
    { 
     stope();
     Serial.println (" Stope ");
    }
    else if(( 25 < difference && difference < 45 )){
      if (valeur0>valeur1){
        tourned250();
        Serial.println (" tourned200 ");
        } 
      else {
       tourneg250();
        Serial.println (" tourneg200 ");
       } 
       }
  
     else if (( 45 < difference && difference < 65 )) {
      if (valeur0>valeur1){
        tourned400();
         Serial.println (" tourned400 ");
        } 
      else {
        tourneg400();
         Serial.println (" tourneg400 ");
       }
     }
       
     else if (( 65 < difference )) {
      if (valeur0>valeur1){
        tourned800();
         Serial.println (" tourned800");
        } 
      else {
        tourneg800();
         Serial.println (" tourneg800");
       }
     }
  }
