void fan() {
  // connected to Relay 4
  pinMode(relay4, OUTPUT);
}
void fanOn() {
  digitalWrite(relay4, HIGH);
  analogWrite(fanPin, 0);
}
void fanOff() {
  digitalWrite(relay4, LOW);
  analogWrite(fanPin, 0);
}
void fanLow() {
  fanOn();
}
void fanHigh() {
  fanOn();
  Serial.println("Pornit FAN");
  analogWrite(fanPin, 255);
}

