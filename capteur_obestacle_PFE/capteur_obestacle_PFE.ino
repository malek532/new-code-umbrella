int ir = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(ir) == HIGH) {
    Serial.println("Obstacle détecté ");
    delay(100);
  }
  if (digitalRead(ir) == LOW) {
    Serial.println("Obstacle non détecté ");
    delay(100);
  }
}
