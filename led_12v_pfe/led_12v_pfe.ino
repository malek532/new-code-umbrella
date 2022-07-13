int led =  4;
void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  pinMode (led , OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite( led , HIGH);
delay (5000);
Serial.println("on");
digitalWrite( led , LOW);
delay (10000 );
Serial.println("off");
}
