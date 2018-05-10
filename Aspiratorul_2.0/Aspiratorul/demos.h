void FanDemo() {
  delay(1000);
  digitalWrite(relay4, LOW);
  delay(200);
  digitalWrite(relay4, HIGH);
  delay(200);
  digitalWrite(relay4, LOW);
  
  delay(5000);
  digitalWrite(relay4, HIGH);
  
  for (int i = 0; i < 255; i+=10) {
    analogWrite(fanPin, i);
    delay(200);
  }
  delay(10000);
  for (int i = 255; i > 0; i-=10) {
    analogWrite(fanPin, i);
    delay(200);
  }
  delay(5000);
  digitalWrite(relay4, LOW);
  delay(10000);
  
  digitalWrite(relay4, HIGH);
  delay(200);
  digitalWrite(relay4, LOW);
}
void MotorDemo() {
  delay(5000);
  MoveForward();
  delay(1000);
  MoveReverse();
  delay(1000);
  TurnLeft();
  delay(1000);
  TurnRight();
  delay(5000);
}