const int potPin=25;

void setup()
{

  pinMode(potPin,INPUT);
  
  Serial.begin(9600);
  
}

void loop()
{
int  valeur0 = analogRead(potPin);
  
  Serial.println(valeur0);
  delay (5000);
}
