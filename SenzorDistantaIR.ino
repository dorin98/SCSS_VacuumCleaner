#define sharpSensor 2

float x, cmDist;

void setup() {
  Serial.begin(9600);
}

void getDistance() {
  x = analogRead(sharpSensor);
  // Alege una dintre formulele de mai jos
    cmDist = 4828 / (x + 5) - 1;
    cmDist = 4800 / (x - 20);
  //
  Serial.println(cmDist);
  delay(2000);
}
